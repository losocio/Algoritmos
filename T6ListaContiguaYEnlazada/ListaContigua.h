#pragma once
#include <cstring>
#include <cstdlib>
#include "assertdomjudge.h"

class ListaContigua
{
	// Array
	int *vector;

	// Numero de elementos
	int n;

	// Total de memoria que ocupa la lista, incluidos espacios sin valor asignado
	int capacidad;

	// Incremento
	int incremento;


public:

	/*  
	Constructor de ListaContigua
		Parámetro: 
			int incremento, tamaño del incremento para operaciones de redimensionamiento

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1 
			O(1)
	*/
	ListaContigua(int incremento);

	/*  
	Leer un valor segun su indice
		Parámetro: 
			int posicion, posicion donde leer

		Retorno: 
			int vector[posicion], la posicion pedida
		
		Precondicion: 
			posicion >= 0
			posicion < n
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int getValor(int posicion);

	/*  
	Cambia un valor segun su posicion, perdiendo lo que se guardaba ahi
		Parámetro: 
			int posicion, posicion a modificar
			int nuevoValor, nuevo valor

		Retorno: 
			Ninguno
		
		Precondicion: 
			posicion >= 0
			posicion < n
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1 
			O(1)
	*/
	void setValor(int posicion, int nuevoValor);

	/*  
	Devuelve la cantidad de elementos contenidos en la lista
		Parámetro: 
			Ninguno

		Retorno: 
			int n, cantidad de elementos
		
		Precondicion: 
			Ninguna
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int getN(); 

	/*  
	Devuelve la capacidad actual de la lista
		Parámetro: 
			Ninguno

		Retorno: 
			int capacidad, capacidad actual de la lista
		
		Precondicion: 
			Ninguna
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int getCapacidad(); 

	/*  
	Insertar un valor en la lista en la posicion elegida, desplazando los elementos de la derecha a la derecha
		Parámetro: 
			int posicion, posicion a modificar
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
	Eliminar un elemento de la posicion elegida de la lista
		Parámetro: 
			int posicion, posicion a eliminar

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
	void eliminar(int posicion);

	/*  
	Concatena dos listas
		Parámetro: 
			ListaContigua *listaAConcatenar, lisca que se concatenara al final

		Retorno: 
			Ninguno
		
		Precondicion: 
			listaAConcatenar->n >= 0
		
		Complejidad Temporal:
			T(m) = m + 1
			O(m)

		Complejidad Espacial: 
			M(m) = m
			O(m)
	*/
	void concatenar(ListaContigua *listaAConcatenar);

	/*  
	Encontrar el indice del elemento a buscar
		Parámetro: 
			int elementoABuscar, elemento a buscar

		Retorno: 
			indiceEncontrado, indice del elemento encontrado
		
		Precondicion: 
			Ninguna
		
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
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	~ListaContigua();
};








