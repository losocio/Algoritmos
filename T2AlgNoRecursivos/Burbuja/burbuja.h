#ifndef BURBUJA_H
#define BURBUJA_H

using namespace std;

/* 
Ordenacion por burbuja, ordena un array de enteros
    Parámetro: Array de int y su longitud
    Retorno: Ninguno
    Precondicion: longitud >= 0
    
    Complejidad Temporal: 
        T(n)= n²/2+n/2+1
        O(n²)
    
    Complejidad Espacial: 
        M(n)=3*4=12bytes
        O(1)
*/
void ordenarBurbuja(int x[], int len);

#endif