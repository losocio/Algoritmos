#include "AgendaSinColision.h"
#include "assertdomjudge.h"
#include <iostream>

/*

Pensamiento espontaneo sin relacion alguna al codigo:

El nombre de la asignatura, "Análisis y Diseño de Algoritmos", 
se llama asi solamente para que el acronimo sea ADAL y no ANAL.
En ningun momento diseñamos ningun algoritmo.

*/

// Constructor por parametros
Agenda::Agenda(int capacidad)
{
	assertdomjudge(capacidad>=0);

	// Capacidad de la tabla
	this->capacidad=capacidad;

	// Reservo memoria para las claves, los valores y la ocupacion
	nombres=new string[capacidad];

	telefonos=new long[capacidad];

	ocupada=new bool[capacidad];

	/*
	// Inicializo a 0 todos los valores, no le veo el sentido a que sea un ()
	telefonos=new long[capacidad] ();

	// Inicializo a 0 todos los valores, no le veo el sentido a que sea un ()
	ocupada=new bool[capacidad] ();
	*/
}

// Aplica la funcion de hash a la clave para determinar su posicion
int Agenda::obtenerPosicion(long telefono)
{
	assertdomjudge(telefono>=0);

	// Aplico funcion hash
	return telefono%capacidad;
}

// TODO FIX creo que esta bien, fallo una vez pero ya no???
// Comprueba si existe un contacto en la tabla hash
bool Agenda::existeContacto(long telefono)
{
	int posicion = obtenerPosicion(telefono);
	// NOTE: Puede darse el caso en que la basura inicial sea 1 y que de como ya hay un dato
	// para evitar esto habria que inicializar todo a 0
	if(ocupada[posicion]==1) return true;
	else return false;

	// NOTE: Es necesario usar un if() porque la basura inicial cuenta como true
	// return ocupada[obtenerPosicion(telefono)];
}

// FIXED: Si que era precondicion, me rayaba tener que usar buscar contacto dos veces
// Devuelve el contacto asociado a un numero de telefono
string Agenda::getContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	int posicion = obtenerPosicion(telefono);

	return nombres[posicion];
}

// Introduce un contacto en la tabla hash, si una posicion esta llena NO la sobreescribe
void Agenda::introducirContacto(long telefono, string contacto)
{
	assertdomjudge(!existeContacto(telefono));

	int posicion=obtenerPosicion(telefono);
	
	// Si la posicion esta llena no la sobreescribe
	if(ocupada[posicion]!=true)
	{
		telefonos[posicion]=telefono;
		nombres[posicion]=contacto;
		ocupada[posicion]=true;
	}
	
	/*
	// Si la posicion esta llena la sobreescribe
	telefonos[posicion]=telefono;
	nombres[posicion]=contacto;
	ocupada[posicion]=true;
	*/

	return;
}

// Marca como vacia un espacio en la tabla hash, si existe el contacto
void Agenda::eliminarContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	int posicion = obtenerPosicion(telefono);

	ocupada[posicion]=false;

	return;
}

// Imprime los contenidos de la tabla hash
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

// Destructor
Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupada;
}