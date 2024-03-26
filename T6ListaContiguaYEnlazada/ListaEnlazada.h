#pragma once
#include "Nodo.h"
#include "assertdomjudge.h"

class ListaEnlazada
{
	Nodo *lista;

	int n;

	Nodo* getNodo(int posicion);

public:

	/*  
	ttt
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
	ttt
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
	ttt
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
	ttt
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
	ttt
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
	ttt
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
	ttt
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
	ttt
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
	ttt
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







