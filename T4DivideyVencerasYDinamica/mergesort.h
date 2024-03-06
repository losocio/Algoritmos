#ifndef MERGESORT_H
#define MERGESORT_H

using namespace std;

/*  
Calcula el factorial
    Parámetro: int del que calcular factorial
    Retorno: int con el factorial
    Precondicion: la entrada debe de ser mayor o igual que 0
    Complejidad Temporal: O(n)
    T(n) = n + c
    Complejidad Espacial: O()
*/
void combinar(int a[],int lenA,int b[],int lenB,int c[]);

/*  
Calcula el factorial
    Parámetro: int del que calcular factorial
    Retorno: int con el factorial
    Precondicion: la entrada debe de ser mayor o igual que 0
    Complejidad Temporal: O(n)
    T(n) = n + c
    Complejidad Espacial: O()
*/
void ordenarMergeSort(const int x[],int inicio,int len);

#endif