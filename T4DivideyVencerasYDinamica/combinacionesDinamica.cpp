#include <iostream>
#include "combinacionesDinamica.h"
#include "combinaciones.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Calcula el numero de combinaciones de n numeros en grupos de r
int combinacionesDinamica(int n,int r)
{
    // Compruebo si n es mayor o igual que r, sino no se puede hacer la 
    assertdomjudge(n>=r);

    // Compruebo que n es menor que 10, ya que solo se generan soluciones para hasta combinaciones de 10 elementos
    assertdomjudge(n<10);

    // Creo la tabla de soluciones y la relleno
    int *soluciones[10];
    
    // Con matriz a medida
    for(int i=0;i<10;i++)
    {
        //Creo espacio para soluciones
        soluciones[i]=new int[i+1];
        
        // Relleno con la nueva fila con sus soluciones
        for(int j=0;j<i+1;j++)
        {   
            soluciones[i][j]=combinaciones(i,j);
        }
    }

    // Busco el la tabla de soluciones la combinacion pedida
    return soluciones[n][r];

    /*
    // Con matriz 10x10
    for(int i=0;i<10;i++)
    {
        soluciones[i]=new int[10];
        
        //TODO: Relleno con la solucion
        int val; 
         
        for(int j=0;j<=i;j++)// FIXED: con j<10 le pasaba valores n<r, algo no valido
        { 
            soluciones[i][j]=combinaciones(i,j); 
        }
        
        //cout<<endl;
    }
    */
}

int main()
{
    int n,r;

    //Bucle para que se repita hasta cometer un error
    while(true)
    {
        cin>>n;
        cin>>r;
        //FIXED: (si meto 0 0 no pasa de aqui) estaba pidiendo la entrada dos veces, fallaria con cualquie numero
        
        if(n<0) break;

        if(n<r) cout<<"ERROR"<<endl;
        else cout<<combinacionesDinamica(n,r)<<endl;
    }

    return 0;
}