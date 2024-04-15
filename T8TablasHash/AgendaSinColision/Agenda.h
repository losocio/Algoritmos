#include "assertdomjudge.h"
#include  <string>

class Agenda
{
private:
    // Capacidad de elementos de la lista hash
    int capacidad;
    
    // Array de los nombres, los valores en ente caso
    string* nombres;
    
    // Array de los telefonos, las claves en este caso
    long* telefonos;

    // Array de los espacios ocupados
    bool* ocupada;

public:
	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    Agenda(int capacidad);

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    int obtenerPosicion(long telefono);

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    bool existeContacto(long telefono);

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    string getContacto(long telefono);

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void introducirContacto(long telefono, string contacto);

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void eliminarContacto(long telefono);

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void imprimir();  

	/*  
	x
		Parámetro: 
			int x, 

		Retorno: 
			Ninguno
		
		Precondicion: 
			x > 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    ~Agenda();
}