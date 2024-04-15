#include <iostream>
#include "mergesort.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

// Combina dos array ordenados en uno nuevo tambien ordenado
void combinar(int x[],int inicioIzquierda,int lenIzquierda,int inicioDerecha,int lenDerecha,int temp[])
{
    // La longitud debe ser mayor o igual que 0
	assertdomjudge(lenIzquierda>=0);
    
    // La longitud debe ser mayor o igual que 0
	assertdomjudge(lenDerecha>=0);

    // NOTE: Se comparan los elementos de indice mas pequeño de cada lista a combinar y se coge el menor, eliminandolo de la lista.
    // NOTE: Esto se repite hasta colocar todos los elementos

    // Defino contadores y la longitud total al juntar los dos subarrays
    int lenTemp = lenIzquierda+lenDerecha;
    int contadorIzquierda=0,contadorDerecha=0;

    // Bucle que rellena el array ordenado 
    for(int i=0;i<lenTemp;i++)
    {
        // Nunca en mil años llegaria a deducir esto por mi cuenta
        // En cada iteracion elige el menor elemento de los dos arrays ordenados
        if((x[inicioIzquierda+contadorIzquierda]<=x[inicioDerecha+contadorDerecha] || contadorDerecha>=lenDerecha) && contadorIzquierda<lenIzquierda)
        {
            temp[i]=x[inicioIzquierda+contadorIzquierda];
            contadorIzquierda++;
        }
        else
        {
            temp[i]=x[inicioDerecha+contadorDerecha];
            contadorDerecha++;
        }
    }

    //combinar(); //NOTE: Combinar tambien es recurrente, pero no tiene que llamarse aqui, se llama al salir de ordenarMergeSort()

    return;
}

// NOTE: se pueden pasar referencias a la mitad del array


// Divide el array a ordenar en subarrays y luego los combina, todo recursivamente
void ordenarMergeSort(int x[],int inicio,int len) //TODO
{
    // La longitud debe ser mayor o igual que 0
	assertdomjudge(len>=0);

    int temp[len]; // NOTE: este array esta pensado en el enunciado para que len sea constante y se limiten los subarrays con inicio y fin, no modificando len

    // Si la longitud es 1 (caso basico), salir de la recursion  
    if(len==1) return;
    else
    {
        // Calculo el nuevo punto de inicio de los subarrays
        // FIXED: Por una razon que no termino de comprender, si cambio cual de los dos usa len-len/2 funciona bien
        int inicioIzquierda=inicio;
        int lenIzquierda=len/2;

        int inicioDerecha=inicio+len/2;
        int lenDerecha=len-len/2;

        // Recurencia, divido en dos el array
        // FIXED: Al cambiar cual de los len usa len-len/2 funciona
        ordenarMergeSort(x,inicioIzquierda,lenIzquierda); // NOTE: si le paso len/2 dara error el los casos en el que se redondee la division
        ordenarMergeSort(x,inicioDerecha,lenDerecha);
        
        // Al salir de la primera recursion se combinan los elementos ordenados
        // NOTE: para el combinar se usan el array x que ha sido modifica por los ordenarMeger y las variables de inicioIzquierda e inicioDerecha 
        combinar(x,inicioIzquierda,lenIzquierda,inicioDerecha,lenDerecha,temp);
        
        //combinar(); //NOTE: No se necesitan dos combinar()
        
        // Copiar del array temporal al array resultado y mostrarlo
        for(int k=0;k<len;k++)
	    {
            x[inicio+k]=temp[k]; // NOTE: Indice de x[] no es k, se colocarian mal los valores ordenados
            cout<<x[inicio+k]<<" ";
	    }
        cout<<endl;
    }

    return;
}

int main()
{
    int n;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++) cin>>x[i];

    int *temp=new int[n];

    // Ordeno el array
    ordenarMergeSort(x,0,n);

    return 0;
}

