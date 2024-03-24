#include "ListaContigua.h"
//#include "assertdomjudge.h"

/* TODO
    Creo que aqui hay que poner & :
    memmove(&vector[posicion+1], &vector[posicion], (n-posicion)*sizeof(int));


*/

// Constructor de ListaContigua
ListaContigua::ListaContigua(int incremento)
{
    // El incremento tiene que ser mayor que 0
    assertdomjudge(incremento>0);

    // NOTE: Aqui es estrictamente necesario usar this, por ser llamarse igual las variables. This Is Not Java
    this->incremento=incremento;

    // La lista empieza vacia
	n=0;

    // La lista comienza con capacidad del tamaño del incremento
	capacidad=incremento;

    // Reservo memoria del tamaño del incremento
    vector=new int[capacidad];
	
}

// Leer un valor segun su indice
int ListaContigua::getValor(int posicion)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<n);

    // Devuelvo valor
    return vector[posicion];
}

// Cambia un valor segun su posicion, perdiendo lo que se guardaba ahi
void ListaContigua::setValor(int posicion, int nuevoValor)
{
    // Compruebo que se accede un valor posible
    // NOTE: "OJO: Este elemento tenía que haberse insertado anteriormente"
    // NOTE: No se puede dar valor a un espacio que este reservado en la capacidad si no tiene una valor ya asignado, se debe insertar primero
    assertdomjudge(posicion>=0 && posicion<n);

    // Cambio el valor
    vector[posicion]=nuevoValor;
    
    return;
}

// Devuelve la cantidad de elementos contenidos en la lista
int ListaContigua::getN() 
{
    return n;
}

// Devuelve la capacidad actual de la lista
int ListaContigua::getCapacidad() 
{
    return capacidad;
}

// Insertar un valor en la lista en la posicion elegida, desplazando los elementos de la derecha a la derecha
void ListaContigua::insertar(int posicion, int nuevoValor)
{

    /* NOTE: Esto estaria mal, ya que los elementos tiene que estar siempre seguidos
    Si pudiese insertar en cualquier parde del incremento este no seria el caso
    
    // Aqui uso capacidad en vez de n, este metodo puede expandir la lista
    assertdomjudge(posicion>=0 && posicion<capacidad);
    */

    // Compruebo que se accede un valor posible
    // NOTE: Es <=n y no <n porque asi puedo añadir un elemento al final de la lista
    assertdomjudge(posicion>=0 && posicion<=n);
    

    // Desplazo los elementos una posicion a la derecha
    // void *memmove(void *str1, const void *str2, size_t n)
    // void *memmove(vector destino, vector origen, Numero de bytes a mover)
    memmove(&vector[posicion+1], &vector[posicion], sizeof(int)*(n-posicion)); // TODO: puede ser n-pos-1

    // Inserto el nuevo valor
    vector[posicion]=nuevoValor;
    
    //Incremento n
    n++;

    // Si al insertar el nuevo elemento llenamos el vector, los aumentamos por el incremento
    if(n>=capacidad)
    {   
        // Aumento la capacidad por el incremento
        capacidad+=incremento;

        // void *realloc(void *ptr, size_t size)
        // void *realloc(puntero a la memoria dinamica por redimensionar, nuevo tamaño total)
        // Reservo memoria con la nueva capacidad aumentada
        vector = (int*) realloc(vector, capacidad);
    }
    
    return;
}

// Eliminar un elemento de la posicion elegida de la lista
void ListaContigua::eliminar(int posicion)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<n);

    // void *memmove(void *str1, const void *str2, size_t n)
    // void *memmove(vector destino, vector origen, Numero de bytes a mover)
    // Desplazo los elementos a la derecha, machacando el elemento a eliminar
    memmove(&vector[posicion], &vector[posicion+1], sizeof(int)*(n-posicion)); // TODO: puede ser n-pos-1

    // Decremento n
    n--;

    // Si eliminando un elemento la capacidad el mayor que 2*incremento la disminuyo
    if(capacidad-n>2*incremento)
    {   
        // Aumento la capacidad por el incremento
        capacidad-=incremento;

        // void *realloc(void *ptr, size_t size)
        // void *realloc(puntero a la memoria dinamica por redimensionar, nuevo tamaño total)
        // Reservo memoria con la nueva capacidad aumentada
        vector=(int*) realloc(vector, capacidad);
    }

    return;
}

// Concatena dos listas
void ListaContigua::concatenar(ListaContigua *listaAConcatenar)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(listaAConcatenar->n>=0);
    
    // Aumento el vector para poder añadir los elemetos del otro vector
    vector=(int*) realloc(vector, capacidad+listaAConcatenar->n);
    
    // void *memmove(void *str1, const void *str2, size_t n)
    // void *memmove(vector destino, vector origen, Numero de bytes a mover)
    // Añado los elemento del otro vector
    memmove(&vector[n], listaAConcatenar->vector, sizeof(int)*(listaAConcatenar->n));

    // Actualizo los contadores de n y capacidad
    n=n+listaAConcatenar->n;
    capacidad=capacidad+listaAConcatenar->n;
    
    return;
}

// Encontrar el indice del elemento a buscar
int ListaContigua::buscar(int elementoABuscar)
{
    int indiceEncontrado=-1;

    for(int i=0;i<n;i++)
    {
        if(vector[i]==elementoABuscar) indiceEncontrado=i;
        i++;    
    }

    return indiceEncontrado;


    /* NOTE: esta implementacion esta mal, si no se encuentra el elemento se devulve el ultimo
    int i=-1;
    
    do i++;
    while(vector[i]!=elementoABuscar);

    return i;
    */
}

ListaContigua::~ListaContigua()
{
    delete [] vector;
}