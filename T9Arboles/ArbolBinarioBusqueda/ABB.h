#pragma once
#include "Nodo.h"

/*
	NOTE: No me da tiempo ha hacerte los comentarios tan
	limpios y bonitos que te he hecho hasta ahora :(
*/

// ABB
class ABB
{
	// Arbol
	Nodo *raiz; 

	// Numero de nodes del arbol
	int n; 
public:

	// Constructor
	ABB();

	// Insertar un nuevo elemento en el arbol
	void insertar (int nuevoElemento);

	// Buscar un nodo con un elemento especifico en el arbol
	Nodo *buscar(int elementoABuscar);

	// Eliminar un elemento del arbol
	void eliminar (int elementoAEliminar);

	// Imprimir el arbol
	void imprimir();

	// Verificar si el arbol es un ABB
	bool esABB();

	// Verificar si el arbol es un AVL
	bool esAVL();

	// Leer un arbol desde la entrada estandar
	void leerArbol();

	// Destructor
	~ABB();

protected:

	// Eliminar un subarbol a partir de una raiz dada
	void eliminarSubarbol(Nodo *raizSubarbol);

	// Encontrar el lugar adecuado para insertar un nuevo elemento
	Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);

	// Buscar recursivamente un elemento en el arbol
	Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar);

	// Encontrar el nodo con el valor maximo en un subarbol
	Nodo *buscarMaximo (Nodo *raizSubarbol);

	// Encontrar el nodo con el valor minimo en un subarbol
	Nodo *buscarMinimo (Nodo *raizSubarbol);

	// Eliminar un nodo especifico en el arbol
	void eliminarNodo (Nodo *nodoParaEliminar);

	// Calcular la altura de un nodo
	int alturaNodo(Nodo *raizSubarbol);

	// Imprimir el recorrido del arbol
	void imprimirRecorrido(Nodo *raizSubarbol);

	// Verificar si un subarbol es un ABB
	bool esSubABB(Nodo *raizSubarbol);

	// Verificar si un subarbol es AVL
	bool esSubAVL(Nodo *raizSubarbol);

	// Leer un subarbol desde la entrada estandar
	Nodo *leerSubarbol(Nodo *padre);	
};

