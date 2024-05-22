#include "ColaPrioridad.h"

class Supermercado
{
private:

	// Vector de todas la cajas
	ColaPrioridad *cajas;

	// Numero de cajas
	int n_cajas;

public:
	/*  
	Contructor
		Parámetro: 
			int n, numero total de cajas

		Retorno: 
			Ninguno
		
		Precondicion: 
			n > 0
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = n
			O(n)
	*/
	Supermercado(int n);

	/*  
	Añade un nuevo usuario a una caja
		Parámetro: 
			int n, numero de caja
			int id, id del usuario. El orden en el que se añaden

		Retorno: 
			Ninguno
		
		Precondicion: 
			n >= 0
			n < n_cajas
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
	void nuevoUsuario(int n, int id);

	/*  
	Cerrar una caja, recolocando a sus usuarios
		Parámetro: 
			int n, numero de caja

		Retorno: 
			Ninguno
		
		Precondicion: 
			n >= 0
			n < n_cajas
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/  
	void cerrarCaja(int n);  

	/*  
	Atiende un usuario, sacandolo de la caja
		Parámetro: 
			int n, numero de caja 

		Retorno: 
			int usuario, id del usuario
		
		Precondicion: 
			n >= 0
			n < n_cajas
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	int atenderUsuario(int n);

	/*  
	Comprueba si la caja esta vacia
		Parámetro: 
			int n, numero de la caja

		Retorno: 
			bool estaVacia
		
		Precondicion: 
			n >= 0
			n < n_cajas
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	bool cajaVacia(int n);
};
