#include "Combinaciones.h"
#include <iostream>
#include <stdlib.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Calcula el factorial
int factorial(int n){
    // Compruebo que el numero factorial es mayor que 0
    assertdomjudge(n>=0);

    // Condicion se salida, si el factorial es de 0!
    if(n==0) return 1;
    
    // Si no estamos al funal del factorial se hace recurrencia
    return n*factorial(n-1);
}

//Calcula el numero de combinaciones de n numeros en grupos de r
int combinaciones(int n, int r){
    // Compruebo si n es mayor o igual que r, sino no se puede hacer la 
    assertdomjudge(n>=r);

    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
    int n, r;
    
    //Bucle para que se repita hasta cometer un error
    while(true){
        cin>>n;
        cin>>r;

        if(n<0) break;

        if(n<r) cout<<"ERROR";
        else cout<<combinaciones(n, r)<<endl;
    }

    return 0;
}