#include "Pila.h"

// Constructor
Pila::Pila(string name)
{
	this->name=name;
	
	cima=NULL;
}

// Devuleve el nombre de la pila
std::string Pila::nombrePila()
{
	return name;
}

// Introducir un elemento a la parte superior de la pila, push
void Pila::apilar(int num)
{
	// NOTE: la cima de la pila es el primer elemento. Los elemento apuntas hacia abajo

  	cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
	
	Nodo* nuevoNodo = new Nodo(num);

	// Si la pila no esta vacia, apunto el nodo de la anterior cima al nuevo nodo
	if(cima/*!=NULL*/) nuevoNodo->siguiente=cima;

	// Guardo el nuevo nodo como la cima
	cima=nuevoNodo;
	
	return;
}
  
// Sacar un elemento a la parte superior de la pila, pop
int Pila::desapilar()
{    

	/* TODO: Implementar dos casos 
		Si se desapila el primer elemento de la pila
		Y si se desapila cualquier otro
	*/

	int valorCima=cima->valor;

	cima=cima->siguiente;

	delete aux;
  	
	cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;

	return valorCima;
}

// Devuelve booleano segun si esta vacia la lista
bool Pila::estaVacia()
{
	//TODO: pseudocode

	// Si cima no es NULL revuelve false
	if(cima/*!=NULL*/) return false;
	// Si en NULL revuelve true
	else return true;
}

