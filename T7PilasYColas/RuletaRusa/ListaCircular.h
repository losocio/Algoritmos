#include<cstdlib>
#include "Nodo.h"

class ListaCircular
{
	Nodo *lista;

	int n;

	Nodo * getNodo (int posicion);

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
	ListaCircular();

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
	string getValor(int posicion);

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
	void setValor(int posicion, string nuevoValor);

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
	void insertar (int posicion, string nuevoValor);

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
	void girar (int p);

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
	~ListaCircular();
};







