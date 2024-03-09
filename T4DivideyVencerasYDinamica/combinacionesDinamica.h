#ifndef COMBINACIONESDINAMICA_H
#define COMBINACIONESDINAMICA_H

using namespace std;

/*  
Calculo de combinaciones mediante programacion dinamica
    Parámetro: nivel, niveles a calcular del triangulo de Pascal

    Retorno: Matriz con las combinaciones
    
    Precondicion: nivel >= 0
    
    Complejidad Temporal:
        T(n) = (6 + c) 3^(n - 1) - 2 
        O()

    Complejidad Espacial: 
        M(n) = 
        O()
*/
int** calcularCombinacionesDinamica(int nivel);

#endif