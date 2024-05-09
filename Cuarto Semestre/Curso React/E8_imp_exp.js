// import { heroes } from './Data/heroes';
// import { heroes } from './Data/heroes'; con imp
// import heroes, { owners } from './Data/heroes'; // escribiendo el archivo "heroes"
import heroes from "./heroes.js";

// console.log( owners );

export const getHeroById = ( id ) => {
    return heroes.find( ( heroe ) => heroe.id === id ); 
};

// console.log( getHeroById( 2 ) );

export const getHeroByOwner = ( owner ) => {
    return heroes.filter( ( heroe ) => heroe.owner === owner );
};

// console.log( getHeroByOwner( 'DC' ) );