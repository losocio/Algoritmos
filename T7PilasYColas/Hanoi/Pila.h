#include"Nodo.h"
#include<string>
#include<iostream>
using namespace std;

class Pila
{
private:
	// Nodo con el elemento superior de la pila
    Nodo *cima;

	// Nombre de la pila
    string name;

public:
	/*  
	Constructor
		Parámetro: 
			string name, nombre para la nueva pila

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	Pila(string name);

	/*  
	Devuleve el nombre de la pila
		Parámetro: 
			Ninguno

		Retorno: 
			string nombre, nombre de la pila
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
	string nombrePila();

	/*  
	Introducir un elemento a la parte superior de la pila, push
		Parámetro: 
			int num, valor a introducir en la pila

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	void apilar(int num);

	/*  
	Sacar un elemento a la parte superior de la pila, pop
		Parámetro: 
			Ninguno

		Retorno: 
			int elemento, elemento desapilado
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	int desapilar();

	/*  
	Devuelve booleano segun si esta vacia la lista
		Parámetro: 
			Ninguno

		Retorno: 
			bool isVacia, si la lista esta o no vacia
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) =  
			O()
	*/
	bool estaVacia();
};

  
