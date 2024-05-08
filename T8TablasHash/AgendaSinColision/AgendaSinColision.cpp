#include "AgendaSinColision.h"
#include "assertdomjudge.h"
#include <iostream>

// Aplica la funcion de hash a la clave para determinar su posicion
int Agenda::obtenerPosicion(long telefono)
{
	assertdomjudge(telefono>=0);

	// Aplico funcion hash
	return telefono%capacidad;
}

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
}

// Comprueba si existe un contacto en la tabla hash
bool Agenda::existeContacto(long telefono)
{
	// NOTE: Puede darse el caso en que la basura inicial sea 1 y de como ya hay un dato
	// para evitar esto habria que inicializar todo a 0
	if(ocupada[obtenerPosicion(telefono)]==1) return true;
	else return false;

	// NOTE: Es necesario usar un if() porque la basura inicial cuenta como true
	// return ocupada[obtenerPosicion(telefono)];
}

// Devuelve el contacto asiciado a un numero de telefono
string Agenda::getContacto(long telefono)
{
	
	if(existeContacto(telefono)) return nombres[obtenerPosicion(telefono)];
	else return NULL;

	// TODO: puede que solo tenga que devolver si el dato existe y que no devuelva la basura de uno borrado previamente
	// return nombres[obtenerPosicion(telefono)];
}

// Introduce un contacto en la tabla hash, si una posicion esta llena la sobreescribe
void Agenda::introducirContacto(long telefono, string contacto)
{
	int posicion=obtenerPosicion(telefono);

	telefonos[posicion]=telefono;
	nombres[posicion]=contacto;
	ocupada[posicion]=true;

	return;
}

// Marca como vacia un espacio en la tabla hash
void Agenda::eliminarContacto(long telefono)
{
	ocupada[obtenerPosicion(telefono)]=false;

	return;
}

// Imprime los contenidos de la tabla hash
void Agenda::imprimir() 
{
	for(int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

// Destructor
Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupada;
}