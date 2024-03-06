#include <iostream>
#include "mergesort.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void combinar(int x[],int inicioIzquierda,int lenIzquierda,int inicioDerecha,int lenDerecha,int temp[])
{
    // NOTE: Se comparan los elementos de indice mas pequeño de cada lista a combinar y se coge el menor, eliminandolo de la lista.
    // NOTE: Esto se repite hasta colocar todos los elementos

    int len = lenIzquierda+lenDerecha;
    int contadorIzquierda=0,contadorDerecha=0;
    
    for(int o=inicioIzquierda;o<lenIzquierda;o++) cout<<x[o]<<" ";
    cout<<endl<<endl;
    for(int e=inicioDerecha;e<lenDerecha;e++) cout<<x[e]<<" ";

    // FIXME: Aqui esta el error
    for(int i=0;i<len;i++)
    {
        if(x[inicioIzquierda+contadorIzquierda]<=x[inicioDerecha+contadorDerecha]) // NOTE: Puede haber valores iguales en el array
        {
            temp[i]=x[inicioIzquierda]; 
            
            // TODO: Puede que aunque use este if() este leyendo fuera del subarray, cuando asigne el ultimo elemento de un subarray el contador NO debe aumentar
            if(contadorIzquierda<lenIzquierda-1) contadorIzquierda++; // TODO: Hay que comprobar que no accedo a valores fuera del subarray, habra que pasarle a la funcion la longitud de los dos sub arrays para hacer if()

        }
        else
        {
            temp[i]=x[inicioDerecha];
            
            if(contadorDerecha<lenDerecha-1) contadorDerecha++;
        }
    }

    
    //combinar(); //NOTE: Combinar tambien es recurrente, pero no tiene que llamarse aqui, se llama al salir de ordenarMergeSort()

    return;
}

void ordenarMergeSort(int x[],int inicio,int len) //TODO
{
    int temp[len]; // NOTE: este array esta pensado en el enunciado para que len sea constante y se limiten los subarrays con inicio y fin, no modificando len

    // Si la longitud es 1 (caso basico), salir de la recursion  
    if(len==1) {
        //cout<<x[inicio]<<endl;
        return;
    }
    else
    {
        // Calculo el nuevo punto de inicio de los subarrays
        // FIXED: Por una razon que no termino de comprender, si cambio cual de los dos usa len-len/2 funciona bien
        int inicioIzquierda=inicio;
        int lenIzquierda=len/2; //len-len/2;

        int inicioDerecha=inicio+len/2;
        int lenDerecha=len-len/2; //len/2;

        // Recurencia, divido en dos el array
        // FIXED: Al cambiar cual de los len usa len-len/2 funciona
        ordenarMergeSort(x,inicioIzquierda,lenIzquierda); // NOTE: si le paso len/2 dara error el los casos en el que se redondee la division
        ordenarMergeSort(x,inicioDerecha,lenDerecha);
        
        // TODO: Combinar ambas mitades y guardarlo en temp
        
        // NOTE: para el combinar se usan el array x que ha sido modifica por los ordenarMeger y las variables de inicioIzquierda e inicioDerecha 
        combinar(x,inicioIzquierda,lenIzquierda,inicioDerecha,lenDerecha,temp);
        //combinar(); //NOTE: No se necesitan dos combinar()
        
        
        // Copiar del array temporal al array resultado y mostrarlo
        for(int k=0;k<len;k++) // FIX: Esto viene mal ya que se recorre todo el array y solo hay que sustituir algunos elementos
	    {
            x[inicio]=temp[k]; // NOTE: Indice de x[] no es k, se colocarian mal los valores ordenados
            //cout<<x[inicio]<<" ";
            inicio++;
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
    ordenarMergeSort(x,0,n);

    return 0;
}

