#include "Cola.h"
#include "assertdomjudge.h"

class Supermercado
{
private:
	Cola *cajas;
	int n_cajas;

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
	Supermercado(int n);

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
	void nuevoUsuario(int n,int id);  

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
	void cerrarCaja(int n);  
	
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
	int atenderUsuario(int n);

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
	bool cajaVacia(int n);
};
