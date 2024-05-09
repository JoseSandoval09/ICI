:- discontiguous padre/2.

/*Hombres*/
hombre(caos).
hombre(ouranos).
hombre(hyperion).
hombre(oceanus).
hombre(iapetus).
hombre(atlas).
hombre(coeus).
hombre(kronos).
hombre(zeus).
hombre(hermes).
hombre(apollo).
hombre(ares).
hombre(hephaistos).
hombre(poseidon).
hombre(hades).
hombre(crius).

/*mujeres*/
mujer(gaia).
mujer(aphrodite).
mujer(themis).
mujer(mnemosyne).
mujer(theia).
mujer(tethys).
mujer(pleione).
mujer(phoebe).
mujer(rhea).
mujer(maia).
mujer(leto).
mujer(hera).
mujer(artemis).
mujer(athena).
mujer(hestia).
mujer(demeter).

/*Relaciones de padres, sin especificar si es madre o padre*/
padre(gaia,themis).
padre(gaia,mnemosyne).
padre(gaia,hyperion).
padre(gaia,theia).
padre(gaia,crius).
padre(gaia,oceanus).
padre(gaia,tethys).
padre(gaia,iapetus).
padre(gaia,coeus).
padre(gaia,phoebe).
padre(gaia,kronos).
padre(gaia,prhea).
padre(tethys,pleione).
padre(pleione,maia).
padre(phoebe,leto).
padre(rhea,zeus).
padre(rhea,hera).
padre(rhea,poseidon).
padre(rhea,hestia).
padre(rhea,hades).
padre(rhea,demeter).
padre(hera,ares).
padre(hera,hephaistos).
padre(leto,artemis).
padre(leto,apollo).
padre(maia,hermes).

padre(ouranos,aphrodite).
padre(ouranos,themis).
padre(ouranos,mnemosyne).
padre(ouranos,hyperion).
padre(ouranos,theia).
padre(ouranos,crius).
padre(ouranos,oceanus).
padre(ouranos,tethys).
padre(ouranos,iapetus).
padre(ouranos,coeus).
padre(ouranos,phoebe).
padre(ouranos,kronos).
padre(ouranos,rhea).
padre(oceanus,pleione).
padre(iapetus,atlas).
padre(atlas,maia).
padre(coeus,leto).
padre(kronos,zeus).
padre(kronos,hera).
padre(kronos,poseidon).
padre(kronos,hestia).
padre(kronos,hades).
padre(kronos,demeter).
padre(zeus,hephaistos).
padre(zeus,ares).
padre(zeus,athena).
padre(zeus,artemis).
padre(zeus,apollo).
padre(zeus,hermes).


/*Relacion de pareja*/
pareja(gaia, ouranos).
pareja(ouranos, gaia).
pareja(oceanus, tethys).
pareja(tethys, oceanus).
pareja(coeus, phoebe).
pareja(phoebe, coeus).
pareja(kronos, rhea).
pareja(rhea, kronos).
pareja(pleione, atlas).
pareja(atlas, pleione).
pareja(leto, zeus).
pareja(zeus, leto).
pareja(maia, zeus).
pareja(zeus, maia).
pareja(zeus, hera).
pareja(hera, zeus).

/* Reglas para establecer relaciones familiares*/

padre_h(X, Y):-hombre(X), padre(X, Y).

madre(X, Y):-mujer(X), padre_h(Z, Y), pareja(X, Z).

hermanos(X, Y):-padre_h(Z, X),padre_h(Z, Y), X \= Y.

tio(X, Y):-hermanos(X, Z), padre_h(Z, Y).
tio(X, Y):-hermanos(X, Z), madre(Z, Y).

abuelo(X, Y):-padre_h(X, Z), padre_h(Z, Y).
abuela(X, Y):-madre(X, Z), padre_h(Z, Y).

nieto(X, Y):-abuelo(Y, X).
nieta(X, Y):-abuela(Y, X).

bisabuelo(X, Y):-abuelo(X, Z), padre_h(Z, Y).
bisabuela(X, Y):-abuela(X, Z), padre_h(Z, Y).

bisnieto(X, Y):-bisabuelo(Y, X).
bisnieta(X, Y):-bisabuela(Y, X).




