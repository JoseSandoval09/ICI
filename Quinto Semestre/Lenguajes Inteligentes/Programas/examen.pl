% Nivel 1:definicion de los animales marinos

animal_marino(delfin).
animal_marino(tortuga).
animal_marino(pulpo).

% Nivel 2: caracteisticas generales animales marinos
tamano(mediano, delfin).
tamano(grande, tortuga).
tamano(pequeno, pulpo).



esperanza_vida(delfin, 25).
esperanza_vida(tortuga, 80).
esperanza_vida(pulpo, 5).


comportamiento(sociable, delfin).
comportamiento(tranquilo, tortuga).
comportamiento(solitario, pulpo).

alimentacion(carnivoro, delfin).
alimentacion(herbivoro, tortuga).
alimentacion(carnivoro, pulpo).

reproduccion(viviparo, delfin).
reproduccion(oviparo, tortuga).
reproduccion(ovoviviparo, pulpo).


habitat(oceanos, delfin).
habitat(playas, tortuga).
habitat(arrecifes, pulpo).

% reglas

?- alimentacion(TipoAlimentacion, delfin).

?- reproduccion(MetodoReproduccion, tortuga).

?- habitat(Lugar, pulpo).

% Ejemplo de consulta para obtener el tamaño promedio del delfin
% ¿Cuál es el tamaño promedio del delfin?
% Respuesta esperada: mediano
?- tamano(Tamano, delfin).

% Ejemplo de consulta para obtener la esperanza de vida de la tortuga
% ¿Cuál es la esperanza de vida de la tortuga?
% Respuesta esperada: 80
?- esperanza_vida(EsperanzaVida, tortuga).

% Ejemplo de consulta para obtener el comportamiento del pulpo
% ¿Cómo se comporta el pulpo?
% Respuesta esperada: solitario
?- comportamiento(Comportamiento, pulpo).



