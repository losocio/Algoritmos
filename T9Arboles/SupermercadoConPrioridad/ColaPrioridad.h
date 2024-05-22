#pragma once
#include "ListaContigua.h"
#include "assertdomjudge.h"

// Clase que implementa una cola con prioridad mediante un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes) e implementado sobre una lista contigua
// Min heap para colas de prioridad
class ColaPrioridad
{
protected:

	// Lista que contien el min heap
	ListaContigua vector; 

public:
	/*  
	Encolo un elemento al final del heap
		Parámetro: 
			int nuevoElemento, nuevo elemento del heap

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void encolar(int nuevoElemento);

	/*  
	Desencolo el elemento de la raiz, el menor
		Parámetro: 
			Ninguno

		Retorno: 
			int valor, valor desencolado
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
	int desencolar();

	/*  
	Comprueba si el heap esta vacio
		Parámetro: 
			Ninguno 

		Retorno: 
			bool estaVacia
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	bool estaVacia();


protected:
	/* 

	NOTE: Me tomo la libertad de modificar el codigo del enunciado.
	Ya que entiendo que reestructurar tiene que realizar tanto heapify up
	como heapify down, en consecuencia necesito saber el indice del ultimo
	elemento encolado/desencolado

	*/

	/*  
	Reestructura el heap
		Parámetro: 
			int i, indice del elemento

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void reestructurar(int i);
};


//private:
//	/*  
//	Devuelve el valor del hijo izquierdo
//		Parámetro: 
//			int i, indice del padre
//
//		Retorno: 
//			int indiceHijoIzquierdo, indice del hijo izquierdo
//		
//		Precondicion: 
//			i >= 0
//		
//		Complejidad Temporal:
//			T(n) = 1
//			O(1)
//
//		Complejidad Espacial: 
//			M(n) = 1
//			O(1)
//	*/
//	int getIndiceHijoIzquierdo(int i);
//
//	/*  
//	Devuelve el valor del hijo derecho
//		Parámetro: 
//			int i, indice del padre
//
//		Retorno: 
//			int indiceHijoDerecho, indice del hijo derecho
//		
//		Precondicion: 
//			i >= 0
//		
//		Complejidad Temporal:
//			T(n) = 1
//			O(1)
//
//		Complejidad Espacial: 
//			M(n) = 1
//			O(1)
//	*/
//	int getIndiceHijoDerecho(int i);
//
//	/*  
//	Devuelve el valor del hijo izquierdo
//		Parámetro: 
//			int i, indice del padre
//
//		Retorno: 
//			int hijoIzquierdo, valor del hijo izquierdo
//		
//		Precondicion: 
//			i >= 0
//		
//		Complejidad Temporal:
//			T(n) = 1
//			O(1)
//
//		Complejidad Espacial: 
//			M(n) = 1
//			O(1)
//	*/
//	int getHijoIzquierdo(int i);
//
//	/*  
//	Devuelve el valor del hijo derecho
//		Parámetro: 
//			int i, indice del padre
//
//		Retorno: 
//			int hijoDerecho, valor del hijo derecho
//		
//		Precondicion: 
//			i >= 0
//		
//		Complejidad Temporal:
//			T(n) = 1
//			O(1)
//
//		Complejidad Espacial: 
//			M(n) = 1
//			O(1)
//	*/
//	int getHijoDerecho(int i);
//	