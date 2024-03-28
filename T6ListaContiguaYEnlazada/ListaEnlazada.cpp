#include "ListaEnlazada.h"

// Devuelve puntero al nodo en la posicion solicitada
Nodo* ListaEnlazada::getNodo(int posicion)
{
    assertdomjudge(posicion>=0 && posicion<=n);

    // Guardo el comienzo de la lista
    Nodo* nodoIterar=lista;

    // Itero hasta la posicion deseada
    for(int i=0;i<posicion;i++) nodoIterar=nodoIterar->siguienteNodo;

    return nodoIterar;
}

// Crea una lista enlazada vacia
ListaEnlazada::ListaEnlazada()
{
    n=0;
    lista=NULL;
}

// Devuelve el valor en la posicion pedida
int ListaEnlazada::getValor(int posicion)
{
    assertdomjudge(posicion>=0 && posicion<n);
    
    return getNodo(posicion)->elemento;
}

// Modifica el valor de la posicion pedida
void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
    assertdomjudge(posicion>=0 && posicion<n);

    getNodo(posicion)->elemento=nuevoValor;

    return;
}

// Devuelve n
int ListaEnlazada::getN()
{
    return n;
} 

// Inserta elementos en la lista, el comportamiento varia dependiendo de donde se quiera insertar
void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<=n);

    // NOTE: Nodo* nodoAnterior=getNodo(posicion-1); da segfault si se elimina el primer elemento
    // Lo pongo en el if
    Nodo* nodoNuevo=new Nodo();

    // Si se inserta al principio de la lista
    if(posicion==0)
    {
        // Guardo el valor en el nuevo nodo
        nodoNuevo->elemento=nuevoValor;

        // Apunto el nuevo nodo al nodo 0
        nodoNuevo->siguienteNodo=lista;

        // Apunto la lista al nodo nuevo
        lista = nodoNuevo;

    }
    // Si se inserta al final de la lista
    else if(posicion==n)
    {
        Nodo* nodoAnterior=getNodo(posicion-1);

        // Guardo el valor en el nuevo nodo
        nodoNuevo->elemento=nuevoValor;

        // Apunto el nuevo nodo a NULL
        nodoNuevo->siguienteNodo=NULL;

        // Apunto el nodo anterior al nuevo
        nodoAnterior->siguienteNodo=nodoNuevo;
    }
    // Si se inserta dentro de la lista, entre dos nodos
    else
    {
        Nodo* nodoAnterior=getNodo(posicion-1);

        // Guardo el valor en el nuevo nodo
        nodoNuevo->elemento=nuevoValor;

        // Apunto el nuevo nodo a siguiente nodo
        // FIXED: nodoAnterior->siguienteNodo en vez de nodoAnterior->getNodo(posicion+1)
        nodoNuevo->siguienteNodo=nodoAnterior->siguienteNodo;

        // Apunto el nodo anterior al nodo nuevo
        nodoAnterior->siguienteNodo=nodoNuevo;
    }

    /* NOTE: no se puede usar switch case, los case no pueden definirse dinamicamente
    switch(posicion)
    {
        // Si la lista esta vacia
        case 0:
            lista = nodo;
            lista->elemento=nuevoValor;
            lista->siguienteNodo=NULL;
          
            break;

        // Si se inserta al final de la lista
        case n:

            nodo->elemento=nuevoValor;
            nodo->siguienteNodo=NULL;

            nodoAnterior->siguienteNodo=nodo;
        
            break;

        // Si se inserta entre dos nodos
        default:
            nodo->elemento=nuevoValor;
            nodo->siguienteNodo=getNodo(posicion+1);

            nodoAnterior->siguienteNodo=nodo;
    }
    */

    // Aumento el contador de nodos
    n++;

    return;
}

// Elimina elementos de la lista, el comportamiento varia dependiendo de donde se quiera eliminar
void ListaEnlazada::eliminar(int posicion)
{
    // TODO: check it
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<n);

    // NOTE: Ejemplo de buena practica, solo llamo a getNodo() una vez para dos variables
    // NOTE: Nodo* nodoAnterior=getNodo(posicion-1); da segfault si se elimina el primer elemento
    // Lo pongo en el if
    Nodo* nodoABorrar=getNodo(posicion);
    //Nodo* nodoABorrar=getNodo(posicion)->siguienteNodo;
    Nodo* nodoSiguiente=nodoABorrar->siguienteNodo;

    // Si se elimina al principio de la lista
    if(posicion==0)
    {
        // Borro el primer nodo
        delete nodoABorrar;
        
        // Apunto el comienzo de la lista al siguiente
        lista = nodoSiguiente;
    }
    // Si se elimina al final de la lista
    else if(posicion==n-1)
    {
        Nodo* nodoAnterior=getNodo(posicion-1);

        // Borro el nodo final
        delete nodoABorrar;

        // Pongo a NULL el puntero del nodo anterior
        nodoAnterior->siguienteNodo=NULL;
    }
    // Si se elimina dentro de la lista, entre dos nodos
    else
    {
        Nodo* nodoAnterior=getNodo(posicion-1);

        // Apunto el nodo anterior al siguiente
        nodoAnterior->siguienteNodo=nodoSiguiente;

        // Borrao el nodo a borrar
        delete nodoABorrar;
    }

    /* NOTE: no se puede usar switch case, los case no pueden definirse dinamicamente
    switch(posicion)
    {
        // Si la lista esta vacia
        case 0:
            
            // NOTE: delete *lista; puede que sea asi
            delete lista;
            

            lista = nodoSiguiente;

          
            break;

        // Si se inserta al final de la lista
        case n:
            //delete getNodo(posicion);
            delete nodoAnterior->siguienteNodo;

            nodoAnterior->siguienteNodo=NULL;
            break;

        // Si se inserta entre dos nodos
        default:
            Nodo* nodoABorrar=nodoAnterior->siguienteNodo;

            nodoAnterior->siguienteNodo=nodoABorrar->siguienteNodo;

            delete nodoABorrar;
    }
    */

    // Decremento el contador de nodos
    n--;

    return;
}

// Concatena la lista indicada como parámetro al final de nuestra lista
void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
    // TODO: implementar sin usar getNodo()

    // NOTE: no se si esto es legal en c++
    // getNodo(n-1)->siguienteNodo=listaAConcatenar->lista;
    
    // Consigo el nodo final
    Nodo* nodoFinal=getNodo(n-1);

    // Apunto el nodo final de una al inicial del parametro
    nodoFinal->siguienteNodo=listaAConcatenar->lista;

    // Actualizo el contador de nodos
    // FIXED: faltaba actializar el contador de nodos
    n+=listaAConcatenar->n;

    return;
}

// Encontrar el indice del elemento a buscar
int ListaEnlazada::buscar(int elementoABuscar)
{
    Nodo* nodoIterar=lista;
    int i=0;

    // Aumento el contador de indice hasta encontar el valor buscado o cuando se llega al final de la lista
    // FIXED: era n-1, no n. Asi tiene sentido con los indices
    while(nodoIterar->elemento!=elementoABuscar && i<n-1) 
    {
        nodoIterar=nodoIterar->siguienteNodo;
        i++;
    }

    // Si el indice es igual al tamaño de la lista lo cambio por -1
    if(i==n-1) i=-1;

    // Devuelvo el indice o -1
    return i;


    /* NOTE: Implementacion menos eficiente que itera todos los elementos
    int indiceEncontrado=-1;

    for(int i=0;i<n;i++)
    {
        if(vector[i]==elementoABuscar) indiceEncontrado=i;
        i++;    
    }

    return indiceEncontrado;
    */

}

// Destructor
ListaEnlazada::~ListaEnlazada()
{
    // NOTE: Nodo* nodoSiguiente=lista, nodoAux; Es esta mal se define un Nodo* y despues un Nodo
    Nodo* nodoSiguiente=lista, *nodoAux;

    // Itero por todos los nodos
    for(int i=0;i<n;i++)
    {
        // Guardo la direccion del siguiente nodo para poder acceder a ella una vez el nodo actual
        nodoAux=nodoSiguiente->siguienteNodo;
        
        // Borro nodo actual
        delete nodoSiguiente;
        
        // Paso al siguiente nodo para borrarlo en la sigiuente iteracion
        nodoSiguiente=nodoAux; 
    }

    // NOTE: no necesario, se borra automaticamente con el constructor 
    // delete lista=NULL;
}