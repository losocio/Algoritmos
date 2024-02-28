#include <iostream>
#include "seleccion.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void ordenarSeleccion(int x[],int len)
{
	// La longitud debe ser mayor o igual que 0
	assertdomjudge(len>=0);

	int temp,indiceMinimo;

	// Itero por todo el array
  	for(int i=0;i<len;i++)
	{
		// 
		for(int j=i+1;j<len;j++)
		{
			// 
			//TODO esta mal ya que no se queda el indicel del mas pequeño sino el del ultimo mas pequeño
			if(x[j]<x[i] && x[j]<x[indiceMinimo]) indiceMinimo = j;
			
			//8 5 6 7 0 3 9 2 4 1
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