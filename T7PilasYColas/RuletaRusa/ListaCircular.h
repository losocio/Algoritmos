#include <cstdlib>
#include "Nodo.h"
#include "assertdomjudge.h"

class ListaCircular
{
	Nodo *lista;

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
	Crea una lista vacia
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
	ListaCircular();

	/*  
	Devuelve el valor en la posicion pedida
		Parámetro: 
			int posicion, posicion del valor a devolver 

		Retorno: 
			string elemento, elemento contenido en la posicion
		
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
	string getValor(int posicion);

	/*  
	Modifica el valor de la posicion pedida
		Parámetro: 
			int posicion, posicion del valor a modificar
			string nuevoValor, nuevo valor

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
	void setValor(int posicion, string nuevoValor);

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
	Inserta nodos en la lista, el comportamiento varia dependiendo de si se inserta el primer nodo
		Parámetro: 
			int posicion, posicion donde insertar el nuevo nodo
			string nuevoValor, nuevo valor

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
	void insertar(int posicion, string nuevoValor);

	/*  
	Elimina nodos de la lista, el comportamiento varia dependiendo de si se vacia la lista
		Parámetro: 
			int posicion, posicion del nodo a eliminar

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
	Girar el tambor, apunta la lista al siguiente nodo
		Parámetro: 
			int p, numero de nodo que iterar

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
	void girar(int p);

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
	~ListaCircular();
};







