#ifndef COMBINACIONES_H
#define COMBINACIONES_H

using namespace std;

/*  
Calcula el factorial
    Parámetro: int del que calcular factorial
    Retorno: int con el factorial
    Precondicion: la entrada debe de ser mayor o igual que 0
    Complejidad Temporal: O()
    Complejidad Espacial: O()
*/
int factorial(int n);

/*  
Calcula el numero de combinaciones de n numeros en grupos de r
    Parámetro: int n y int r
    Retorno: int con el numero de combinaciones
    Precondicion: n >= r
    Complejidad Temporal: O()
    Complejidad Espacial: O()
*/
int combinaciones(int n, int r);

#endif