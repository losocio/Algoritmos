#include <iostream>
#include <stdlib.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

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
    assertdomjudge(n>=0);

    // Condicion se salida, si el factorial es de 0!
    if(n==0) return 1;
    
    // Si no estamos al funal del factorial se hace recurrencia
    return n*factorial(n-1);
}

/*  

    Parámetro: 
    Retorno: 
    Precondicion: 
    Complejidad Temporal: O()
    Complejidad Espacial: O()
*/
int combinaciones(int n, int r){
    // Compruebo si n es mayor o igual que r, sino no se puede hacer la 
    assertdomjudge(n>=r);

    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
    int n, r;
    while(true){
        cin>>n;
        cin>>r;
        if(n<0) break;
        //if(n<r && n>=0) cout<<"ERROR";
        if(n<r) cout<<"ERROR";
        else cout<<combinaciones(n, r)<<endl;
    }

    return 0;
}