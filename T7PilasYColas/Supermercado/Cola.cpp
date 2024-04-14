#include "Cola.h"

// Constructor
Cola::Cola()
{
    // Hace pop desde aqui
    principio=NULL;

    // Aqui se añaden nuevo nodos
    final=NULL;
}

// Añadir un nuevo nodo al final de la cola
void Cola::encolar(int num)
{
    // NOTE: Al ser el orden de llegada no puede ser negativo
    assertdomjudge(num>=0);

    Nodo* nuevoNodo=new Nodo(num);

    // Apunto a NULL, es el ultimo de la cola
    nuevoNodo->siguiente=NULL;

    // Si la cola esta vacia
    if(principio==NULL && final==NULL)
    {
        // Asigno el final y el pricipio de la cola al unico nodo
        principio=nuevoNodo;
        final=nuevoNodo;
    }
    // Si ya hay algun nodo
    else
    {
        // Apunto el nodo final al nuevo nodo
        final->siguiente=nuevoNodo;

        // Apunto final al nuevo nodo
        final=nuevoNodo;
    }

    return;
}

// Extraer el primer nodo de la cola
int Cola::desencolar()
{
    // TODO: Implementar si se borra el ultimo elemento aunk puede que no sea necesario

    // Guardo el valor desencolado
    int valorDesencolado=principio->valor;
    
    // Guardo el siguiente nodo
    Nodo* nodoSiguiente=principio->siguiente;
    
    // Si principio y final son iguales (solo queda el ultimo nodo) Apunto final a NULL
    if(principio==final) final=NULL;

    // Borro el primer nodo
    delete principio;

    // Apunto el principio al siguiente nodo
    principio=nodoSiguiente;

    return valorDesencolado;
}

// Devuelve si esta vacia la cola
bool Cola::estaVacia() 
{
    // Si la lista esta vacia devuelvo true
    if(principio==NULL && final==NULL) return true;
    // Si no devuelvo false
    else return false;
}