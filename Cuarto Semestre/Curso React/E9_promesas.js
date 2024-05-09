// Promesas

import { getHeroById } from "./E8_imp_exp.js";

/*
const promesa= new Promise( ( resolver, reject ) => {
    
    setTimeout(() => {
        //resolver();
        //console.log( '2seg despues' );

        // EJERCICIO IMPORTAR FUNCION

        const heroes = getHeroById( 2 );
        resolve(heroe);

        //reject( 'No se pudo encontrar el heroe' );
    }, 2000);
});

promesa.then( ( heroe ) => {
    console.log( 'heroe', heroe );
})
.catch( err => console.warn( err ) );
*/

const getHeroByIdAsync = ( id ) => {
    return new Promise( ( resolve, reject ) => {
        
        const heore = getHeroById( id );
        if( heroe ) { resolve( heroe ); }
        else { reject( 'No se pudo encontrar el heroe' ); }
    });
};

getHeroByIdAsync( 2 )
    .then( console.log )
    .catch( console.warn );