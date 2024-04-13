#include "Nodo.h"

class Cola
{
private:
	Nodo *principio;
	Nodo *final;

public:
	/*  
	Constructor
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
	Cola();

	/*  
	Añadir un nuevo nodo al final de la cola
		Parámetro: 
			int num, valor del nodo

		Retorno: 
			Ninguno
		
		Precondicion: 
			num >= 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
	void encolar(int num);  

	/*  
	Extraer el primer nodo de la cola
		Parámetro: 
			Ninguno

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
	int desencolar();

	/*  
	Devuelve si esta vacia la cola
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
	bool estaVacia();  
};

  
