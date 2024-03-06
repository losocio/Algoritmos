#include <iostream>
#include "mergesort.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void combinar(int a[], int len_a, int b[], int len_b, int c[])
{
    /*Añadir código que permite combinar dos arrays */

    for()

    c[]
    //combinar tambien es recurrente
    combinar();

    return;
}

void ordenarMergeSort(const int x[],int inicio,int len) //TODO
{
    int temp[len];

    // Si la longitud es 1 (caso basico), salir de la recursion  
    if(len==1) return;
    else
    {
        // Calculo el nuevo punto de inicio de los subarrays
        int inicio1=inicio;
        int inicio2=inicio+(len/2);

        // Recurencia, divido en dos el array
        ordenarMergeSort(x,inicio1,len-len/2); // NOTE: si le paso len/2 dara error el los casos en el que se redondee la division
        ordenarMergeSort(x,inicio2,len/2);
        
        // TODO: Combinar ambas mitades y guardarlo en temp
        // TODO: al combinar elementos se necesitara un bucle para iterar distintas longitudes de array, ya que no seran iguales si el array tiene len inicial impar
        
        // NOTE: para el combinar se usan el array x que ha sido modifica por los ordenarMeger y las variables de inicio1 e inicio2 
        combinar(temp);
        combinar(); //TODO: creo que hay que combinar para cada sort
        //combinar(int a[], int len_a, int b[], int len_b, int c[])
        
        
        // Copiar del array temporal al array resultado y mostrarlo
        for(int k=0;k<len;k++)
	    {
            x[k]temp[k];
            cout<<x[k]<<" ";
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

