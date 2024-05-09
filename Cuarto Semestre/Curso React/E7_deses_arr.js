// Desestructuración de arreglos

const personajes = ['Mikasa', 'Armin', 'Eren'];

const [ p1 ] = personajes;
const [ ,p2 ] = personajes;
const [ ,,p3 ] = personajes;

console.log( p1 );
console.log( p2 );
console.log( p3 );

const retornarArreglo = () => {
    return ['ABC', 123];
};

const [ letras, numeros ] = retornarArreglo();
console.log( letras, numeros );

// EJERCICIO

const [ nombre, setNombre ] = getState( 'juanciano' );

console.log( nombre );
setNombre();