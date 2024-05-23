#include <iostream>
#include "seleccion.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

// Ordenacion por seleccion, ordena un array de enteros
void ordenarSeleccion(int x[],int len)
{
	// La longitud debe ser mayor o igual que 0
	assertdomjudge(len>=0);

	int temp,minimo,indiceMinimo;

	// Itero por todo el array
  	for(int i=0;i<len;i++)
	{
		indiceMinimo=i;
		// Para cada elemento comparado
		for(int j=i+1;j<len;j++)
		{
			// Si la iteracion actual es menor que en valor anterior, guardo su indice
			if(x[j]<x[indiceMinimo]) indiceMinimo = j; // NOTE: esto seria siempre constante T(n)=1
		}

		// Intercambio el menor por el valor de la iteracion actual
		temp=x[i];
		x[i]=x[indiceMinimo];
		x[indiceMinimo]=temp;
		
		// Mostrar cada iteracion
		for(int k=0;k<len;k++) cout<<x[k]<<" ";
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

	ordenarSeleccion(x,n);

	return 0;
}