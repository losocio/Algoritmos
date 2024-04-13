#include "ListaCircular.h"

// Devuelve puntero al nodo en la posicion solicitada
Nodo* ListaCircular::getNodo(int posicion)
{
    assertdomjudge(posicion>=0 && posicion<n);

    // Guardo el comienzo de la lista
    Nodo* nodoIterar=lista;

    // Itero hasta la posicion deseada
    for(int i=0;i<posicion;i++) nodoIterar=nodoIterar->siguienteNodo;

    return nodoIterar;
}

// Crea una lista vacia
ListaCircular::ListaCircular()
{
    lista=NULL;
	n=0;
}

// Devuelve el valor en la posicion pedida
string ListaCircular::getValor(int posicion)
{
    assertdomjudge(posicion>=0 && posicion<n);
    
    return getNodo(posicion)->elemento;
}

// Modifica el valor de la posicion pedida
void ListaCircular::setValor(int posicion, string nuevoValor)
{
    assertdomjudge(posicion>=0 && posicion<n);

    getNodo(posicion)->elemento=nuevoValor;

    return;
}

// Devuelve n
int ListaCircular::getN()
{
    return n;
} 

// Inserta nodos en la lista, el comportamiento varia dependiendo de si se inserta el primer nodo
void ListaCircular::insertar(int posicion, string nuevoValor)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<=n);

    // Creo nuevo nodo
    Nodo* nodoNuevo = new Nodo();

    // Asigno nuevo valor
    nodoNuevo->elemento=nuevoValor;

    // Si se inserta el primer nodo
    if(posicion==0)
    {
        // Apunto el nuevo nodo a si mismo, ya que es el unico
        nodoNuevo->siguienteNodo=nodoNuevo;
        nodoNuevo->anteriorNodo=nodoNuevo;

        // Apunto la lista al nodo nuevo
        lista = nodoNuevo;

    }
    // Si se insertan nodos adicionales
    else
    {
        Nodo* nodoAnterior=getNodo(posicion-1);
        Nodo* nodoSiguiente=nodoAnterior->siguienteNodo;

        // Apunto el nuevo nodo al nodo siguiente y anterior
        nodoNuevo->siguienteNodo=nodoSiguiente;
        nodoNuevo->anteriorNodo=nodoAnterior;

        // Apunto el nodo anterior al nodo nuevo
        nodoAnterior->siguienteNodo=nodoNuevo;

        // Apunto el nodo siguiente al nodo nuevo
        nodoSiguiente->anteriorNodo=nodoNuevo;
    }
	
    n++;
	
	return;
}

// Elimina nodos de la lista, el comportamiento varia dependiendo de si se vacia la lista
void ListaCircular::eliminar(int posicion)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<n);

    Nodo* nodoABorrar=getNodo(posicion);   

    // Si se elimina al principio de la lista
    if(posicion==0)
    {
        // Apunto el comienzo de la lista al siguiente
        lista = nodoABorrar->siguienteNodo;
        
        // Borro el primer nodo
        delete nodoABorrar;
        
    }
    // Si se elimina dentro de la lista, entre dos nodos
    else
    {
        Nodo* nodoAnterior=nodoABorrar->anteriorNodo;
        Nodo* nodoSiguiente=nodoABorrar->siguienteNodo;

        // Apunto el nodo anterior al nodo siguiente
        nodoAnterior->siguienteNodo=nodoSiguiente;

        // Apunto el nodo siguiente al nodo anterior
        nodoSiguiente->anteriorNodo=nodoAnterior;

        // Borro el nodo a borrar
        delete nodoABorrar;
    }

    n--;

    return;
}

// Girar el tambor, apunta la lista al siguiente nodo
void ListaCircular::girar(int p)
{
    // Si p es positivo, girar a la derecha
    if(p>=0)
    {
        // Itero p veces apuntando lista al siguiente nodo
        for(int i=0;i<p;i++) lista=lista->siguienteNodo;
    }
    // Sino girar a la izquierda
    else
    {
        //FIX: algo falla aqui
        
        // Itero p veces apuntando lista al anterior nodo
        for(int i=0;i<p;i++) lista=lista->anteriorNodo;
    }

    return;
}

// Destructor
ListaCircular::~ListaCircular()
{
    Nodo* nodoABorrar=lista;
    Nodo* nodoAux;

    // Itero por todos los nodos
    for(int i=0;i<n;i++)
    {
        // Guardo la direccion del siguiente nodo para poder acceder a ella una vez el nodo actual
        nodoAux=nodoABorrar->siguienteNodo;
        
        // Borro nodo actual
        delete nodoABorrar;
        
        // Paso al siguiente nodo para borrarlo en la sigiuente iteracion
        nodoABorrar=nodoAux; 
    }

}

