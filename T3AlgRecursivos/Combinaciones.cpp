#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

/*  
Producto una matriz por matriz 
    Parámetro: Dos matrices
    Retorno: una nueva matriz con el resultado.
    Precondicion: La matriz debe exsistir y las
    filas_m1 == columnas_m2 && columnas_m1 == filas_m2
    Complejidad Temporal: O(n_filas*n_columnas)
    Complejidad Espacial: O(1)
*/
int factorial(int n){
    
    // Compruebo que el numero factorial es mayor que 0
    if(n<0) return -1;

    // Condicion se salida, si el factorial es de 0!
    if(n==0) return 1;
    
    // Si no estamos al funal del factorial se hace recurrencia
    return n*factorial(n-1);
}

int combinaciones(int n, int r){
    if(r>n) cout<<"ERROR"<<endl;

    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
    int n, r, i = 1;
    while(i){
        cin>>n;
        cin>>r;
        combinaciones(n, r)<<endl;
        if(;;){
            
        }
    }

    return 0;
}