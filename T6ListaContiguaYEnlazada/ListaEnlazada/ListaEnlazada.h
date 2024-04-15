#pragma once
#include "Nodo.h"
#include "assertdomjudge.h"

class ListaEnlazada
{
	// Comienzo de la lista
	Nodo* lista;

	// Cantidad de nodos
	int n;

	/*  
	Devuelve puntero al nodo en la posicion solicitada
		Parámetro: 
			int posicion, posicion del nodo a devolver

		Retorno: 
			Nodo* nodoIterar, nodo en la posicion solicitada
		
		Precondicion: 
			posicion >= 0 
			posicion < n
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	Nodo* getNodo(int posicion);

public:

	/*  
	Crea una lista enlazada vacia
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	ListaEnlazada();

	/*  
	Devuelve el valor en la posicion pedida
		Parámetro: 
			int posicion, posicion del valor a devolver

		Retorno: 
			valor de la posicion dada
		
		Precondicion: 
			posicion >= 0 
			posicion < n
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int getValor(int posicion);

	/*  
	Modifica el valor de la posicion pedida
		Parámetro: 
			int posicion, posicion del valor a modificar
			int nuevoValor, nuevo valor

		Retorno: 
			Ninguno
		
		Precondicion: 
			posicion >= 0 
			posicion < n
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void setValor(int posicion, int nuevoValor);

	/*  
	Devuelve n
		Parámetro: 
			Ninguno

		Retorno: 
			int n, n
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int getN(); 

	/*  
	Inserta elementos en la lista, el comportamiento varia dependiendo de donde se quiera insertar
		Parámetro: 
			int posicion, posicion donde insertar el nuevo nodo
			int nuevoValor, nuevo valor

		Retorno: 
			Ninguno
		
		Precondicion: 
			posicion >= 0 
			posicion <= n
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void insertar(int posicion, int nuevoValor);

	/*  
	Elimina elementos de la lista, el comportamiento varia dependiendo de donde se quiera eliminar
		Parámetro: 
			int posicion, posicion del nodo a eliminar

		Retorno: 
			Ninguno
		
		Precondicion: 
			posicion >= 0 
			posicion < n
		
		Complejidad Temporal:
			T(n) = 2*n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void eliminar(int posicion);

	/*  
	Concatena la lista indicada como parámetro al final de nuestra lista
		Parámetro: 
			ListaEnlazada *listaAConcatenar, lista que concatenar al final

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void concatenar(ListaEnlazada *listaAConcatenar);

	/*  
	Encontrar el indice del elemento a buscar
		Parámetro: 
			int elementoABuscar, valor a buscar

		Retorno: 
			int indiceEncontrado, posicion donde del valor encontrado, -1 a su defecto
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int buscar(int elementoABuscar);

	/*  
	Destructor
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = n + 1
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	~ListaEnlazada();
};







