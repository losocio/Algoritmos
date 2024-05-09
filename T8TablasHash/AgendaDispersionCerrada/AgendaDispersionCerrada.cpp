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

//TODO
// Busca la posicion de un contacto en la tabla hash
int Agenda::buscarContacto(long telefono)
{
	// Posicion inicial
	int posicion = obtenerPosicion(telefono);

	// Mientras el contacto no sea el buscado se pasa al siguiente
	/*
	Para seguir buscando deben cumplirse varias cosas:
		La clave no es la buscada (telefonos[posicion]!=telefono)


	*/
	while(telefonos[posicion]!=telefono && borradas[posicion]==true && vacias[posicion]!=true)
	{
		// Apuntar a la siguiente posicion
		posicion++;

		// Si se llega al final de la tabla vuelvo al principio
		if(posicion=capacidad-1) posicion=0;
	}


	// Mientras el contacto no sea el buscado se pasa al siguiente
	// NOTE: esto esta mal, si no esta en la tabla es bucle infinito
	while(telefonos[posicion]!=telefono)
	{
		// Apuntar a la siguiente posicion
		posicion++;

		// Si se llega al final de la tabla vuelvo al principio
		if(posicion=capacidad-1) posicion=0;
	}

	return posicion;
}

//TODO
// Busca un hueco adecuado para almacenar un contacto
int Agenda::buscarHueco(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	// Mientras el espacio no este vacio o/y (decidir) o este borrado

	// NOTE: Es necesario usar == en las condiciones, ya que esos bits empiezan como basura (los booleanos en c++ ocupan 1 byte, no un bit)
	// TODO: esta condicion esta mal cienpor
	while(vacias[posicion]==false /*&& borradas[posicion]==true*/)
	{
		// Apuntar a la siguiente posicion
		posicion++;

		// Si se llega al final de la tabla vuelvo al principio
		if(posicion=capacidad-1) posicion=0;
	}

	return posicion;

}

// Indica si la tabla hash esta llena
bool Agenda::isLlena()
{
	if(capacidad==n) return true;
	else return false;
}

// existeContacto y getContacto son iguales, solo que uno devuelve true y otro el contacto en string

// TODO: ajustar sa
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

// TODO: ajustar sa
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
	// Si la lista esta llena sale del metodo sin introducir nada
	if(isLlena()) return;

	// Encuentro un hueco apropiado
	int posicionHueco = buscarHueco(telefono);

	// Guardo la clave y el valor en el hueco apropiado
	nombres[posicionHueco] = contacto;
	telefonos[posicionHueco] = telefono;

	// Marco como llena la posicion
	vacias[posicionHueco] = false;

	n++;

	return;
}

// TODO: creo que ya esta
// Marca como vacia un espacio en la tabla hash
void Agenda::eliminarContacto(long telefono)
{
	// Encuentro el contacto
	int posicionContacto = buscarContacto(telefono);

	// Si el contacto no esta en la agenda salgo del metodo
	if(posicionContacto==-1) return;


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
