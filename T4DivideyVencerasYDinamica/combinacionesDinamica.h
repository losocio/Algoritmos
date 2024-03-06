#ifndef COMBINACIONESDINAMICA_H
#define COMBINACIONESDINAMICA_H

using namespace std;

/*  
Calculo de combinaciones mediante programacion dinamica
    Parámetro: int n elementos y grupos de r elementos
    Retorno: int con el numero de combinaciones
    Precondicion: n >= r, n < 10
    Complejidad Temporal: O()
    T(n) = (6 + c) 3^(n - 1) - 2 
    Complejidad Espacial: O()
*/
// TODO: No tiene mucho sentido que se calcule la tabla para cada combinacion, si da tiempo haz una funcion separada para ese proposito
int combinacionesDinamica(int n,int r);

#endif