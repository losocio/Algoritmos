#ifndef SELECCION_H
#define SELECCION_H

using namespace std;

/* 
Ordenacion por seleccion, ordena un array de enteros
    Parámetro: Array de int y su longitud
    Retorno: Ninguno
    Precondicion: longitud >= 0
    
    Complejidad Temporal: 
        T(n)=n²/2+3n/2+1
        O(n²)
    
    Complejidad Espacial: 
        M(n)=5*4=20bytes
        O(1)
*/
void ordenarSeleccion(int x[],int len);

#endif