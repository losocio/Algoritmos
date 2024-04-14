#include "Cola.h"
#include "assertdomjudge.h"

class Supermercado
{
private:
	Cola *cajas;
	int n_cajas;

public:
	/*  
	Constructor, reserva n cajas
		Parámetro: 
			int n, numero de cajas a crear 

		Retorno: 
			Ninguno
		
		Precondicion: 
			n > 0
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = n + 1
			O(n)
	*/
	Supermercado(int n);

	/*  
	Añade un usuario nuevo a la caja elegida
		Parámetro: 
			int n, numero de caja donde insertar
			int id, valor del usuario

		Retorno: 
			Ninguno
		
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
	void nuevoUsuario(int n,int id);  

	/*  
	Reparte los usuarios encolados en la caja a cerrar entre el resto de cajas
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
	Desencola un usuario
		Parámetro: 
			int n, numero de caja

		Retorno: 
			int valor, valor del ususario
		
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
	int atenderUsuario(int n);

	/*  
	Comprueba si esta vacia la caja n
		Parámetro: 
			int n, numero de caja

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
