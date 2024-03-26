#include "ListaEnlazada.h"

// Devuelve puntero al nodo en la posicion solicitada
Nodo* ListaEnlazada::getNodo(int posicion)
{
    Nodo* nodoIterar=lista;

    for(int i=0;i<posicion;i++)
    {
        nodoIterar=nodoIterar->siguienteNodo;
    }

    return nodoIterar;
}

ListaEnlazada::ListaEnlazada()
{
    n=0;
    lista=NULL;
}

int ListaEnlazada::getValor(int posicion)
{
    assertdomjudge(posicion>=0 && posicion<n);
    
    return getNodo(posicion).elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
    assertdomjudge(posicion>=0 && posicion<n);

    getNodo(posicion)->elemento=nuevoValor;
    return;
}

int ListaEnlazada::getN()
{
    return n;
} 

void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
    // TODO: check it
    assertdomjudge(posicion>=0 && posicion<n);

    // Si la lista esta vacia
    switch(posicion)
    {
        // Si la lista esta vacia
        case 0:
            lista = new Nodo();
            lista->elemento=nuevoValor;
            lista->siguienteNodo=NULL;
          
            break;

        // Si se inserta al final de la lista
        case n:
            Nodo* nodo=new Nodo();
            nodo->elemento=nuevoValor;
            nodo->siguienteNodo=NULL;

            Nodo* nodoAnterior=getNodo(posicion-1);
            nodoAnterior->siguienteNodo=nodo;
        
            break;

        // Si se inserta entre dos nodos
        default:
            Nodo* nodo=new Nodo();
            nodo->elemento=nuevoValor;
            nodo->siguienteNodo=getNodo(posicion+1);

            Nodo* nodoAnterior=getNodo(posicion-1);
            nodoAnterior->siguienteNodo=nodo;
    }

    n++;

    return;
}

void ListaEnlazada::eliminar(int posicion)
{
    // TODO: check it
    assertdomjudge(posicion>=0 && posicion<n);

    // Si la lista esta vacia
    switch(posicion)
    {
        // Si la lista esta vacia
        case 0:
            Nodo* nodoSiguiente=lista->siguienteNodo;
            
            // NOTE: delete *lista; puede que sea asi
            delete lista;
            

            lista = nodoSiguiente;

          
            break;

        // Si se inserta al final de la lista
        case n:
            Nodo* nodoAnterior=getNodo(posicion-1);

            //delete getNodo(posicion);
            delete nodoAnterior->siguienteNodo;

            nodoAnterior->siguienteNodo=NULL;
            break;

        // Si se inserta entre dos nodos
        default:
            Nodo* nodoAnterior=getNodo(posicion-1);
            Nodo* nodo=nodoAnterior->siguienteNodo;

            nodoAnterior->siguienteNodo=nodo->siguienteNodo;

            delete nodo;
    }

    n--;

    return;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{

}

int ListaEnlazada::buscar(int elementoABuscar)
{

}

ListaEnlazada::~ListaEnlazada()
{
    for(int i=n;i>0;i--)
    {
        delete 
    }

    delete lista;
}