#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

Agenda::Agenda(int capacidad)
{
	this->capacidad=capacidad;

	nombres=NULL;

	telefonos=NULL;

	ocupados=NULL;
}

int obtenerPosicion(long telefono)
{

}

bool existeContacto(long telefono)
{

}

string getContacto(long telefono)
{

}

void introducirContacto(long telefono, string contacto)
{

}

void eliminarContacto(long telefono)
{

}

void Agenda::imprimir() 
{
	for(int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::~Agenda()
{

}