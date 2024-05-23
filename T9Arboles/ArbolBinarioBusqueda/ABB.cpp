#include "ABB.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

// Constructor
ABB::ABB()
{
    // Inicializa el numero de nodos en 0
    n = 0;
    // Inicializa el puntero a la raiz del arbol como NULL
    raiz = NULL;
}

// Insertar un nuevo elemento en el arbol
void ABB::insertar(int nuevoElemento)
{
    // Crear un nuevo nodo e inicializarlo con el nuevo elemento
    Nodo* insertar = new Nodo;

    // Asignar el contenido del nuevo nodo
    insertar->contenido = nuevoElemento;
    // Inicializar los punteros del nuevo nodo
    insertar->padre = NULL;
    insertar->hijoDerecho = NULL;
    insertar->hijoIzquierdo = NULL;

    // Si el arbol esta vacio, el nuevo nodo se convierte en la raiz
    if(n == 0)
    {
        raiz = insertar;
    }
    // Si el arbol no esta vacio, buscar la posicion correcta para insertar el nuevo nodo
    else
    {
        Nodo* padre = buscarHueco(raiz, nuevoElemento);
        // Insertar en el hijo izquierdo si el nuevo elemento es menor o igual al contenido del padre
        if(nuevoElemento <= padre->contenido)
        {
            padre->hijoIzquierdo = insertar;
        }
        // Insertar en el hijo derecho si el nuevo elemento es mayor al contenido del padre
        else
        {
            padre->hijoDerecho = insertar;
        }
        // Establecer el padre del nuevo nodo
        insertar->padre = padre;
    }

    // Incrementar el numero de nodos
    n++;
}

// Buscar un nodo con un elemento especifico en el arbol
Nodo* ABB::buscar(int elementoABuscar)
{
    // Llama a la funcion recursiva para buscar el elemento
    return buscarRecursivo(raiz, elementoABuscar);
}

// Eliminar un elemento del arbol
void ABB::eliminar(int elementoAEliminar)
{
    // Buscar el nodo a eliminar
    Nodo* nodoEliminar = buscar(elementoAEliminar);

    // Llama a la funcion que elimina el nodo encontrado
    eliminarNodo(nodoEliminar);

    // Decrementa el numero de nodos
    n--;

    // Si el arbol queda vacio, establece la raiz como NULL
    if(n == 0)
    {
        raiz = NULL;
    }
}

// Imprimir el arbol
void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

// Verificar si el arbol es un ABB
bool ABB::esABB()
{
    // Llama a la funcion recursiva para verificar si cada subarbol cumple la propiedad de ABB
    return esSubABB(raiz);
}

// Verificar si el arbol es un AVL
bool ABB::esAVL()
{
    // Primero verifica si es un ABB
    if(esABB())
    {
        // Luego verifica si es un AVL
        if(esSubAVL(raiz))
        {
            return true;
        }
    }
    return false;
}

// Lee el arbol desde la entrada estandar
void ABB::leerArbol()
{
    raiz = leerSubarbol(NULL);
}

// Destructor
ABB::~ABB()
{
    // Libera la memoria asignada a la raiz del arbol
    delete[] raiz;
}



// PROTECTED

// Eliminar un subarbol a partir de una raiz dada
void ABB::eliminarSubarbol(Nodo* raizSubarbol)
{
    // Verifica que el nodo no sea NULL
    assertdomjudge(raizSubarbol != NULL);

    Nodo* padre = raizSubarbol->padre;

    // Elimina recursivamente el subarbol izquierdo
    if(raizSubarbol->hijoIzquierdo != NULL)
    {
        eliminarSubarbol(raizSubarbol->hijoIzquierdo);
    }

    // Elimina recursivamente el subarbol derecho
    if(raizSubarbol->hijoDerecho != NULL)
    {
        eliminarSubarbol(raizSubarbol->hijoDerecho);
    }

    // Ajusta los punteros del padre para desvincular el nodo eliminado
    if(padre != NULL)
    {
        if(padre->hijoIzquierdo == raizSubarbol)
        {
            padre->hijoIzquierdo = NULL;
        }

        if(padre->hijoDerecho == raizSubarbol)
        {
            padre->hijoDerecho = NULL;
        }

    }

    // Elimina el nodo
    delete raizSubarbol;
}

// Encontrar el lugar adecuado para insertar un nuevo elemento
Nodo* ABB::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar)
{
    // Verifica que el nodo raiz no sea NULL
    if(raizSubarbol == NULL)
    {
        return NULL;
    }
    // Si el elemento a insertar es menor o igual al contenido del nodo actual, busca en el subarbol izquierdo
    if(elementoAInsertar <= raizSubarbol->contenido)
    {
        // Si el hijo izquierdo es NULL, se ha encontrado el hueco
        if(raizSubarbol->hijoIzquierdo == NULL)
        {
            return raizSubarbol;
        }
        // Continua buscando en el subarbol izquierdo
        return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
    }
    else
    {
        // Si el hijo derecho es NULL, se ha encontrado el hueco
        if(raizSubarbol->hijoDerecho == NULL)
        {
            return raizSubarbol;
        }
        // Continua buscando en el subarbol derecho
        return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
    }
}

// Buscar recursivamente un elemento en el arbol
Nodo* ABB::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar)
{

    Nodo* buscar = new Nodo();

    // Si el nodo actual es NULL devuelve NULL
    if(raizSubarbol == NULL)
    {
        return NULL;
    }
    // Si contiene el valor buscado, retorna el nodo actual
    else if(elementoABuscar == raizSubarbol->contenido)
    {

        return raizSubarbol;
    }
    // Si el valor buscado es menor que el contenido del nodo actual, busca en el subarbol izquierdo
    else if(elementoABuscar < raizSubarbol->contenido)
    {
        buscar = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    }
    // Si el valor buscado es mayor, busca en el subarbol derecho
    else if(elementoABuscar > raizSubarbol->contenido)
    {
        buscar = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    }

    return buscar;
}

// Encontrar el nodo con el valor maximo en un subarbol
Nodo* ABB::buscarMaximo(Nodo* raizSubarbol)
{
    // Asegurarse de que la raiz del subarbol no es NULL
    assertdomjudge(raizSubarbol != NULL);

    Nodo* maximo = new Nodo();

    // Si NULL devolver raizSubarbol
    if(raizSubarbol->hijoDerecho == NULL)
    {
        maximo =  raizSubarbol;
    }
    // Continuar moviendose hacia la derecha hasta encontrar el nodo maximo
    else
    {
        maximo = buscarMaximo(raizSubarbol->hijoDerecho);
    }

    return maximo;
}

// Encontrar el nodo con el valor minimo en un subarbol
Nodo* ABB::buscarMinimo(Nodo* raizSubarbol)
{
    // Asegurarse de que la raiz del subarbol no es NULL
    assertdomjudge(raizSubarbol != NULL);

    Nodo* minimo = new Nodo();

    // Si NULL devolver raizSubarbol
    if(raizSubarbol->hijoIzquierdo == NULL)
    {
        minimo = raizSubarbol;
    }
    // Continuar moviendose hacia la izquierda hasta encontrar el nodo minimo
    else
    {
        minimo = buscarMinimo(raizSubarbol->hijoIzquierdo);
    }

    return minimo;
}

// Eliminar un nodo especifico en el arbol
void ABB::eliminarNodo(Nodo* nodoAEliminar)
{
    // Verifica que el nodo a eliminar no sea NULL
    assertdomjudge(nodoAEliminar != NULL);

    // Nodo temporal para manejar la eliminacion
    Nodo* eliminarElemento = new Nodo();

    // Caso 1: El nodo no tiene hijos
    if(nodoAEliminar->hijoDerecho == NULL && nodoAEliminar->hijoIzquierdo == NULL)
    { 
        // Si el nodo es la raiz, el arbol queda vacio
        if(nodoAEliminar == raiz)
        {
            raiz = NULL;
        }
        // Si el nodo es el hijo derecho de su padre, lo elimina
        else if(nodoAEliminar == nodoAEliminar->padre->hijoDerecho)
        {
            nodoAEliminar->padre->hijoDerecho = NULL;
        }
        // Si el nodo es el hijo izquierdo de su padre, lo elimina
        else
        {
            nodoAEliminar->padre->hijoIzquierdo = NULL;
        }
        // Libera la memoria del nodo eliminado
        delete nodoAEliminar;
    }
    else
    {
        // Caso 2: El nodo solo tiene un hijo izquierdo
        if(nodoAEliminar->hijoDerecho == NULL && nodoAEliminar->hijoIzquierdo != NULL)
        { 
            // Encuentra el nodo con el valor maximo en el subarbol izquierdo
            eliminarElemento = buscarMaximo(nodoAEliminar->hijoIzquierdo);
            // Reemplaza el contenido del nodo a eliminar con el contenido del nodo encontrado
            nodoAEliminar->contenido = eliminarElemento->contenido;
            // Elimina el nodo encontrado
            eliminarNodo(eliminarElemento);
        }
        // Caso 3: El nodo solo tiene un hijo derecho
        else if(nodoAEliminar->hijoDerecho != NULL && nodoAEliminar->hijoIzquierdo == NULL)
        { 
            // Encuentra el nodo con el valor minimo en el subarbol derecho
            eliminarElemento = buscarMinimo(nodoAEliminar->hijoDerecho);
            // Reemplaza el contenido del nodo a eliminar con el contenido del nodo encontrado
            nodoAEliminar->contenido = eliminarElemento->contenido;
            // Elimina el nodo encontrado
            eliminarNodo(eliminarElemento);
        }
        // Caso 4: El nodo tiene dos hijos
        else if(nodoAEliminar->hijoDerecho != NULL && nodoAEliminar->hijoIzquierdo != NULL)
        { 
            // Si el subarbol derecho es mas alto que el izquierdo
            if(alturaNodo(nodoAEliminar->hijoDerecho) > alturaNodo(nodoAEliminar->hijoIzquierdo))
            { 
                // Encuentra el nodo con el valor minimo en el subarbol derecho
                eliminarElemento = buscarMinimo(nodoAEliminar->hijoDerecho);
                // Reemplaza el contenido del nodo a eliminar con el contenido del nodo encontrado
                nodoAEliminar->contenido = eliminarElemento->contenido;
                // Elimina el nodo encontrado
                eliminarNodo(eliminarElemento);
            }
            else
            {
                // Encuentra el nodo con el valor maximo en el subarbol izquierdo
                eliminarElemento = buscarMaximo(nodoAEliminar->hijoIzquierdo);
                // Reemplaza el contenido del nodo a eliminar con el contenido del nodo encontrado
                nodoAEliminar->contenido = eliminarElemento->contenido;
                // Elimina el nodo encontrado
                eliminarNodo(eliminarElemento);
            }
        }
    }
}

// Calcular la altura de un nodo
int ABB::alturaNodo(Nodo* raizSubarbol)
{
    // Si el nodo es NULL, su altura es -1
    if(raizSubarbol == NULL)
    {
        return -1;
    }

    // Calcula la altura de los subarboles izquierdo y derecho
    int alturaDerecha = alturaNodo(raizSubarbol->hijoDerecho);
    int alturaIzquierda = alturaNodo(raizSubarbol->hijoIzquierdo);

    // Retorna la altura maxima mas uno
    if(alturaIzquierda > alturaDerecha)
    {
        return alturaIzquierda + 1;
    }
    else
    {
        return alturaDerecha + 1;
    }

}

// Imprimir el recorrido del arbol
void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

// Verificar si un subarbol es un ABB
bool ABB::esSubABB(Nodo* raizSubarbol)
{
    // Un arbol vacio es un ABB valido
    if(raizSubarbol == NULL)
    {
        return true;
    }
    else
    {
        // Inicializa la variable esABBI como true
        bool esABBI = true;
        // Verifica si el subarbol izquierdo cumple con las propiedades de un ABB
        if(raizSubarbol->hijoIzquierdo != NULL)
        {
            // El subarbol izquierdo debe tener valores menores al nodo actual y tambien ser un ABB
            esABBI = (buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido < raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoIzquierdo);
        }

        // Inicializa la variable esABBD como true
        bool esABBD = true;
        // Verifica si el subarbol derecho cumple con las propiedades de un ABB
        if(raizSubarbol->hijoDerecho != NULL)
        {
            // El subarbol derecho debe tener valores mayores al nodo actual y tambien ser un ABB
            esABBD = (buscarMinimo(raizSubarbol->hijoDerecho)->contenido > raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoDerecho);
        }

        // El subarbol es un ABB si ambos subarboles izquierdo y derecho cumplen con las propiedades de un ABB
        return (esABBI && esABBD);
    }
}

// Verificar si un subarbol es AVL
bool ABB::esSubAVL(Nodo* raizSubarbol)
{
    // Verifica que el nodo no sea NULL
    if(raizSubarbol == NULL)
    {
        return true;
    }

    int diferencia = alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho);

    // Verifica la condicion de balanceo AVL
    if(diferencia > 1 || diferencia < -1)
    {
        return false;
    }

    // Verifica recursivamente los subarboles izquierdo y derecho
    return esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho);
}

// Leer un subarbol desde la entrada estandar
Nodo* ABB::leerSubarbol(Nodo* padre)
{
    int contenido;
    cin >> contenido;
    if(contenido >= 0) 
    {
        Nodo* arbol = new Nodo;
        arbol->contenido = contenido;
        arbol->hijoIzquierdo = leerSubarbol(arbol);
        arbol->hijoDerecho = leerSubarbol(arbol);
        arbol->padre = padre;
        return arbol;
    }
    else
    {
        return NULL;
    }
}