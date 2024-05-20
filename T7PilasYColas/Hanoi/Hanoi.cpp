#include <iostream>
#include "Pila.h"
#include "assertdomjudge.h"

using namespace std;

// Algoritmo de torre de Hanoi
void Hanoi(int n, Pila *origen, Pila *destino, Pila *temporal) 
{
	// Implementacion copiada de los apuntes

	// FIXED: La precondicion se tiene que poner en el main
	// El numero de discos no puede ser negativo
	// assertdomjudge(n>0);

	// Si se llega 0 se sale de la recursion
	if(n==0) return;
	
	// Recursividad
	Hanoi(n-1, origen, temporal, destino);

	// Mover de origen a destino
	destino->apilar(origen->desapilar());

	// Recursividad
	Hanoi(n-1, temporal, destino, origen);
}

int main()
{  
	Pila *A=new Pila("A");
	Pila *B=new Pila("B");
	Pila *C=new Pila("C");

	// Numero de discos
	int n;
	cin>>n;

	// La cantidad de discos debe de ser mayor que 0
	assertdomjudge(n>0);

	// Apilo n discos en A
	for(int i=n; i>0; i--) A->apilar(i);

	// Paso los n discos de A a C usando B auxiliarmente
	Hanoi(n, A, C, B);
	
	// Desapilo n discos de C
	for(int i=0; i<n; i++) C->desapilar();

	delete A;
	delete B;
	delete C;

	return 0;
}

