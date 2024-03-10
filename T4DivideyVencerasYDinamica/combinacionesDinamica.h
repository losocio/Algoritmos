#ifndef COMBINACIONESDINAMICA_H
#define COMBINACIONESDINAMICA_H

using namespace std;

/*  
Calculo de combinaciones mediante programacion dinamica
    Parámetro: nivel, niveles a calcular del triangulo de Pascal

    Retorno: Matriz con las combinaciones
    
    Precondicion: nivel >= 0
    
    Complejidad Temporal:
        T(n) = n³/2 + 3n²/2 + 3n
        O(n³)

    Complejidad Espacial: 
        M(n) = n²/2 + 3n/2 + 1
        O(n²)
*/
int** calcularCombinacionesDinamica(int nivel);

#endif