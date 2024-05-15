#include "AgendaDispersionCerrada.h"
#include "assertdomjudge.h"
#include <iostream>

// Constructor por parametros
Agenda::Agenda(int capacidad)
{
	assertdomjudge(capacidad>=0);

	// Capacidad de la tabla
	this->capacidad=capacidad;

	n=0;

	// Reservo memoria para las claves, los valores, la ocupacion y las borradas
	nombres=new string[capacidad];

	telefonos=new long[capacidad];

	vacias=new bool[capacidad];

	borradas=new bool[capacidad];
}

// Aplica la funcion de hash a la clave para determinar su posicion
int Agenda::obtenerPosicion(long telefono)
{
	assertdomjudge(telefono>=0);

	// Aplico funcion hash
	return telefono%capacidad;
}

// FIX: no continua hasta donde deberia
// Busca la posicion de un contacto en la tabla hash, si este no esta devuelve -1
int Agenda::buscarContacto(long telefono)
{
	// Posicion inicial
	int posicion = obtenerPosicion(telefono);

	// Si no se encuentra el contacto se devuleve -1
	int encontrado = -1;

	// NOTE: Usar telefonos[posicion]!=telefono como una de las condiciones no tiene sentido, ya que el bucle sera infinito ni no se existe el contacto
	// Mientras el contacto no sea el buscado se pasa al siguiente
	// FIX: Bucle infinito
	while(vacias[posicion]!=true && borradas[posicion]!=true)
	{
		// NOTE: Primero se incrementa este contador,
		// porque la condicion del while() se cumple si la posicion NO cumple los requisitos
		// Se apunta a la siguiente posicion para comprobar si ahi esta el contacto buscado
		posicion++;

		// Si la posicion se sale del rango de la tabla vuelve a la primera posicion
		if(posicion==capacidad) posicion=0;

		// FIXED: Se saltaria la ultima posicion
		// if(posicion==capacidad-1) posicion=0;

		// NOTE: hay que comprobar vacias[posicion]!=true, sino podria devolver un dato borrado previamente
		// Si el contacto es el buscado y la posicion no esta vacia
		if(telefonos[posicion]==telefono && vacias[posicion]!=true) //TODO: lo esto comprobando dos veces, pero puede que sea necesario
		{
			// Guardo en encontrado la posicion
			encontrado=posicion;
			// Salgo del bucle
			break;
		}

	}

	return encontrado;
}

// Busca un hueco adecuado para almacenar un contacto
int Agenda::buscarHueco(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	// Mientras el espacio no este vacio o/y (decidir) o este borrado

	// NOTE: Es necesario usar == en las condiciones, ya que esos bits empiezan como basura (los booleanos en c++ ocupan 1 byte, no un bit)
	// Pasa a la siguiente posicion hasta encontrar una vacia
	while(vacias[posicion]==false /*&& borradas[posicion]==true*/)
	{
		// Apuntar a la siguiente posicion
		posicion++;

		// Si la posicion se sale del rango de la tabla vuelve a la primera posicion
		if(posicion==capacidad) posicion=0;

		// FIXED: Se saltaria la ultima posicion
		// if(posicion==capacidad-1) posicion=0;
	}

	return posicion;
}

// Indica si la tabla hash esta llena
bool Agenda::isLlena()
{
	// Si la cantidad de contactos en igual que la capacidad la lista esta llena
	if(capacidad==n) return true;
	else return false;
}

// Comprueba si existe un contacto en la tabla hash
bool Agenda::existeContacto(long telefono)
{
	// Si no se encuentra el contacto devuelve false
	if(buscarContacto(telefono)==-1) return false;
	// Sino true
	else return true;
}

// FIXED: Si que era precondicion, me rayaba tener que usar buscar contacto dos veces
// Devuelve el contacto asiciado a un numero de telefono
string Agenda::getContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	// Busco el contacto
	int posicionContacto = buscarContacto(telefono);

	// Devuelvo el nombre del contacto
	return nombres[posicionContacto];
}

// Introduce un contacto en la tabla hash
void Agenda::introducirContacto(long telefono, string contacto)
{
	// La lista necesita tener sitio
	assertdomjudge(!isLlena());

	// Encuentro un hueco apropiado
	int posicionHueco = buscarHueco(telefono);

	// Guardo la clave y el valor en el hueco apropiado
	nombres[posicionHueco] = contacto;
	telefonos[posicionHueco] = telefono;

	// Marco como llena la posicion
	vacias[posicionHueco] = false;

	// NOTE: No es necesario, ya que buscarHueco() nunca lo consulta
	// Marco como no borrada la posicion
	// borradas[posicionHueco] = false;

	n++;

	return;
}

// Marca como vacia un espacio en la tabla hash
void Agenda::eliminarContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));
	
	// Encuentro el contacto
	int posicionContacto = buscarContacto(telefono);

	/* NOTE: Esto lo controlo con el assert()
	// Si el contacto no esta en la agenda salgo del metodo sin hacer nada
	if(posicionContacto==-1) return;
	*/

	// Marco como vacia la posicion
	vacias[posicionContacto] = true;

	// Marco como borrada la posicion
	borradas[posicionContacto] = true;

	n--;

	return;
}

// Imprime los contenidos de la tabla hash
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

// Destructor
Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}
