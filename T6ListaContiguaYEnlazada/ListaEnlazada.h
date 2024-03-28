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
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	Nodo* getNodo(int posicion);

public:

	/*  
	Crea una lista enlazada vacia
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	ListaEnlazada();

	/*  
	Devuelve el valor en la posicion pedida
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	int getValor(int posicion);

	/*  
	Modifica el valor de la posicion pedida
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	void setValor(int posicion, int nuevoValor);

	/*  
	Devuelve n
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	int getN(); 

	/*  
	Inserta elementos en la lista, el comportamiento varia dependiendo de donde se quiera insertar
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	void insertar (int posicion, int nuevoValor);

	/*  
	Elimina elementos de la lista, el comportamiento varia dependiendo de donde se quiera eliminar
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	void eliminar (int posicion);

	/*  
	Concatena la lista indicada como parámetro al final de nuestra lista
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	void concatenar(ListaEnlazada *listaAConcatenar);

	/*  
	Encontrar el indice del elemento a buscar
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	int buscar(int elementoABuscar);

	/*  
	Destructor
		Parámetro: 
			int incremento, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	~ListaEnlazada();
};







