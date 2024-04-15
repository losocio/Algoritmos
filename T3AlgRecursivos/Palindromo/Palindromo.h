#ifndef PALINDROMO_H
#define PALINDROMO_H

using namespace std;

/* 
Palidromo recursivo.
    Parámetro: Array de longitud inferior a 20.
    Retorno: int segun si es palidromo.
    Precondicion: Ninguno.
    T(n) = 5n + c
    Complejidad Temporal: O(n)
    Complejidad Espacial: O()
*/
int esPalindromo(const char palindromo[], int i);

#endif