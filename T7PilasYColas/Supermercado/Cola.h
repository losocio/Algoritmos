#include "Nodo.h"
#include "assertdomjudge.h"

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
			T(n) = n + 1
			O(n)

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
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	void encolar(int num);  

	/*  
	Extraer el primer nodo de la cola
		Parámetro: 
			Ninguno

		Retorno: 
			int valorDesencolado, valor desencolado
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int desencolar();

	/*  
	Devuelve si esta vacia la cola
		Parámetro: 
			Ninguno

		Retorno: 
			bool estaVacia
		
		Precondicion: 
			incremento > 0
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	bool estaVacia();  
};

  
