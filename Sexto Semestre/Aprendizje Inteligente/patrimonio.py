import requests
import pandas as pd
from bs4 import BeautifulSoup
import re


# URL de la página web
url = "https://en.wikipedia.org/wiki/List_of_World_Heritage_in_Danger"

# Realizar una solicitud GET para obtener el contenido de la página
response = requests.get(url)

# Verificar que la solicitud se realizó con éxito
if response.status_code == 200:
    # Parsear el contenido HTML
    soup = BeautifulSoup(response.content, 'html.parser')
    
    # Encontrar todas las tablas en la página
    tables = soup.find_all('table', class_='wikitable')
    
    # Convertir la primera tabla en un DataFrame de pandas
    # Convertir la primera tabla en un DataFrame de pandas
import io

# Convertir la primera tabla en un DataFrame de pandas
if tables:
    tablasitios = pd.read_html(io.StringIO(str(tables[0])))[0]
    
    # Seleccionar columnas específicas por índice
    tablasitios = tablasitios.iloc[:, [0, 2, 3, 5, 6]]
    
    # Renombrar las columnas
   # Renombrar las columnas
    tablasitios.columns = ['Nombre', 'Lcon', 'Criteria', 'YearEntry', 'yearEndangered']

# Imprimir el DataFrame resultante
   # print(tablasitios)
    # Definir criterios basados en el contenido de la columna 'crit' y asignarlos a la columna 'criteria'
    tablasitios['Criteria'] = tablasitios['Criteria'].apply(lambda x: 'nat' if re.search(r'Natural', str(x)) else 'cult')

    # Imprimir los primeros 3 elementos de la columna 'criteria'
   # print(tablasitios['Criteria'].iloc[:3])


    # Convertir la columna de años a numérico
    tablasitios['YearEntry'] = pd.to_numeric(tablasitios['YearEntry'], errors='coerce')

    # Imprimir los primeros 3 elementos de la columna 'year'
    #print(tablasitios['YearEntry'].iloc[:3])

    

  

# Limpiar la columna de años declarados en peligro y ponerlos en la columna 'yearEndangered'
    tablasitios['yearEndangered'] = tablasitios['yearEndangered']


    ##print(tablasitios.head())

    # Crear una copia del DataFrame
    tablasitios_acp = tablasitios.copy()

    # Definir la expresión regular y extraer el país de la columna 'lcon'
    reg = "[A-Za-z ]+(?=\\d)"
    tablasitios['Lcon'] = tablasitios['Lcon'].apply(lambda x: re.search(reg, str(x)).group(0) if re.search(reg, str(x)) else None)
    tablasitios.loc[0, 'Lcon'] = "Egypt"
    tablasitios.loc[11, 'Lcon'] = "Potosi"
    tablasitios.loc[22, 'Lcon'] = "Ukraine"
    tablasitios.loc[23, 'Lcon'] = "Ukraine"
    tablasitios.loc[34, 'Lcon'] = "Côte d'Ivoire / Guinea"
    tablasitios.loc[49, 'Lcon'] = "Tanzania"

    # Expresión Regular para Coordenada 'Y'
    reg_y = r"([-/]?)\s*(\d+(\.\d+)?)"
    # Expresión Regular para Coordenada 'X'
    reg_x = r"(;)\s*(\d+(\.\d+)?)"

    # Extraer y convertir coordenadas 'y' a numérico, manejando errores
    tablasitios['coordenadas_y'] = pd.to_numeric(tablasitios_acp['Lcon'].str.extract(reg_y, expand=False)[0], errors='coerce').astype(float)

    # Extraer y convertir coordenadas 'x' a numérico, manejando errores
    tablasitios['coordenadas_x'] = pd.to_numeric(tablasitios_acp['Lcon'].str.extract(reg_x, expand=False)[0], errors='coerce').astype(float)

    # Verificar si hubo algún error en la extracción y manejarlo
    nan_count = tablasitios.isnull().sum()
    if nan_count > 0:
        print(f"Hubo {nan_count} valores NaN después de la extracción.")
    else:
        print("Extracción exitosa sin valores NaN.")

    # Mostrar los primeros registros para verificar los resultados
    print(tablasitios[['coordenadas_x', 'coordenadas_y']].head())

    # Imprimir las primeras coordenadas 'x' y 'y' redondeadas
    print("Coordenadas 'y':")
    print(tablasitios['coordenadas_y'].round(2).head())
    print("\nCoordenadas 'x':")
    print(tablasitios['coordenadas_x'].round(2).head())

    # Imprimir las dimensiones del DataFrame
    print("\nDimensiones del DataFrame:")
    print(tablasitios.shape)

    # Imprimir las primeras filas del DataFrame utilizando pander
    
  # Mostrar las primeras filas del DataFrame
    print(pd.DataFrame(tablasitios.head()))

else:
    print("Error al acceder a la página:", response.status_code)
