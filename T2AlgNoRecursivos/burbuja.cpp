#include <iostream>
#include "burbuja.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

void ordenarBurbuja(int x[], int len)
{
	// La longitud debe ser mayor que 0
	assertdomjudge(len>0);

	int temp;
	// Una pasada del algoritmo por cada elemento de array
  	for(int i=1;i<len;i++)
    {
		// Recorrer los elementos para hacer la comprobacion y actuar en consecuencia
		// El recorrido disminuye cada iteracion, con cada iteracion se ordena un elemento
		for(int j=0; j<len-i; j++)
		{
			if(x[j]>x[j+1])
			{
				// Cambiar posiciones
				temp = x[j];
               	x[j] = x[j+1];
               	x[j+1] = temp;
			}
		}

		// Mostrar las iteraciones
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

 	ordenarBurbuja(x, n);

	return 0;
}
