// Objeto literal

const persona = {
    nombre: 'Juan',
    apellido: 'Rosales',
    edad: 21,
    dirección: {
        ciudad: 'Coyoacan',
        zip: 190509,
        lat: 13.584921,
        lng: 58.695784,
    }
};

// se crea otra constante con las propiedades del objeto principal
// los ... se conocen "pre operator" y representan que tomará todos los valores de la variable 
// que se coloca después
const persona2 = {...persona};
persona2.nombre = 'Manuel';

// console.log({persona});
console,log(persona);
console.log(persona2);
// Se puede obtener únicamente las propiedades de cada objeto accediendo a ellas

console.log(persona.direccion.ciudad);