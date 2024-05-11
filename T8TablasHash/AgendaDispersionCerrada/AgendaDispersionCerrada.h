#include "assertdomjudge.h"
#include <string>

using namespace std;

class Agenda
{
private:
    // Capacidad de elementos de la tabla hash
    int capacidad;

	// Numero total de valores en la tabla hash
	int n;
    
    // Array de los nombres, los valores en ente caso
    string* nombres;
    
    // Array de los telefonos, las claves en este caso
    long* telefonos;

    // Array de los espacios ocupados
    bool* vacias;

    // Array de los espacios ocupados
    bool* borradas;

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
			M(n) = 4*capacidad
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
	Busca la posicion de un contacto en la tabla hash, si este no esta devuelve -1
		Parámetro: 
			long telefono, clave

		Retorno: 
			int encontrado, posicion del contacto adecuado
		
		Precondicion: 
			telefono >= 0
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    int buscarContacto(long telefono);

	/*  
	Busca un hueco adecuado para almacenar un contacto
		Parámetro: 
			long telefono, clave

		Retorno: 
			int posicion, posicion del hueco adecuado
		
		Precondicion: 
			Ninguna
		
		Complejidad Temporal:
			T(n) = capacidad
			O(capacidad)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    int buscarHueco(long telefono);

	/*  
	Indica si la tabla hash esta llena
		Parámetro: 
			Ninguno

		Retorno: 
			bool llena, si la tabla hash esta llena o no
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    bool isLlena();

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
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    string getContacto(long telefono);

	/*  
	Introduce un contacto en la tabla hash
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
			M(n) = 1
			O(1)
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
			T(n) = capacidad
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