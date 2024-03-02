#include <iostream>
#include "insercion.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void ordenarInsercion(int x[],int len)
{	
	// La longitud debe ser mayor o igual que 0
	assertdomjudge(len>=0);

	int desplazado, j;
	// Itero todo el array
  	for(int i=1;i<len;i++)
    {
		// Separo el elemento a ordenar
		desplazado = x[i];

		j = i-1;
		// Si el elemento anterior al que se ordena es mayor lo desplazo
		// Tambien termina el bucle si me saldria del array
		while(x[j]>desplazado && j>=0)
		{
			// Desplazo el elemento
			x[j+1] = x[j];
			j--;
		}
		
		// Pongo el elemento desplazado en su sitio
		x[j+1]=desplazado;

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

	ordenarInsercion(x,n);

	return 0;
}
