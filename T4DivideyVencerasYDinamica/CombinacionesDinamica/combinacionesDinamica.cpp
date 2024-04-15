#include <iostream>
#include "combinacionesDinamica.h"
#include "combinaciones.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/* 
NOTE: Para niveles mas grandes no funciona bien
    Da valores incorrectos o "Floating point exception"
*/

// Precalcula las combinaciones de hasta 9 elementos
int** calcularCombinacionesDinamica(int nivel)
{
    // El triangulo no puede ser de tamaño negativo
    assertdomjudge(nivel>=0);

    // Creo la tabla de combinaciones y la relleno
    //int *tablaCombinaciones[10]; // NOTE: No entiendo del todo porque esto no es valido
    int** tablaCombinaciones = new int*[nivel];

    // Con matriz a medida
    for(int i=0;i<nivel;i++)
    {
        //Creo espacio para combinaciones
        tablaCombinaciones[i]=new int[i+1];
        
        // Relleno con la nueva fila con sus combinaciones
        for(int j=0;j<i+1;j++) tablaCombinaciones[i][j]=combinaciones(i,j);
    }

    // Busco el la tabla de combinaciones la combinacion pedida
    return tablaCombinaciones;
}

int main()
{
    int n,r;

    // Calculo las combinaciones hasta 9 elementos
    int** tablaCombinaciones = calcularCombinacionesDinamica(10);

    //Bucle para que se repita hasta cometer un error
    while(true)
    {
        cin>>n;
        cin>>r;
        //FIXED: (si meto 0 0 no pasa de aqui) estaba pidiendo la entrada dos veces, fallaria con cualquie numero
        
        if(n<0) break;

        if(n<r) cout<<"ERROR"<<endl;
        else cout<<tablaCombinaciones[n][r]<<endl;
    }

    return 0;
}