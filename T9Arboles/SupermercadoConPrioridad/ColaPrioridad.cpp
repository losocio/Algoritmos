#include "ColaPrioridad.h"
#include <iostream>
using namespace std;

// Min heap para colas de prioridad

// Encolo un elemento al final del heap
void ColaPrioridad::encolar(int nuevoElemento)
{
	// Inserto un elemento al final de la lista
	vector.insertarAlFinal(nuevoElemento);
	
	// Reestruturo el heap
	reestructurar(vector.getN()-1);

	return;
}

// Desencolo el elemento de la raiz, el menor
int ColaPrioridad::desencolar()
{
	// Cogo el valor de la raiz
	int valor = vector.getValor(0);

	// Sustituyo el primer elemento por el ultimo
	vector.setValor(0, vector.getValor(vector.getN()-1));

	// Elimino el ultimo elemento
	vector.eliminarAlFinal();
	
	// FIXED: le estaba pasando el valor y no el indice
	// reestructurar(valor);

	// Reestruturo el monticulo
	reestructurar(0);

	return valor;
}

// Comprueba si el heap esta vacio
bool ColaPrioridad::estaVacia()
{
	return vector.getN()==0;
}

/* 

NOTE: Me tomo la libertad de modificar el codigo del enunciado.
Ya que entiendo que reestructurar tiene que realizar tanto heapify up
como heapify down, en consecuencia necesito saber el indice del ultimo
elemento encolado/desencolado

*/

// Reestructura el heap, dependiendo del indice del ultimo elemento actializado hace heapify down o heapify up
void ColaPrioridad::reestructurar(int i)
{
	/*
	Hijo I: 2*i+1
	Hijo D: 2*i+2
	Padre: (i-2)/2
	*/

	// Si el elemento es la raiz (desencolar), heapify down
	if(i==0)
	{
		int size = vector.getN();
		while(true) 
		{
			int indiceHijoIzquierdo = 2 * i + 1;
			int indiceHijoDerecho = 2 * i + 2;
			int indiceHijoMenor = i;

			// Encontrar el menor entre i, indiceHijoIzquierdo y indiceHijoDerecho
			if(indiceHijoIzquierdo < size && vector.getValor(indiceHijoIzquierdo) < vector.getValor(indiceHijoMenor))
			{
				indiceHijoMenor = indiceHijoIzquierdo;
			}

			if(indiceHijoDerecho < size && vector.getValor(indiceHijoDerecho) < vector.getValor(indiceHijoMenor))
			{
				indiceHijoMenor = indiceHijoDerecho;
			}

			// Si indiceHijoMenor no es i intercambiar y continuar
			if(indiceHijoMenor != i)
			{
				int aux = vector.getValor(i);
				vector.setValor(i, vector.getValor(indiceHijoMenor));
				vector.setValor(indiceHijoMenor, aux);

				i = indiceHijoMenor;
			} 
			else 
			{
				break;
			}
    	}
	}
	// Si el elemento es cualquier otro (encolar), heapify down
	else
	{
		while (i > 0) {
			int indicePadre = (i - 1) / 2;

			// Si el valor actual es menor que el valor del padre, intercambiarlos
			if (vector.getValor(i) < vector.getValor(indicePadre)) {
				int aux = vector.getValor(i);
				vector.setValor(i, vector.getValor(indicePadre));
				vector.setValor(indicePadre, aux);

				// Mover el índice hacia arriba
				i = indicePadre;
			} else {
				break;
			}
		}
		
	}
}
	
	/*
	// un while porque no se sabe hasta cuando es el recorrido
	int i=0;
	while()
	{
		int indiceHijoMenor;
		if(getHijoDerecho(i) < getHijoDerecho(i)) 
		{
			indiceHijoMenor=getIndiceHijoDerecho(i);
		}
		else
		{
			indiceHijoMenor=getIndiceHijoIzquierdo(i);
		}
	}
	*/
	
	/*
	// NOTE: solo es un bubble sort, no la implementacion ideal
	// Con esto tambien se consigue que el elemento raiz sea el minimo, pero no es un heap real
	for(int i=0; i<vector.getN()-1; i++)
	{
		for(int j=0; j<(vector.getN()-i)-1; j++)
		{
			if(vector.getValor(j) > vector.getValor(j+1))
			{
				// Intercambio dos elementos
				int aux = vector.getValor(j);
				vector.setValor(j, vector.getValor(j+1));
				vector.setValor(j+1, aux);
			}
		}	
	}

	return;
	*/