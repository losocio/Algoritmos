#include <iostream>
#include "Pila.h"
#include "assertdomjudge.h"
using namespace std;

// Algoritmo de torre de Hanoi
void Hanoi(int n, Pila *origen, Pila *destino, Pila *temporal) 
{
	// Implementacion copiada de los apuntes

	// NOTE: Si empieza por 0 da NO-OUTPUT creo
	assertdomjudge(n>0);

	// Si se llega 0 se sale de la recursion
	if(n>0)
	{
		// Recursividad
		Hanoi(n-1, origen, temporal, destino);

		// Mover de origen a destino
		destino->apilar(origen->desapilar());

		// Recursividad
		Hanoi(n-1, temporal, destino, origen);
	}

	return;
}


int main()
{  
	Pila *A=new Pila("A");
	Pila *B=new Pila("B");
	Pila *C=new Pila("C");

	int n;
	cin>>n;

	for(int i=n;i>0;i--) A->apilar(i);

	Hanoi(n,A,C,B);
	
	for(int i=0;i<n;i++) C->desapilar();

	return 0;
}

