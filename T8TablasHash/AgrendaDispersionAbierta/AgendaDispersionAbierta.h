#include "assertdomjudge.h"

using namespace std;

class Agenda
{
private:

    int capacidad;

    int n;

    ListaEnlazada *tabla;

    /*  
	Aplica la funcion de hash a la clave para determinar su posicion
		Parámetro: 
			long telefono, clave

		Retorno: 
			int posicion, posicion relacionada con la clave
		
		Precondicion: 
			telefono >= 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    int obtenerPosicion(long telefono);

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
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    Agenda(int capacidad);

	/*  
	Comprueba si existe un contacto en la tabla hash
		Parámetro: 
			long telefono, clave

		Retorno: 
			bool ocupada, si esta o no ocupada la posicion
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
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
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    string getContacto(long telefono);

	/*  
	Introduce un contacto en la tabla hash, si una posicion esta llena la sobreescribe
		Parámetro: 
			long telefono, clave
			string contacto, valor

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
    void introducirContacto(long telefono, string contacto);

	/*  
	Marca como vacia un espacio en la tabla hash
		Parámetro: 
			long telefono, clave

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
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
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
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    ~Agenda();
    
};