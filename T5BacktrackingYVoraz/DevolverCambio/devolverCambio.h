#ifndef DEVOLVERCAMBIO_H
#define DEVOLVERCAMBIO_H

using namespace std;

/*  
Devuelve las cantidades de las distintas monedas de pesetas necesarias para de cambio
    Parámetro: 
        int valor,  valor del que dar cambio
        int* cambio, referencia del array donde se guardan las cantidades de cambio

    Retorno: 
        Ninguno
    
    Precondicion: 
        valor >= 0
    
    Complejidad Temporal:
        T(n) = 
        O()

    Complejidad Espacial: 
        M(n) = 
        O()
*/
void devolverCambio(int valor, int* cambio);

#endif