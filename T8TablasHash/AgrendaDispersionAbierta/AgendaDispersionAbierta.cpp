#include <iostream>
#include "AgendaDispersionAbierta.h"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash

// Constructor por parametros
Agenda::Agenda(int capacidad)
{
	assertdomjudge(capacidad>=0);

	// Capacidad de la tabla
	this->capacidad=capacidad;

	n=0;

	tabla = new ListaEnlazada[capacidad];
	
}

// Aplica la funcion de hash a la clave para determinar su posicion
int Agenda::obtenerPosicion(long telefono)
{
	assertdomjudge(telefono>=0);

	// Aplico funcion hash
	return telefono%capacidad;
}

// Comprueba si existe un contacto en la tabla hash
bool Agenda::existeContacto(long telefono)
{
	int posicion = obtenerPosicion(telefono);

	// Busco el contacto
	int posicionEncontrada=tabla[posicion].buscar(telefono);

	// Si buscar contacto devuleve -1 no se encontro el contacto
	if(posicionEncontrada==-1) return false;
	else return true;

	/* NOTE: Es inececsario ya que buscar ya compara el telefono
	// Si buscar contacto devuleve -1 no se encontro el contacto
	if(posicionEncontrada==-1) return false;
	else if(tabla[posicion].getValor(posicionEncontrada).telefono==telefono) return true;
	*/
}

// Devuelve el nombre asociado a un numero de telefono
string Agenda::getContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	int posicion = obtenerPosicion(telefono);
	
	// Busco la posicion del contacto
	int posicionEncontrada=tabla[posicion].buscar(telefono);
	
	// Devuelve el contacto
	return tabla[posicion].getValor(posicionEncontrada).nombre;
}

// Introduce un contacto en la lista enlazada de la posicion de la tabla hash
void Agenda::introducirContacto(long telefono, string contacto)
{
	// Determino la posicion usand obtenerPosicion()
	int posicion = obtenerPosicion(telefono);

	// NOTE: El objeto de Contacto de memoria dinamica se crea dentro del objeto Nodo dentro del metodo insertar
	// Creo un nuevo objeto de contacto y lo lleno con los datos del contacto
	Contacto nuevoContacto;
	nuevoContacto.telefono=telefono;
	nuevoContacto.nombre=contacto;

	// NOTE: Esta lista enlazada no esta ordenada

	// FIXED: Hay que insertar al principio de la lista, por esto me daba error. Deberia especificarse en el enunciado >:(
	// En dicha posicion de la tabla hash, inserto un nuevo contacto al final de la lista enlazada
	// Para saber donde cuantos elemento hay en la lista enlazada utilizo getN()
	//tabla[posicion].insertar(tabla[posicion].getN(), nuevoContacto);
	

	// Inserto el contacto en la primera posicion de la lista enlazada
	tabla[posicion].insertar(0, nuevoContacto);

	n++;

	return;
}

// Elimina un contacto en la lista enlazada de la posicion de la tabla hash
void Agenda::eliminarContacto(long telefono)
{
	assertdomjudge(existeContacto(telefono));

	// Determino la posicion usand obtenerPosicion()
	int posicion = obtenerPosicion(telefono);

	// NOTE: He modificado el codigo del enunciado, mas informacion en la declaracion del metodo buscar()
	// Busco el contacto a eliminar en la lista enlazada de la posicion dada
	int posicionAEliminar=tabla[posicion].buscar(telefono);

	// Elimino el contacto
	tabla[posicion].eliminar(posicionAEliminar);
	
	// NOTE: Esto estaria mal, eliminaria el ultimo elemento de la lista enlazada, no el telefono a eliminar
	// tabla[posicion].eliminar(tabla[posicion].getN());

	n--;

	return;
}

// Imprime los contenidos de la tabla hash
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

// Destructor
Agenda::~Agenda()
{
	delete[] tabla;
	
	/* NOTE: pensaba que habria que hacer algo asi pero resulta que no
	// Itero por toda la tabla hash llamando al destructor de cada lista enlazada
	for(int i=0; i<capacidad; i++)
	{
		delete tabla[i];
	}
	*/

}