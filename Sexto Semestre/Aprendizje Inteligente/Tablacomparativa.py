import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score, f1_score
import seaborn as sns
import matplotlib.pyplot as plt

# Cargar el conjunto de datos de Titanic
# Asegúrate de ajustar la ruta del archivo según corresponda
titanic = pd.read_csv("titanicV2020.csv")

# Preprocesamiento de datos (aquí se asume que ya tienes las columnas relevantes y etiquetas)
# Por ejemplo, seleccionar solo las columnas numéricas y la columna de sobrevivencia
# y realizar cualquier preprocesamiento necesario (codificación, normalización, etc.)

# Dividir el conjunto de datos en características (X) y etiquetas (y)
X = titanic.drop('Survived', axis=1)
y = titanic['Survived']

# Dividir el conjunto de datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Definir los clasificadores
classifiers = {
    'Naive Bayes': GaussianNB(),
    'SVM': SVC(probability=True),
    'KNN (NNBP)': KNeighborsClassifier(n_neighbors=3) # Ajusta el número de vecinos según sea necesario
}

# Función para calcular métricas
def calculate_metrics(y_true, y_pred):
    tn, fp, fn, tp = confusion_matrix(y_true, y_pred).ravel()
    precision_positive = tp / (tp + fp)
    precision_negative = tn / (tn + fn)
    recall_positive = tp / (tp + fn)
    recall_negative = tn / (tn + fp)
    f1_positive = 2 * (precision_positive * recall_positive) / (precision_positive + recall_positive)
    f1_negative = 2 * (precision_negative * recall_negative) / (precision_negative + recall_negative)
    return {
        'accuracy': accuracy_score(y_true, y_pred),
        'precision_positive': precision_positive,
        'precision_negative': precision_negative,
        'recall_positive': recall_positive,
        'recall_negative': recall_negative,
        'f1_positive': f1_positive,
        'f1_negative': f1_negative,
    }

# Aplicar cada clasificador y calcular métricas
results = {}
for name, classifier in classifiers.items():
    classifier.fit(X_train, y_train)
    y_pred = classifier.predict(X_test)
    metrics = calculate_metrics(y_test, y_pred)
   
