// Desestructuracion
// Asignación desestructurada

const persona = {
    nombre: 'Juan',
    edad: 22,
    clave: 'juanciano',
    rango: 'Cadete'
};

// console.log( persona.nombre );
// console.log( persona.edad );
// console.log( persona.clave );

const { nombre, edad, clave } = persona;

console.log( nombre, edad, clave );

const getContext = ( { clave, nombre, edad, rango = 'Capitán'} ) => {
    // console.log( nombre, edad, rango );

    return {
        nombreClave: clave,
        years: edad,
        lating:{
            lat: -54.8756,
            lng: 21.3985
        }
    }
};

const { nombreClave, years, latlng:{ lat,lng } } = getContext( persona );

const persona2 = getContext( persona );

console.log( persona2 );

const clave2 = persona2.nombreClave;
const years2 = persona2.years;

console.log( 'Persona 2', clave2, years2 );

console.log( nombreClave, years );
console.log( lat, lng );

