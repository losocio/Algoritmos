#include "assertdomjudge.h"
#include "ListaEnlazada.h"

using namespace std;

class Agenda
{
private:

	// Capacidad de elementos de la lista hash
    int capacidad;

	// Numero de elementos en la tabla hash
    int n;

	// Tabla hash de listas enlazadas
    ListaEnlazada *tabla;

public:

    /*  
	Constructor por parametros
		Parámetro: 
			int capacidad, capacidad de la tabla hash

		Retorno: 
			Ninguno
		
		Precondicion: 
			capacidad >= 0
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = capacidad
			O(capacidad)
	*/
    Agenda(int capacidad);

	/*  
	Aplica la funcion de hash a la clave para determinar su posicion
		Parámetro: 
			long telefono, clave

		Retorno: 
			int posicion, posicion relacionada con la clave
		
		Precondicion: 
			telefono >= 0
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    int obtenerPosicion(long telefono);
	
	/*  
	Comprueba si existe un contacto en la tabla hash
		Parámetro: 
			long telefono, clave

		Retorno: 
			bool ocupada, si esta o no ocupada la posicion
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = n
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    bool existeContacto(long telefono);

	/*  
	Devuelve el contacto asiciado a un numero de telefono
		Parámetro: 
			long telefono, clave

		Retorno: 
			string nombre, nombre de contacto asociado a un telefono
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 2*n
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    string getContacto(long telefono);

	/*  
	Introduce un contacto en la lista enlazada de la posicion de la tabla hash
		Parámetro: 
			long telefono, clave
			string contacto, valor

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = n
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    void introducirContacto(long telefono, string contacto);

	/*  
	Elimina un contacto en la lista enlazada de la posicion de la tabla hash
		Parámetro: 
			long telefono, clave

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 2*n
			O(n)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    void eliminarContacto(long telefono);

	/*  
	Imprime los contenidos de la tabla hash
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = capacidad * n
			O(capacidad)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    void imprimir();  

	/*  
	Destructor
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
    ~Agenda();
    
};