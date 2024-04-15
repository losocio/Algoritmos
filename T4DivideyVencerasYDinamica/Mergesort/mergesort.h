#ifndef MERGESORT_H
#define MERGESORT_H

using namespace std;

/*  
Combina dos subarrays ordenados en un array nuevo tambien ordenado
    Parámetro: 
        x: array a ordenar
        inicioIzquierda: indice de inicio del subarray de la izquierda
        lenIzquierda: longitud del subarray izquierdo
        inicioDerecha: indice de inicio del subarray de la derecha
        lenDerecha: longitud del subarray derecho
        temp: array temporal para guardar el resultado de la combinacion

    Retorno: Ninguno

    Precondicion: lenIzquierda >= 0, lenDerecha >= 0
*/
void combinar(int x[],int inicioIzquierda,int lenIzquierda,int inicioDerecha,int lenDerecha,int temp[]);

/*  
Divide el array a ordenar en subarrays y luego los combina, todo recursivamente
    Parámetro: 
        x: array a ordenar
        inicio: indice del primer elemento
        len: longitud del array o subarray
        
    Retorno: Ninguno

    Precondicion: len >= 0

    Complejidad Temporal: 
        T(n)=2T(n/2)+1
        O(n*logn)
    
    Complejidad Espacial: 
        M(1) = 1, M(n) = M(n/2) + 1
        O(n*logn)
        
*/
void ordenarMergeSort(int x[],int inicio,int len);

#endif