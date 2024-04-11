#include "Pila.h"

// Constructor
Pila::Pila(string name)
{
	this->name=name;
	cima=NULL;
}

// Devuelve el nombre de la pila
std::string Pila::nombrePila()
{
	return name;
}

// Introducir un elemento a la parte superior de la pila, push
void Pila::apilar(int num)
{
	// NOTE: la cima de la pila es el primer elemento. Los elementos apuntan hacia abajo

	// NOTE: creo que con num como unico parametro es valido, el puntero al siguiente nodo es NULL por defecto
	// Creo un nuevo nodo
	Nodo* nuevoNodo = new Nodo(num);

	// Si la pila no esta vacia, apunto el nuevo nodo a la cima anterior
	if(cima!=NULL) nuevoNodo->siguiente=cima;

	// Guardo el nuevo nodo como la cima
	cima=nuevoNodo;

  	cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
	
	return;
}

// FIX: causa segfault sa
// Sacar un elemento a la parte superior de la pila, pop
int Pila::desapilar()
{    
	// NOTE: No necesito un caso especial 

	// Guardo el nodo por desapilar y su valor
	Nodo* nodoADesapilar=cima;
	int valorADesapilar=cima->valor;

	// Apunto la cima al siguiente nodo
	cima=nodoADesapilar->siguiente;

	// Borro el nodo de la cima
	delete nodoADesapilar;
  	
	cout<<"Desapilando disco "<<valorADesapilar<<" del poste "<<name<<endl;

	return valorADesapilar;
}

// Devuelve booleano segun si esta vacia la lista
bool Pila::estaVacia()
{
	// Si cima es NULL revuelve false
	if(cima==NULL) return true;
	// Si no es NULL revuelve true
	else return false;
}

