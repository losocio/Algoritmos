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


void ordenarMergeSort(int x[], int len) //TODO
{
    int temp[len];
    if(len==1){ // Si el len es el tamaño basico, 1 seguramente
        /*caso básico */
        // llamar al combinar
        combinar();
        return;
    } 
    else
    {
        /*Ordenar dos mitades */

        //TODO calcular la mitad dependiendo del len de entrada
        
        //Recurencia
        ordenarMergeSort(x, len/2);
        ordenarMergeSort(x, len/2);
        
        /*Combinar ambas mitades y guardarlo en temp */
        //Combinar
        combinar();
        
        // Copiar del array temporal al array resultado y mostrarlo
        for(int k = 0; k < len; k++)
	    {
            x[k] = temp[k];
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
    ordenarMergeSort(x,n);

    return 0;
}

