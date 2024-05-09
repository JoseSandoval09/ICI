// Funciones en JS

// const saludar = function (nombre){
//      return 'Hola, $(nombre)';    
// }

const saludar2 = (nombre)=>{
    return `Hola, ${nombre}`;
}

const saludar3 = (nombre)=> `Hola, ${nombre}`

const saludar4 = () => `Hola Mundo`;

const funFlecha = () => 'Esta es una función flecha';

const funFlechaP = (param,nombre) => {
    param++;
    nombre = 'Pepe';
    return `Esta es una funcion flecha con ${param} parametro`
}

console.log(saludar2('Juan'));
console.log(saludar3('Manuel'));
console.log(saludar4());

// F1 - llamar 
console.log(funFlecha());
console.log(funFlecha(1,'Jose'));

const getUser = () => ({
    uid: 'Juan1',
    usernam: 'manuel2',
});

console.log(getUser());


// Función con un objeto
const getUsuarioActivo = (nombre) => ({
    uid: '1234',
    username: nombre,
});

// Función con un propio objeto (variable)
const usuarioActivo = getUsuarioActivo('Juan2');
console.log(usuarioActivo.username);