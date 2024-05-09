//TEORIA 
/*
GRAFO BIPARTITO
Un grafo G = (N, A) es bipartito si existe una particion del conjunto
de nodos, es decir si N = N1 U N2, con N1 n N2 = �, de manera que
los arcos existentes solo conectan nodos de N1 con nodos de N2: es decir,
{u, v} E A implica que u E N1, v E N2 o v E N1, u E N2. De manera
equivalente, si {u, v} E A, u E N1 <-> v E N2.
-Los dos conjuntos U y N pueden ser definidos como un coloreo del grafo con dos
colores
P r o p i e d a d e s
1. Todo grafo sin ciclos con cantidad de nodos impar es bipartito
Como consecuencia de esto: Todo �arbol es bipartito
� Los grafos c�iclicos con un n�umero par de nodos son bipartitos.
� Todo grafo planar donde todas las caras tienen un n�umero par de arcos
es bipartito

GRAFO BIPARTITO COMPLETO
Un grafo bipartito completo G = (N1 U N2, A) es un grafo bipartito tal
//que Angulov1 E N1, Angulov2 E N2 -> a(v1, v2) E A. Es decir, un grafo bipartito
completo est�a formado por dos conjuntos disjuntos de nodos y todas los
arcos que unen esos nodos El grafo completo bipartito con particiones de
tamano |N1| = m y |N2| = n, es denotado como Km,n.
P r o p i e d a d e s
Sea Km,n un grafo bipartito con |N1| = m y |N2| = n, se verifica:
|A| = |N1||N2| = mn
Km,n posee m^n-1 n^m-1 arboles de expansion

HIPERGRAFO
Sea G(N1, N2, A) un grafo bipartito, es posible construir un hipergrafo derivado de este Hyp(G) = (N1, F).
Se debe se�nalar que la nocion de hipergrafo amplia la nocion de grafo al permitir que los bordes del hipergrafo conecten cualquier 
numero de nodos mediante los llamados
hiperarcos.
F = ({v E N2|{u, v} E A)uEN1
e j e m p l o
un conjunto de grupos de personas en un sitio de redes sociales
pueden ser modeladas como un hipergrafo, en el que las personas son los nodos, y
cada grupo crea una hiperarco que esta formada por todas las personas que figuran
en ese grupo.
El grafo bipartito equivalente tiene personas y grupos como nodos, y un arco de
una persona a un grupo cuando la persona es miembro de ese grupo.
Debido a la simetr�ia entre N1 y N2, se puede construir una representacion hipergrafica analoga 
Hyp(G) = (N2, F) en la que F contiene una hiperarco para
cada nodo en N1.

MODELO DE ESPACIO VECTORIAL
forma alternativa de modelar un grafo bipartito
Este enfoque es muy com �un en la mineria de textos1
, donde los
documentos que contienen palabras se modelan como vectores de palabras.
Sea G = (N1, N2, A) una red de palabras de un documento bipartito, donde N1
son los documentos y N2 son las palabras. El modelo de espacio vectorial representa cada 
documento u E N1 como un vector.
En el area de recuperacion de informacion normalmente se usa una expresion vectorial, 
donde las dimensiones del vector representan t�erminos, frases o conceptos
que aparecen en el documento.
En este aspecto la representacion mas adoptada es la conocida como bolsa de
palabras: una colecci on de documentos compuesta por n documentos indexados y
m^2
terminos representados por una matriz documento-termino de n � m.
Donde los n vectores renglon representan los n documentos; y el valor asignado
a cada componente refleja la importancia o frecuencia ponderada que produce el
termino, frase o concepto ti en la representacion semantica del documento j.
En esta representacion, ciertas medidas surgen naturalmente, como la similitud
del coseno.

PROYECION A UN GRAFO UNIPARTITO
representacion alternativa comun de un grafo bipartito
En la proyeccion de un grafo sobre los nodos de la izquierda, solo se mantienen los
nodos de la izquierda y los nodos que estan conectados cuando tienen un vecino
comun en el grafico bipartito original.
La proyeccion en los nodos de la derecha se define de manera analoga.
Sea G = (N1, N2, A) un grafo bipartito, sus proyecciones hacia el lado izquierdo
y derecho pueden definirse como los grafos.
Las proyecciones definidas de esta manera se utilizan comunmente cuando se aplican 
metodos de an�alisis de un grafo unipartito a grafos bipartitos.
Entre muchos ejemplos, esta el caso de los tipos de borde que representan una
colaboracion, cuyo nombre suele comenzar con co-, por ejemplo, la red de coautoria de 
cientificos o la red de actores co-protagonistas.
Sin embargo, las redes de proyecci �on no rechazan completamente las propiedades
de los grafos bipartitos originales.
Por ejemplo, las distribuciones de grados izquierdo y derecho en el grafico bipartito 
original se combinaran. Sin embargo, las distribuciones de grado de izquierda
y derecha de las redes bipartitas son a menudo muy diferentes, y esto se pierde en
la proyeccion.
Los grafos bipartitos, sin embargo, son mas faciles de estudiar convirti�endolos en
unipartitos o grafos modo-uno: para ello simplemente se proyectan, eliminando
los nodos de uno de los dos tipos, y sustituy�endolos por la relaci �on estar conectados al 
mismo nodo: dos nodo estar�an enlazados si, y solo si, est�an enlazados al
mismo nodo en el grafo bipartito.

PROBLEMA DE ASIGNACION DE TAREAS
Dada una serie de trabajos (tareas) pendientes por realizar y otra de recursos (candidatos) 
para uno o mas de dichos trabajos,
�Bajo que condiciones existe una asignacion ?
�Qu�e asignacion de candidatos a tareas permite minimizar los costos totales?
El modelo de asignacion es un caso especial del modelo de transporte, en el que
los recursos se asignan a las actividades en terminos de uno a uno, haciendo notar
que la matriz correspondiente debe ser cuadrada. Asi entonces cada recurso debe
asignarse, de modo unico a una actividad particular o asignacion.
Se tiene un costo Cij asociado con el recurso i que es asignado a la tarea j, de
modo que el objetivo es determinar en que forma deben realizarse todas las asignaciones
para minimizar el costo total.
El problema de asignacion puede transformarse en un problema de transporte al
considerar a los trabajadores como origenes y a las tareas como destinos con todos
los suministros y demandas igual a uno.

REPRESENTACION MEDIANTE GRAFOS
El problema de la asignacion de tareas tambien puede expresarse en terminos de
Teoria de Grafos como: �Bajo que condiciones un grafo bipartito G dado posee
un subgrafo 1-regular que incluya a todos los nodos de uno de los subconjuntos
partitos, el que representa a los candidatos (o bien a los trabajos)? 
�Cual es el tamano maximo de un subgrafo 1-regular de un grafo bipartito?

MODELADO DEL PROBLEMA
En un grafo G bipartito ponderado, si el candidato (R) se le asigna al recurso 
tarea(T), entonces el peso de la arco RT, w(CT)
, en G es una medida del beneficio que
se obtiene asignando al candidato R para emplear el recurso T.
El problema de encontrar una asignacion de candidatos a trabajos vacantes que
produzca un beneficio maximo es equivalente a encontrar un subgrafo 1-regular
H de G tal que la suma de los pesos de los arcos de H sea maximo.

Un emparejamiento en G = (SUT, A) es un conjunto E de arcos tales que ning�un
par de ellas tiene un nodo en com �un.
Si el emparejamiento es del mayor n�umero posible de arcos se denomina emparejamiento
maximo o de cardinal m�aximo.
Un nodo se dice expuesto (o no cubierto) por un emparejamiento E si no es punto
extremo de ninguna arco de E.
Ser emparejamiento maximo no significa que todos los nodos esten emparejados
con otro, sino que estan emparejados los maximos posibles.
Por ejemplo,si S tiene 5 nodos y T tiene 7, a lo mas puede obtenerse un emparejamiento 
de tamano 5, pero tambien es posible que no puedan emparejarse los 5
nodos:
Un emparejamiento como el de G2(fig.3.15), que no deja ningun borde expuesto,
de dice que es un emparejamiento completo (evidentemente, un emparejamiento
completo es maximo y solo puede darse si los dos conjuntos tienen el mismo
n�umero de nodos).
Los nodos x1 y x8 no estan cubiertos por el emparejamiento dado en G1 (fig.3.14),
es decir, son expuestos.
La manera de proceder para obtener un emparejamiento maximo, es ir incrementando paso 
a paso el cardinal del emparejamiento hasta hacerlo maximo. Para esta
idea es fundamental el concepto de camino aumentador.

ALGORITMO DE EMPAREJAMIENTO
Sea G = (S U T, A) un grafo bipartito de n nodos y E un emparejamiento en G
(puede ser inicialmente E = � ).
Denotemos los nodos por 1, 2, ..., n.
1. Si en S no hay ningun borde expuesto, E es maximo.
En caso contrario, etiquetar cada nodo expuesto de S por 0.
2. Para cada nodo j E S y arco j, k E/ E, etiquetar el nodo k con j, a menos
que ya este etiquetado.
3. Para cada nodo k E T cubierto por E, etiquetar al nodo j por k, donde j es
el nodo de S extremo de la unica arco {j, k} E E.
4. Recorrer hacia atras los caminos alternantes que acaban en un nodo expuesto en T, 
usando las etiquetas sobre los nodos.
5. Si en el paso anterior, ninguno de los caminos alternantes es de aumento,
entonces E es maximo.
En caso contrario, aumentar E usando un camino aumentador y eliminar todas las etiquetas 
y volver al Paso 1.

M O D E L A N D O  p r o b l e m a s reales con grafos bipartitos

ARRIBOS de AVIONES
Por razones obvias de seguridad, las autoridades aeroportuarias deben garantizar
que el n�umero de aviones de aterrizaje en un intervalo de tiempo determinado sea
inferior a la capacidad del aeropuerto.
Por lo tanto, los aeropuertos tienen intervalos de tiempo (franjas horarias) que se
asignan inicialmente a las aeronaves segun su programa de llegadas.

Una aeronave solo puede asignarse a una pista que sea compatible con su hora de
llegada.
Sin embargo, si se retrasa un vuelo, los controladores de operacion de la l�inea
aerea deben asignar una nueva pista a traves del sistema de informacion que administra 
estos intercambios.
Las estrictas regulaciones que deben respetar estos sistema hacen que solo sean
posibles dos operaciones.
Se asigna una pista disponible a la aeronave A (Regla 1), o una pista S que ya
esta asignada a otra aeronave B se reasigna a A mientras que a B se le asigna una
pista disponible S0 (Regla 2).
En ambos casos, la pista S debe ser compatible con el programa de A y en el
segundo caso, S y S0 deben ser compatibles con la de B.
Si varios aeroplanos se atrasan y pierden sus pistas, la resolucion de estos problemas 
es dificil.
Ya que los controladores aereos no tienen las herramientas de sistema para realizar
estos cambios y deben garantizar a mano que todas las aeronaves obtendr�an un
espacio.
Cada avion esta vinculado a las pistas que son compatibles con el. Inicialmente,
los Slots 1,2,4 y 6 se asignan a los aviones A, C, B y D, respectivamente.

Por lo tanto, la configuraci �on se convierte en la que se muestra en la Fig.3.18(a).
Desde la Configuracion (a), si la pista 2 se reasigna a A y la pista 3 se asigna a C
(es decir, la Regla 2 se aplica a A y C), entonces llegamos a Conf.(b) donde no es
posible ninguna modificaci �on permitida (no hay Regla puede ser aplicado).

Otra solucion seria aplicar la Regla 2 a A y B (A obtiene la pista 4 y B obtiene
la pista 3), alcanzando Conf. (c), y luego aplicar la Regla 2 a C y D (C obtiene la
pista 5 y D obtiene la pista 2), llegando a la Conf. (d) donde a todas las aeronaves
se les asigna un espacio.

PAREO DE GRAFOS
El problema de la reasignacion de pistas puede, por supuesto, ser modelado como
un problema de emparejamiento de grafos.
Un pareo M que coincide con E de un grafico G = (N, E) es un conjunto de
bordes separados por pares.

El tamano maximo de una coincidencia en G se denota por �(G). El problema de
calcular una coincidencia maxima ha sido ampliamente estudiado y es bien sabido
que puede resolverse en tiempo polinomial.
Un ingrediente clave en la mayoria de los trabajos sobre emparejamientos es la
nocion de camino aumentador.

Una ruta P = (v0, ..., vk) de G es una secuencia de nodos distintos de pares de
manera que ei = {vi, vi + 1} E E para cada 0 = i < k.
La ruta P se dice aumento de M si v0 y vk estan expuestos (no inciden en un borde
de M) y, para cualquier 0 = i < k, ei E M si y solo si i es impar.
Cuando se pasa de una M coincidente a la MtrianguloE(P) coincidente, se dice que la
ruta P de aumento de M esta aumentada.
Algunos algoritmos que calculan las coincidencias maximas en gr�aficos se basan
en aumentar dichas rutas en el orden no decreciente de sus longitudes.

El problema de la reasignacion de pistas descrito anteriormente se puede modelar
de la siguiente manera:
Sea G = (X U Y, E) un grafo bipartito.
X representa el conjunto de aviones y Y representa el conjunto de pistas.
Hay un arco entre a E X y s E Y si la pista s es compatible con el horario de la
aeronave A.
Sea M una coincidencia de G que corresponda a una asignacion v�alida preestablecida de 
algunas pistas a algunas aeronaves.
El problema de la reasignacion de pistas es equivalente a calcular una coincidencia
maxima que se puede obtener de M aumentando s�olo las rutas de longitud a lo
sumo 3.
Por ejemplo, el primer escenario en el ejemplo anterior consiste en aumentar la
ruta (A2C3). Al llegar a Conf. (b), no hay rutas de aumento de longitud a lo sumo
3. El segundo escenario consiste en aumentar primero la ruta (A4B3) (llegando a
Conf. (c)) y luego a la ruta (D2C5) para llegar a Conf. (d).
Este ejemplo ya sugiere que delimitar la longitud de las rutas aumentadas puede
aumentar la dificultad del Problema de coincidencia m�axima, ya que el orden en
que se aumentan las rutas se vuelve importante.

Cuando k >= 3, la dificultad surge del hecho de que el orden en que se aumentan
los caminos es importante.
Este hecho se ilustra en la Fig.3.18, donde aumentar primero la trayectoria (A2C3)
conduce a una configuracion de punto muerto no optima.
Ademas, el orden en que se aumentan las rutas tiene un impacto en la creaci �on o
no creacion de nuevas rutas de aumento de longitud como maximo k.

Por ejemplo, para k = 5, consideremos el grafo de la Fig.3.19 que consta de una
ruta (v1, ..., v7) mas tres bordes {v5, v8}, {v8, v9} y {v9, v10}.
La coincidencia inicial es {{v2, v3}, {v4, v5}, {v8, v9}}. Inicialmente, hay dos 
rutas de aumento de longitud a lo sumo 5: P1 = (v6, v7) y P2 = (v1, ..., v6).
Si P1 se aumenta primero, entonces no quedan m�as rutas de aumento de longitud
a lo sumo 5.
Sin embargo, aunque aumentar P2 destruye la ruta P1, tambi�en crea una nueva
ruta de aumento P3 = (v10, v9, v8, v5, v6, v7) que se puede aumentar.

PROBLEMA DE RUTEO DE VEHICULOS
Un problema de rutas de vehiculos consiste en determinar las rutas de un conjunto
(o flotilla) de vehiculos que deben iniciar un recorrido (y finalizarlo) en los almacenes 
(o depositos) para atender la demanda de servicio de un conjunto disperso
de clientes sobre una red.
El transporte es uno de los sectores que mas aporta a la generacion de riqueza en
el mundo.

El transporte por carretera muestra un comportamiento netamente superior al resto
de los modos y actividades de transporte (ferroviario, maritimo y aereo) en cuanto
a generacion de valor.
En este trabajo se analizan todos los factores que se tienen en cuenta a la hora de
elaborar las rutas diarias de cada operario de un vehiculo: la planificacion inicial
de las rutas llevada a cabo por el jefe de taller y la encargada de control y gesti �on
de los equipos, asi como los cambios llevados a cabo por los operarios en una ruta
decidiendo el orden de las visitas en base a diferentes factores no considerados
en la determinacion de la ruta inicial, tales como: el consumo diario actual del
cliente, la zona geografica, las necesidades especificas del cliente, la comodidad,
el trafico, etc..
Trata una situacion en la cual se envia un bien desde uno o varios puntos de origen
hasta uno o varios puntos de destino con el objetivo de determinar la cantidad
enviada, satisfaciendo al mismo tiempo las restricciones de la oferta y la demanda,
y minimizando el costo total del envio.
Este problema tambien se caracteriza por suponer que el costo de envio en una
ruta determinada es directamente proporcional al n�umero de unidades enviadas en
esa ruta.
Las caracteristicas diferentes de los clientes, la demanda, los almacenes y los
vehiculos, asi como de las restricciones operativas sobre las rutas, horarios, etc.
dan lugar a gran numero de variantes del problema.
El problema especifico surge de una empresa perteneciente al sector de la distribucion
automatica, cuya actividad empresarial es distribucion y abastecimiento de
maquinas vending y de agua refrigerada.
Esta actividad pone a disposicion del consumidor una amplia gama de productos a
traves de un nuevo modelo de distribucion, constituyendo al tiempo, un punto de
vista diferenciado de lo tradicional, puesto que no requiere la presencia humana
de un vendedor.
La empresa objeto de estudio distribuye sus m�aquinas principalmente en entornos
laborales, centros p�ublicos y privados y en empresas dedicadas al sector servicios.
Cualquier empresa del mercado se enfrenta a variables externas que afectan su
gestion.
En el caso de estudio, destaca la tendencia en los precios de los recursos energ�eticos, ya que la actividad de la empresa supone un desplazamiento continuo de
todos los operarios a todos los clientes.
La planificacion actual de las rutas de trabajo depende de los siguientes factores:
localizacion del cliente, consumo mensual y tipo de maquina . Posteriormente, el
operario realiza cambios en esta ruta bas�andose en unos criterios previstos y que
dan lugar a la ruta replanificada: jornada laboral de los clientes, media mensual de
consumo, ubicacion de las m�aquinas y dimensi �on de la posici �on, ampliaci �on del
numero de m�aquinas instaladas en un mismo cliente, modificaci �on de la capacidad
de la maquina, nueva l�inea de negocio de la empresa, periodo de caducidad de los
productos, etc..
Tambien se consideran una serie de factores imprevistos como:
. Averias en los equipos/avisos reposicion
. dias festivos
. avisos de los clientes durantes la jornada
. maquinas no atendidas
. jornada laboral de los clientes
 
Para determinar el costo asociado a cada arco se define la siguiente funci �on:
fij = Kmij � Cu + tij � Cm + CT ributos
Donde:
Km representa una matriz de distancia (en kms)
Cu matriz de costo del recurso energ�etico
t matriz de tiempos de recorrido (en minutos)
Cm matriz de costo de las horas trabajadas por los operarios (en moneda)
CT matriz de costo de la circulaci �on de los camiones (costas e impuestos al
transporte).

Aunque estos son los componentes fundamentales de los costos directos de las
empresas de transporte, el modelo se podria extender facilmente introduciendo
otras variables como son los gastos en neumaticos, mantenimiento, reparaciones
y amortizacion y financiacion de los vehiculos.
Desde el punto de vista de los costos, este estudio proporciona un total de 16
valores minimos.
Esto significa que de las veinte jornadas diarias analizadas que componen cada
mes estudiado (Semana 1-Lunes o S1 - L,...Semana 4-Viernes o S4 - N) la
aplicacion ha obtenido en dieciseis de estas costos minimos �optimos Por tanto, el
costo global de una ruta disminuye dado que se repite la misma secuencia de visitas 
durante la primera y tercera semana, y durante la segunda y la cuarta semana
para todos los meses analizados.
Estos resultados comparados con el unico valor minimo que ha generado la ruta inicial 
confirman que las secuencias provistas por dicha aplicaci �on ayudan a
reducir el costo a la empresa.
La diferencia entre los valores minimos obtenidos frente a los m�aximos, suponen
un ahorro anual total de 2.610 unidades para esta ruta.
Al comparar la ruta inicial con la ruta optima obtenida en este estudio, anualmente
la empresa ahorraria la cantidad de 984,82 unidades para la ruta estudiada siempre
y cuando se modificara la ruta inicial y la adaptara a los resultados obtenidos.

PROBLEMAS DE PAREO EN GRAFOS. PAREOS PERFECTOS Y MAXIMALES.

p a r e o s   p e r f e c t o s
Un emparejamiento perfecto de un grafo es una colecci �on de arcos
separadas que cubren todos los nodos.
Se va a denotar el n�umero de coincidencias perfectas de un gr�afico G por Mp(G).
Veamos ahora un ejemplo m�as grande. Supongamos que queremos encontrar todos los emparejamientos perfectos del gr�afico de 12 nodos que se muestra a la
izquierda de la Fig.3.25.
Se dividen en dos posibilidades segun si el nodo superior izquierdo se empareja
horizontal o verticalmente.
En el primer caso, otros tres bordes (rodeados por l�ineas de puntos en la Fig.3.25)
son obligados a formar parte de la coincidencia perfecta, y lo que queda sin cubrir
es solo un ciclo de 4 ciclos, que claramente tiene dos coincidencias perfectas.
El ultimo caso se ramifica en dos, seg�un que el nodo superior izquierdo coincida
horizontal o verticalmente.
Ahora, la instancia con emparejamiento vertical obliga a 2 bordes, dejando dos
formas de terminar este subcaso.
Las ramas alternativas coincidentes horizontalmente en dos subramas m�as; Se ve
facilmente que cada uno de ellos tiene exactamente dos formas de completarlos
para obtener una coincidencia perfecta (ver la figura).
Por lo tanto, el n�umero total de coincidencias perfectas de este gr�afico es 8.

Un ultimo ejemplo hecho a mano es el grafico de cuadricula 4 � 4G4, ilustrado
en la Fig.3.26. Nos dividimos en dos de acuerdo a que el nodo superior izquierdo
coincide horizontal o verticalmente; Por simetria, los dos casos se pueden extender
a un emparejamiento perfecto en la misma cantidad de formas.
La Fig.3.26 describe la rama superior a medida que se divide en subdivisiones, dependiendo de c�omo coincidan ciertos nodos. El n�umero de formas de terminar los
emparejamientos parciales en las puntas del arbol se encuentra f�acilmente como
se indica en la imagen. Obtenemos M(G4) = 36.

p a r e o s   m a x i m a l e s
Un emparejamiento maximal es un emparejamiento que no puede crecer por
agregado de un arco. Cumple la propiedad de que al anadir  algun arco que no
pertenece al emparejamiento, se deshace el emparejamiento.

(Emparejamiento maximal)
Si G = (N, E) es un grafo bipartito con N dividido como X U Y , un
emparejamiento maximal en G es aquel que relaciona el mayor n�umero
posible de nodos en X con los nodos en Y .
Un emparejamiento maximo � es un emparejamiento que contiene el n�umero m�aximo posible de arcos. Por lo tanto, no puede estar contenido en otro de cardinal
mayor.
Atendiendo a las definiciones anteriores se puede formular los siguientes teoremas:
Puede haber muchos emparejamientos m�aximos.
Los emparejamientos m�aximos son maximales, pero no todos los emparejamientos maximales son m�aximos.
Cada emparejamiento perfecto es m�aximo y maximal.
Los problemas de emparejamiento guardan una importante relaci �on con los grafos
bipartitos. Como ya se estableci �o un grafo G = (N, A) se dice bipartito si el
conjunto de nodos N puede separarse en dos conjuntos disjuntos N = X ? Y de
tal manera que los arcos del grafo unen siempre un nodo de X con uno de Y , es
decir, no hay arcos entre los nodos de X ni entre los nodos de Y .
Para obtener un emparejamiento m�aximo bipartito, es necesario definir previamente un par de conceptos:
Un camino alterno es un camino en el cual sus arcos alternativamente pertenecen y no pertenecen al emparejamiento.
Un camino incremento es un camino alterno que comienza y termina en
un nodo libre.
La manera de proceder para obtener un emparejamiento maximo bipartito consiste
en ir incrementando paso a paso el cardinal del emparejamiento mediante caminos
incremento hasta obtener un emparejamiento maximo.

A P L I C A C I O N E S
 e l  p r o b l e m a   de   los   m a t r i m o n i o s   e s t a b l e s
Este es un problema de asignaci �on bipartito que parte de dos conjuntos de personas que tienen el mismo cardinal, hombres y mujeres, donde cada persona de
cada grupo tiene una lista de preferencias en la que ordena a los miembros del
sexo opuesto.
El problema consiste por tanto en encontrar un emparejamiento estable entre ambos 
grupos de personas.
La estabilidad de este problema de asignacion es muy importante, ya que no se
conforma con que un hombre y una mujer est�en emparejadas con otra persona si
ambos preferir�ian estar juntos antes que con sus parejas actuales.

A pesar de que este problema ha sido muy estudiado a lo largo de las ultimas
decadas, los primeros en encontrar una soluci �on para el mismo fueron D.Gale y
G.S.Sapley, quienes en 1962 plantearon el llamado Algoritmo de Gale-Shapley.
Con este algoritmo se demostro que, si el n�umero de hombres y mujeres es el
mismo, siempre existe un emparejamiento estable entre ellos.

Este problema se puede definir en terminos de grafos, puesto que se parte de dos
conjuntos disjuntos del mismo cardinal, H = {h1, h2, ..., hn} y M = m1, m2, ...,
mn, que conformar�an el conjunto de nodos del grafo bipartito (V = H U M, con
|H| = |M|).
En terminos de matrimonios, el concepto de pareja bloqueante se puede formular
de la siguiente manera.
Si hay dos matrimonios (hi, mi) y (hj, mj ) tales que hi prefiere estar antes con
mj que con mi, y mj prefiere estar antes con hi que con hj, entonces (hi, mj )
es una pareja bloqueante, ya que tanto hi como mj se divorciaran de sus parejas
para estar juntos.
En esta definicion se basa el concepto clave de la estabilidad del emparejamiento.

Ejemplo
Sean los conjuntos H = {h1, h2, h3} y H = {m1, m2, m3} de hombres y mujeres
respectivamente. Se cuenta tambi�en con la lista de preferencias de los hombres
sobre las mujeres y de las mujeres sobre los hombres, mostradas a continuacion:

h1 m1 m2 m3
h2 m1 m3 m2
h3 m2 m1 m3

Tabla 3.1: Preferencias hombre
m1 h1 h3 h2
m2 h3 h1 h2
m3 h3 h2 h1

Tabla 3.2: Preferencias mujer
m1 h1 h3 h2
m2 h3 h1 h2
m3 h3 h2 h1

En esta situacion, el emparejamiento (h1, m1),(h2, m3),(h3, m2) seria estable, ya
que no hay parejas bloqueantes que prefieran estar juntas antes que con sus 
respectivas parejas.

Asi, los pares (h1, m1),(h2, m3),(h3, m2) son todos ellos parejas validas porque
existe un emparejamiento estable, en este caso el formado por ellas tres juntas,
para el cual son parejas.

Sin embargo, el emparejamiento (h1, m2),(h2, m1),(h3, m3) no seria estable, ya
que el par (h1, m1) seria una pareja bloqueante, puesto que h1 prefiere estar con
m1 antes que con m2, y m1 prefiere estar con h1 antes que con h2.

Al principio, todos los hombres y las mujeres estan desemparejados. Cada h1
no emparejado le propone ser su pareja al nodo mj que mas prefiere seg�un su
ordenacion (siempre que ese nodo no le haya rechazado ya).

Cada nodo mj que haya recibido alguna propuesta en el paso anterior:
Si no estaba emparejado, se empareja con el nodo hi de los que tiene propuesta
que mas prefiera segun su ordenacion, y deja a los demas como nodos
libres del emparejamiento.

Si ya estaba emparejado, se empareja con el nodo hi que mas prefiere de
entre todas sus propuestas (incluido su pareja actual), y deja a los dem�as
como nodos libres del emparejamiento.
Se repiten los pasos 1 y 2 hasta que todos los nodos hi esten emparejados
con un nodo mj.

ALGORITMO Gale-Shapley
1. Cada mujer propone su primera eleccion.
2. Los hombres con dos o mas propuestas responden rechazando a todas menos 
a la mas favorable.
3. Las mujeres rechazadas proponen su segunda eleccion. Las que no fueron
rechazadas continuan con su propuesta.
4. Se repiten los pasos 2 y 3 hasta que ninguna propuesta sea rechazada


 GRAFO DIRIGIDO
Es un triple ordenado D = (N(D), A(D), v/(ve tachada) D) que consiste en un conjunto no 
vacio de nodos N(D), un conjunto separado de arcos A(D), y
una funcion de incidencia  v/(ve tachada)D que se asocia con cada arco D con un par
ordenado (no necesariamente distinto) de nodos D.

Si a es un arco y u y v son nodos tales que v/(ve tachada)D(a) = (u, v), entonces se dice 
que a une a u con v; u es la cola de a, y v es su cabeza. Por conveniencia, abreviaremos
grafo dirigido como digrafo. En un digrafo D', hay un 
subdigrafo si N(D') c= N(D), A(D') c= A(D) y v/(ve tachada)D 
es la restriccion de v/(ve tachada)D  para A(D'). 
La terminologia y la notacion para subdigrafos es similar a la utilizada para subgrafos.

Cada digrafo D se puede asociar un grafo G con el mismo conjunto de nodos,
correspondiendo a cada arco de D un borde de G con los mismos extremos.

Este grafo es el grafo subyacente de D. A la inversa, dado cualquier grafo G, podemos 
obtener un digrafo de G especificando, para cada enlace, una orden en sus
extremos. Tal digrafo se llama una orientacion de G.

Al igual que con los grafos, los d�igrafos tienen una representacion grafica simple.
Un digrafo se representa mediante un diagrama de su grafo subyacente junto con
flechas en sus bordes, cada flecha apuntando hacia la cabeza del arco correspondiente (fig.4.1).

GRAFOS DIRIGIDOS PROPIEDADES
Todos los conceptos que son validos para los grafos tambien se aplican
a los digrafos. 
Sin embargo, hay muchos conceptos que implican la nocion de orientacion, y
estos se aplican solo a los digrafos.
Un RECORRIDO en D es una secuencia finita no nula W = (v0, a1, v1, ..., ak, vk),
cuyos terminos son nodos y arcos alternativamente, de manera que, para
i = 1, 2, ..., k, el arco ai tiene cabeza vi y cola vi-1. 
Al igual que con los paseos en los grafos, un recorrido (v0, a1, v1, ..., ak, vk) 
a menudo se representa simplemente por su secuencia de nodo (v0, v1, ..., vk).
Si hay una ruta (u, v) dirigida en D, se dice que el nodo v es accesible desde el
nodo u en D.

Dos nodos estan conectados en D si cada uno es accesible desde el otro. Como en el 
caso de la conexion en grafos, la conexion dirigida es una relacion de
equivalencia en el conjunto de nodos de D.

Los subdigrafos D[N1], D[N2], ..., D[Nm] inducidos por la partici �on resultante.
(NI , N2, ..., Nm) de N(D) se llaman d-componentes de D. Un d�igrafo D es dconectado si 
tiene exactamente un d-componente.
El digrafo de la fig.4.3a esta d-conectado; tiene los tres componentes que se muestran 
en la fig.4.3b.

Definicion 1  
Una red es un digrafo con una fuente designada s y un destino
t != s, ademas, cada arco e tiene una capacidad positiva, c(e).
Las redes se pueden utilizar para modelar el transporte a traves de una red fisica,
de una cantidad fisica como el petroleo o la electricidad, o de algo mas abstracto,
como la informacion.

Definicion 2 
Un flujo en una red es una funcion f de los arcos del digrafo a R,
con 0 <= f(e) <= c(e) para todo e, y tal que:
ZUMATORIA e E E + vf(e) = ZUMATORIA e E E - vf(e)

para todo v excepto s y t.

Se desea asignar un valor a un flujo, igual al flujo neto que sale de la fuente, dado
que la sustancia que se transporta no puede recolectarse ni originarse en ningun
nodo que no sea s y t, parece razonable que este valor tambien sea el flujo neto
hacia el objetivo.

Antes de probar esto, se introduce una nueva notacion. Suponer que U es un conjunto de
nodos en una red, con s E U y t E/ U.
Sean U-> el conjunto de arcos (v, w) con v E/ U, w E/ U, y
U<- el conjunto de arcos (v, w) con v E/ U, w E U.

Definicion 4
El valor de un flujo, denotado val(f), es
ZUMATORIA e E E + sf(e) - ZUMATORIA e E E - sf(e)
Un flujo maximo en una red es cualquier flujo f cuyo valor es el maximo entre
todos los flujos.
A continuacion, se busca formalizar la nocion de cuello de botella, a fin de demostrar
que el caudal maximo es igual a la cantidad que puede pasar por el cuello
de botella mas pequeno.

Definicion 5 
Un corte en una red es un conjunto C de arcos con la propiedad
de que cada camino de s a t usa un arco en C, es decir, si los arcos en C se
eliminan de la red, no hay camino desde s a t.
La capacidad de un corte, denotada c(C), es
ZUMATORIA e E Cc(e)
Un corte minimo es uno con capacidad minima, es minimo si ningun corte esta
correctamente contenido en C.
Tener en cuenta que un corte minimo es cuando U es un conjunto de nodos que
contiene s pero no t, entonces
->U es un corte.

Lema 6 
Suponer que C es un corte minimo, entonces hay un conjunto U que
contiene s pero no t tal que C =->U .

Prueba. Sea U el conjunto de nodos v tales que hay un camino de s a v sin arco
en C.
Suponer que e = (v, w) E C, dado que C es m�inimo, hay un camino P de s a t
usando e pero ning�un otro arco en C.
Por lo tanto, hay un camino de s a v sin usar un arco de C, entonces v E U.
Si hay un camino de s a w sin arco de C, entonces este camino seguido por la
parte de P que comienza con w es un camino de s a t sin arco en C.
Esto implica que hay un camino de s sin usar ningun arco en C, lo que ocasiona
una contradiccion. Asi w E/ U y por lo tanto e E U. 
Por lo tanto, C c= U-> .
Suponer que e = (v, w) E U-> , entonces v E U y w E/ U, por lo que cada camino
de s a w usa un arco en C.
Dado que v E U, hay un camino de s a v que no usa un arco de C, y este camino
seguido por e es un camino de la s a la w. Por lo tanto, el arco e debe estar en C,
por lo que ->U c= C.
Ahora hemos demostrado que C c= U-> .
Ahora podemos probar una version del importante teorema de flujo maximo, corte
minimo.

REPRESENTACIONES de un G R A F O   D I R I G I D O
Sea D un grafo dirigido con m nodos, la representacion secuencial de D
en memoria o sea, la representacion de D por su matriz de adyacencia
MA tiene unas cuantas desventajas importantes, en primer lugar, puede
ser dificil insertar y eliminar nodos de D.

Esto es porque el tamano de MA deberia de ser cambiado y los nodos deberian
de ser reordenados, debido a lo cual, habria que realizar muchos cambios en la
matriz MA.

Mas aun si el numero de arcos es O(m) u O(m log i m), entonces la matriz
MA estara desperdiciada (contendra muchos ceros) por tanto, se desperdiciara
una gran cantidad de espacio. Por tanto D normalmente se representa en memoria
por una representacion enlazada, tambien llamada estructuras de adyacencia.

Dado el digrafo D de la fig.4.4(a), la tabla de la fig.4.4(b) muestra cada nodo de D
seguido por su lista de nodos adyacentes, tambien llamados sucesores o vecinos.

A continuacion la fig.4.5 muestra el diagrama esquematico de la representacion
enlazada de D en memoria.
Especificamente la representacion enlazada contendra dos listas (o archivos) una
lista de nodos denominada NODO y una lista de arcos llamada ARCO.

*Lista de nodos. Cada elemento de la lista de NODO correspondera a un
nodo de D y sera un registro de la forma:
NODO      SIG      ADY
Aqui NODO sera el nombre o valor clave del nodo, SIG sera un apuntador
al siguiente NODO de la lista NODO y ADY sera un apuntador al primer
elemento de la lista de adyacencia del nodo que se mantiene en la lista
ARCO.
El area sombreada indica que puede haber otra informacion en el registro, 
tal como el grado de entrada GRADENT del nodo, el grado de salida GRADSAL del nodo, 
el ESTADO del nodo durante la ejecuci �on de
un algoritmo, etc. (alternativamente se puede asumir que NODO es un
arreglo de registros conteniendo campos como NOMBRE, GRADENT ,
GRADSAL, ESTADO).
Los nodos mismos, como se ve en la fig.4.4 estaran organizados como una
lista enlazada y por tanto habra una variable apuntador PRINCIPIO para
el comienzo de la lista y una variable apuntador NDISP para la lista de 
espacio disponible.
A veces, dependiendo de la aplicacion, los nodos pueden
estar organizados como un arreglo ordenado o un arbol binario de busqueda
en vez de una lista enlazada.

*Listas de arcos. Cada elemento de la lista ARCOS corresponder�a a un arco
de D y sera un registro de la forma;
DEST     ENL
El campo DEST apuntara a la posicion de la lista NODO del nodo destino
o terminal del arco. El campo ENL enlazara juntos los arcos con el mismo
nodo inicial, o sea, los nodos de la misma lista de adyacencia. El area 
sombreada indica que puede haber otra informacion en el registro del arco, tal
como un campo ARCOS conteniendo los datos etiquetados del arco cuando D es un 
digrafo con etiquetas, un campo P ESO conteniendo el peso del
arco cuando D es un digrafo con peso, etc.
Tambien se necesita una variable apuntador ADISP para la lista de espacio
disponible en la ARCO.

La fig.4.6 muestra como apareceria el digrafo D de la fig.4.4(a) en memoria. La
eleccion de 10 posiciones para la lista NODO y de 12 posiciones para la lista
ARCO es arbitraria. La representacion enlazada de un digrafo D vista se puede
denotar por:
DIGRAFO(NODO, SIG, ADY, P RINCIP IO, NDISP, ENL, ADISP)

La representacion puede incluir un arreglo PESO cuando D tiene peso o puede
incluir un arreglo ARIS cuando D es un digrafo con etiquetas.

------------------------------------------------------------------------------
ALGORITMOS PARA GRAFOS DIRIGIDOS
-  Algoritmo Primero en Anchura y Primero en Profundidad para grafos dirigidos

Los algoritmos empleados en grafos dirigidos son los mismos que se
emplean en los no dirigidos, por ejemplo para la determinacion de los
caminos mas cortos.
*Algoritmo de Dijkstra
*Algoritmo de Floyd-Warshall

En el caso de algoritmos de recorrido o de busqueda se emplean mas comunmente:
*Algoritmo de busqueda en anchura
*Algoritmo de busqueda en profundidad

-Algoritmo de Dijkstra-
El algoritmo de Dijkstra, tambien llamado algoritmo de caminos minimos, es un
algoritmo para la determinacion del camino mas corto dado un nodo origen al
resto de nodos en un grafo dirigido y con pesos en cada arco.
La idea subyacente en este algoritmo consiste en ir explorando todos los caminos
mas cortos que parten del nodo origen y que llevan a todos los demas nodos.
Cuando se obtiene el camino mas corto desde el nodo origen, al resto de nodos que
componen el grafo, el algoritmo se detiene. El algoritmo es una especializaci �on
de la busqueda de costo uniforme, y como tal, no funciona en grafos con arcos de
costo negativo.

-Algoritmo de Floyd-Warshall-
Intenta resolver el problema de encontrar el camino mas corto entre todos los
pares de nodos o nodos de un grafo.
Esto es similar a construir una tabla con todas las distancias m�inimas entre pares
de ciudades de un mapa, indicando la ruta a seguir para ir de la primera ciudad a
la segunda.

-Algoritmo de busqueda en anchura -
Es un algoritmo para recorrer o buscar elementos en un grafo (usado frecuentemente sobre arboles).
Intuitivamente, se comienza en la raiz (eligiendo alg�un nodo como elemento raiz
en el caso de un grafo) y se exploran todos los vecinos de este nodo.

Su nombre se debe a que expande uniformemente la frontera entre lo descubierto
y lo no descubierto. Llega a los nodos de distancia k, solo tras haber llegado a
todos los nodos a distancia k - 1.
Formalmente, BFS^1
es un algoritmo de busqueda sin informacion, que expande y
examina todos los nodos de un arbol sistematicamente para buscar una solucion.
El algoritmo no usa ninguna estrategia heuristica.
El peso de los arcos para ejecutar BFS debe de ser de IGUAL costo. Si los arcos
tienen pesos negativos se aplica el algoritmo de Bellman-Ford en alguna de sus
dos versiones.

Descripcion detallada:
*Dado un nodo fuente s, se explora los nodos de D para descubrir todos los
nodos alcanzables desde s.
*Se busca desde s a todos los nodos alcanzables.
*Despues produce un arbol BF con raiz en s y que contiene a todos los nodos
alcanzables.
*El camino desde s a cada nodo en este recorrido contiene el minimo numero
de nodos. Es el camino mas corto medido en n�umero de nodos.

Durante un recorrido en anchura, cuando se recorren ciertos arcos, llevan a nodos
sin visitar.
Los arcos que llevan a nodos nuevos se conocen como arcos de arbol y forman un
bosque abarcador en anchura para el grafo dirigido dado.
Ademas de los arcos de arbol, existen dos tipos de arcos definidos por una busqueda
en anchura de un grafo dirigido, que se conocen como:

*Arco de retroceso: Es el arco que va de un nodo a uno de sus antecesores. Un arco 
que va de un nodo hacia si mismo se considera una arco de retroceso.
*Arco cruzado: Es el arco que va de un nodo a otro que no es ni antecesor
ni descendiente.

-Algoritmo de Busqueda en Profundidad-
El recorrido en profundidad DFS^2
es un algoritmo que permite recorrer todos los
nodos de un grafo o arbol de manera ordenada, pero no uniforme.
Su funcionamiento consiste en ir expandiendo todos y cada uno de los nodos que
va localizando, de forma recurrente, en un camino concreto.
Cuando ya no quedan m�as nodos que visitar en dicho camino, regresa, de modo
que repite el mismo proceso con cada uno de los hermanos del nodo ya procesado.
Durante un recorrido en profundidad, cuando se recorren ciertas arcos, llevan a
nodos sin visitar.

Los arcos que llevan a nodos nuevos se conocen como arcos de arbol y forman un
bosque abarcador en profundidad para el grafo dirigido dado.
Ademas de los arcos de arbol, existen tres tipos de arcos definidos por una busqueda
en profundidad de un grafo dirigido, que se conocen como:
*Arco de retroceso: Es el arco que va de un nodo a uno de sus antecesores. 
Un arco que va de un nodo hacia si mismo se considera una arco de
retroceso.
*Arco de avance: Es el arco que va de un nodo a uno de sus descendientes.
*Arco cruzado: Es el arco que va de un nodo a otro que no es ni antecesor
ni descendiente.

------------------------------------------------------------------------------------------
PROBLEMAS sobre grafos dirigidos  e j e r c i c i o s
La tecnologia de grafos permite capturar en tiempo real, conexiones entre entidades, 
tambien ayudan a detectar anomalias y comportamientos erroneos en los
conjuntos de entidades que se conectan en una red para evitar de forma eficiente
amenazas que pueden perjudicar la integridad de dichas entidades.

p l a n i f i c a c i o n   de  TAREAS
La planificacion de tareas es un proceso que consiste en identificar, organizar y
planificar las actividades que deben llevarse a cabo dentro de un proyecto, para
luego estimar su duracion y los recursos necesarios para completarlas.

-Construccion de una piramide
�En cuanto tiempo, como minimo, se puede construir la piramide?
�Cuando debe empezar cada tarea en la planificacion optima?
�Que tareas son mas criticas (es decir, no pueden sufrir retrasos)?
�Cuanta gente necesitamos para acabar las obras?

-Ejemplo de construccion de una casa
El grafo de la figura muestra la secuencia de las diferentes etapas en la 
construccion de una casa.

-Redes de distribucion de balon en futbol
El patron de juego en un partido de futbol puede formularse como una red de
pases de balon. Los jugadores son nodos y los pases son vinculos orientados,
conformando un digrafo del que su grosor indicara la cantidad de pases entre dos
jugadores.
Esta forma de reducir la estructura del juego permite examinar el papel de actores
individuales y, al mismo tiempo, representa el desempeno del equipo en su conjunto.
La dinamica del juego se representa en una estructura social de interaccion.

-Grafo de clasificacion biologica 
Un arbol filogen�etico es un esquema arborescente que muestra las relaciones evolutivas
entre varias especies u otras entidades que se cree que tienen una ascendencia comun.
Los arboles filogeneticos se usa informacion proveniente de fosiles y de la comparacion
anatomica, fisiologica y molecular de los organismos actuales.

DIGRAFOS Y LENGUAJE NEUTRAL
Cuando el ser humano lee o escucha una palabra, inmediatamente la relaciona
con un concepto. Esto es posible gracias a la acumulacion de informacion y a la
posibilidad de filtrar, procesar y relacionar dicha informacion.
Para una computadora, una expresion escrita en el lenguaje natural es una cadena 
de bits que no aporta informaci �on por s�i sola. La computadora interpreta esta
cadena de bits, modelando el proceso que tiene lugar en la mente humana, estructurando 
y relacionado la cadena con informaci �on previamente almacenada.
En el proceso, asi como al momento de describir los resultados, el texto es representado 
por estructuras formales que permiten el procesamiento autom�atico, la
interpretacion y la comparaci �on de la informacion.

Para el ser humano una frase expresada en lenguaje natural leida, escuchada, hablada o escrita
adquiere inmediatamente un significado. Cada palabra o conjunto
de palabras, se asocia con un conjunto de experiencias e im�agenes que al ser relacionadas y filtradas 
trae a la mente exactamente el significado correcto.
El hombre identifica de qui�en se habla, la accion que realiza, el tiempo, los sinonimos, el dominio 
y todas las particularidades del lenguaje natural.
Para una computadora, un texto escrito en lenguaje natural, corresponde a una
cadena de bits (simbolos) sin significado alguno.
Para que la computadora pueda entender su significado, se debe recurrir a tecnicas
propias del procesamiento del lenguaje natural (PLN) y de la linguistica computacional (LC) y 
a artificios computacionales como el de estructurar la informacion
de tal forma que esta pueda ser gestionada y relacionada con algun significado.
Significado que puede buscarse usualmente en elementos especializados para tal
fin, tales como ontologias, tesauros, bases de conocimiento, entre otros.

El proceso de estructurar el texto escrito en lenguaje natural o de representar la
cadena de simbolos en una estructura computacional como un vector, un arbol, una
pila, un modelo relacional, entre otras, permite que se pueda gestionar la cadena a
traves de algoritmos computacionales.

Para transformar de forma automatica el texto a la estructura escogida se utilizan
las partes de dicha cadena, es decir las palabras y sus interrelaciones y de acuerdo
a la estructura escogida, es deseable que, por un lado, dicha estructura permita
incluir la mayor cantidad de informacion -entendida informacion como aquella
que aporta al significado de la cadena-, y por el otro, que el proceso de transformar
la cadena a esta estructura sea factible de ser automatizado.

Existen varios metodos para representar los documentos como grafos Los metodos
se clasifican en: estandares, simples, distancia n, distancia n-simple, frecuencia
absoluta y frecuencia relativa. Cada metodo se basa en examinar los t�erminos en
cada documento y sus adyacencias.
Al igual que en otros metodos, los terminos se extraen del documento y se realiza
un pre-procesamiento.
Este generalmente consiste en eliminar las palabras que no aportan significado a
los documentos (stop words) para asi tratar de disminuir la dimensionalidad.

ESTANDAR 
Cada palabra corresponde a la etiqueta de un nodo y si una palabra
a inmediatamente precede a una palabra b en una seccion s, entonces existe una
arista que comienza en a y termina en b etiquetada con s. En este caso se tiene
en cuenta la puntuacion y las secciones propias de un documento como el titulo o
resumen, entre otros.
SIMPLE
A diferencia de la estandar, no se etiquetan las aristas con las secciones y
no se tienen en cuenta todas las secciones sino aquellas que sean mas visibles.
DISTANCIA N
Se buscan las n palabras siguientes a partir de un termino dado, y
las aristas se etiquetan con la distancia al punto inicial. 
El parametro n es definido por el usuario.
DISTANCIA SIMPLE
Es similar a la anterior, con la diferencia de que las aristas no
son etiquetadas y lo unico que se sabe es que la distancia entre dos nodos
conectados es menor que n.
FRECUENCIA ABSOLUTA
Es similar a la representacion simple, pero cada nodo y
arista son etiquetados con una medida de frecuencia. Para un nodo esto indica
cuantas veces los t�erminos aparecen en el documento; para las aristas esto 
significa el numero de veces que dos terminos conectados aparecen en el orden 
especifico. Bajo esta representacion, el tamano del grafo se define como la suma de las
frecuencias de los nodos mas la suma de las frecuencias de las aristas.
FRECUENCIA RELATIVA
Es similar a la frecuencia absoluta con la diferencia de que
las frecuencias son normalizadas entre 0 y 1. Los nodos se normalizan por el valor
maximo de frecuencia de los nodos y las aristas similarmente por el maximo valor
de frecuencia en las aristas.
GRAFOS CONCEPTUALES
Un grafo conceptual es un grafo bipartito, esto es, que tiene dos tipos de nodos:
conceptos y relaciones conceptuales, y cada arco une solamente a un concepto
con una relacion conceptual.

Existen dos notaciones para los grafos conceptuales, la forma lineal (textual) y
los diagramas o display form, que presentan tres tipos de elementos notacionales:
rectangulos, que marcan los nodos de concepto, circulos, que marcan los nodos
de relacion, flechas direccionadas, que marcan los arcos:
Notacion textual
[CONCEPT1] (REL.) [CONCEPT2]
La intencion del uso de los grafos conceptuales para la representacion del lenguaje
natural es importante para la aplicacion del esquema al analisis del lenguaje.

Los grafos conceptuales ponen el enfasis en la representacion semantica (en el
sentido linguistico de la palabra), por ejemplo, tomar la siguiente expresion:

Typhoon Babs weakened into a severe tropical storm Sunday night after it triggered 
massive flooding and landslides in Taiwan and slammed Hong Kong with
strong winds. The storm earlier killed at least 156 people in the Philippines and
left hundreds of thousands homeless.

El tifon Babs se debilito a tormenta tropical severa la noche del domingo despues
de haber provocado graves inundaciones y deslizamientos de tierra en Taiwan
y cerro en Hong Kong con fuertes vientos. La tormenta mato al menos a 156 personas 
en Filipinas y dejo a cientos de miles sin hogar.

Se consideran como conceptos a palabras de contenido, es decir, todas las palabras
excepto palabras auxiliares (como articulos, preposiciones, etc.); y como relaciones
conceptuales se consideran a los roles semanticos: agente, iniciador, instrumento, 
experimentante, paciente, lugar, tiempo, objeto, fuente, y meta; asi como
otras relaciones tales como atributo, cantidad, medida, etc., aproximadamente 30
relaciones.
---------------------------------------------------------------------------------------------
GRAFO ACILICO DIRIGIDO
Un grafo aciclico dirigido (DAG por sus siglas en ingles), es un grafo dirigido
finito sin ciclos dirigidos.

Esto significa que sus nodos estan conectados por arcos con una direccion especifica 
y el recorrido de todo el grafo nos lleva de un punta A al B, sin tener la
posibilidad de regresar al punto en A de ninguna forma.

Aciclico significa que no hay bucles (es decir, ciclos) en el grafico, de modo que
para cualquier nodo dado, si sigue un arco que conecta ese nodo con otro, no hay
camino en el grafico para volver a ese nodo inicial.

p r o p i e d a d e s
1. Tienen un punto de partida (origen) y un punto de llegada o final (sumidero).
Al ser dirigidos, esto garantiza que su recorrido siempre vaya de un punto
de origen a un punto final, y no se puede regresar sobre dicho recorrido.
2. La modificacion de una relacion entre nodos, reescribe la totalidad del DAG,
debido a que su estructura y peso ha variado
3. Son paralelizables. Un DAG puede tener generacion paralela y recorridos de
diferente valor entre distintos nodos. Esto optimiza su generaci �on y la capacidad 
de verificar la relacion entre los nodos y la informaci�on que puedan
contener.
4. Son reducibles. Una propiedad unica de los DAG es que su estructura puede
ser reducida a un punto optimo en que su recorrido cumpla con todas las
relaciones especificadas en el mismo sin ninguna perdida. Esto significa
que es posible reducir las relaciones de los nodos hasta un punto minimo en
que dicha reduccion no afecta la capacidad de verificar la informacion de
ningun nodo en ningun momento.

Un DAG tambien puede utilizarse para representar conceptualmente una serie de
actividades.
El orden de las actividades se representa mediante un grafico, que se presenta
visualmente como un conjunto de circulos, cada uno de los cuales representa una
actividad, algunos de los cuales estan conectados por lineas, que representan el
flujo de una actividad a otra, cada c�irculo es un nodo y cada linea es un arco.

Dirigido significa que cada arco tiene una direccion definida, por lo que representa 
un flujo direccional unico de un nodo a otro.
Los DAG son utiles para representar muchos tipos diferentes de flujos, incluidos
los flujos de procesamiento de datos.
Al pensar en los flujos de procesamiento a gran escala en terminos de DAG, se
pueden organizar los diversos pasos y el orden asociado para estos trabajos.

En muchos entornos de procesamiento de datos, se ejecutan una serie de calculos
sobre los datos para prepararlos para uno o mas destinos finales. Este tipo de flujo
de procesamiento de datos a menudo se denomina canalizacion de datos.

Como ejemplo, los datos de transacciones de ventas pueden procesarse inmediatamente para 
prepararlos para hacer recomendaciones en tiempo real a los consumidores.
Como sugiere su nombre, las canalizaciones de datos actuan como la tuberia para
proyectos de ciencia de datos o paneles de control de business intelligence.
Los datos se pueden obtener a partir de una amplia variedad de lugares: API, SQL
y bases de datos NoSQL, archivos, etc., pero desafortunadamente, estos datos no
suelen estar preparados para su uso inmediato.

Como parte del ciclo de vida del procesamiento, los datos pueden pasar por muchos pasos,
incluida la limpieza (correccion de datos incorrectos/no validos), la agregacion 
(calculo de resumenes), el enriquecimiento (identificacion de relaciones con datos relevantes) 
y la transformacion (escribir los datos en nuevo formato).
Una vez que los datos se han filtrado adecuadamente, fusionado y resumido, se
pueden almacenar y mostrar.

Las canalizaciones de datos bien organizadas proporcionan la base para una gran
variedad de proyectos de datos, entre los que se incluyen el analisis de datos exploratorios, 
las visualizaciones de datos y tareas de machine learning.
Otra caracteristica clave de los DAG y los flujos de datos que modelan es que puede haber varias 
rutas en el flujo. Esto es importante porque reconoce la necesidad
de procesar los datos de multiples maneras para adaptarse a diferentes resultados
y necesidades.

Un flujo de datos consta de una serie de elementos de datos ordenados en el tiempo. Estos 
representan un evento o un cambio de estado que ha ocurrido en la
empresa, y es util para que la empresa los conozca y analice en tiempo real.
Un flujo de datos se puede ver como una cinta transportadora sin fin, que transporta datos 
y los alimenta continuamente a un procesador de datos.

Los datos se cargan primero desde los sensores y luego se separan por tipo de
sensor. Los datos del sensor X se resumiran por segundo y luego se analizaran en
tiempo real. Si se observa alg�un estado critico, se envia una alerta.
Los datos tambien se guardan para el almacenamiento a largo plazo y posiblemente para 
otros analisis. 
Tambien en este flujo hay datos del sensor Y, que por ahora
se resumen por minuto y luego se almacenan en el mismo almacen a largo plazo
que los datos del sensor X.

Un ejemplo de como se aplican los DAG a las canalizaciones de procesamiento
por lotes , suponer una base de datos de ventas globales y se desea un informe de
todas las ventas por region, expresado en dolares estadounidenses.
Primero se cargan todos los datos en un motor de procesamiento, se separan los
datos por las diferentes monedas, convertir las cifras financieras a dolares estadounidenses.
Luego resumir los datos por pais/region y reunir todos los datos en un informe
final. Ademas los datos solo de EE. UU. tambien se crearan en un informe separado.



*/
