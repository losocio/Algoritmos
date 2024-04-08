#include "ListaContigua.h"

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
    capacidad=0;

    /* 
    // NOTE: La capacidad debe crecer al intentar insertar un nuevo elemento, no al llenarse la capacidad
    // Mi implementacion no esta mal, solo es otra forma de hacerlo

    // La lista comienza con capacidad del tamaño del incremento
    capacidad=incremento;
    */

    // Reservo memoria del tamaño del incremento
    vector=(int*)malloc(sizeof(int)*capacidad);

    // NOTE: Problemas al usar memoria dinamica de c y c++
    // vector=new int[capacidad];
	
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
    // Compruebo que se accede un valor posible
    // NOTE: Es <=n y no <n porque asi puedo añadir un elemento al final de la lista
    assertdomjudge(posicion>=0 && posicion<=n);
    
    // Si al insertar el nuevo elemento llenamos el vector, los aumentamos por el incremento
    if(n==capacidad)
    {   
        // Aumento la capacidad por el incremento
        capacidad+=incremento;

        // Reservo memoria con la nueva capacidad aumentada
        vector = (int*) realloc(vector, sizeof(int)*capacidad);

        // Esto es muy raro profe :/
        // NOTE: Por alguna razon funciona si le paso el numero de elementos y no la cantidad de bytes
        // vector = (int*) realloc(vector, capacidad);
    }

    // Desplazo los elementos una posicion a la derecha
    memmove(&vector[posicion+1], &vector[posicion], sizeof(int)*(n-posicion));

    // Inserto el nuevo valor
    vector[posicion]=nuevoValor;
    
    // Incremento n
    n++;


    /* NOTE: La capacidad debe crecer al intentar insertar un nuevo elemento, no al llenarse la capacidad
    // Mi implementacion no esta mal, solo es otra forma de hacerlo

    // Desplazo los elementos una posicion a la derecha
    memmove(&vector[posicion+1], &vector[posicion], sizeof(int)*(n-posicion));

    // Inserto el nuevo valor
    vector[posicion]=nuevoValor;
    
    // Incremento n
    n++;

    // Si al insertar el nuevo elemento llenamos el vector, los aumentamos por el incremento
    if(n==capacidad)
    {   
        // Aumento la capacidad por el incremento
        capacidad+=incremento;

        // Reservo memoria con la nueva capacidad aumentada
        vector = (int*) realloc(vector, sizeof(int)*capacidad);

        // Esto es muy raro profe :/
        // NOTE: Por alguna razon funciona si le paso el numero de elementos y no la cantidad de bytes
        // vector = (int*) realloc(vector, capacidad);
    }
    */

    return;
}


// Eliminar un elemento de la posicion elegida de la lista
void ListaContigua::eliminar(int posicion)
{
    // Compruebo que se accede un valor posible
    assertdomjudge(posicion>=0 && posicion<n);

    // Desplazo los elementos a la derecha, machacando el elemento a eliminar
    memmove(&vector[posicion], &vector[posicion+1], sizeof(int)*(n-posicion));

    // Decremento n
    n--;

    // FIXED: if((capacidad-n)>=incremento), era incorrecto
    // Si eliminando un elemento la capacidad el mayor que 2*incremento la disminuyo
    if(n<=(capacidad-2*incremento))
    {   
        // Disminuyo la capacidad por el incremento
        capacidad-=incremento;

        // Reservo memoria con la nueva capacidad aumentada
        vector=(int*) realloc(vector, sizeof(int)*capacidad);
    }
    
    /* NOTE: La capacidad debe crecer al intentar insertar un nuevo elemento, no al llenarse la capacidad
    // Mi implementacion no esta mal, solo es otra forma de hacerlo

    // Desplazo los elementos a la derecha, machacando el elemento a eliminar
    memmove(&vector[posicion], &vector[posicion+1], sizeof(int)*(n-posicion));

    // Decremento n
    n--;

    // Si eliminando un elemento la capacidad el mayor que 2*incremento la disminuyo
    // FIXED: if(capacidad-n>2*incremento) estaba mal
    if(capacidad-n>incremento)
    {   
        // Disminuyo la capacidad por el incremento
        capacidad-=incremento;

        // Reservo memoria con la nueva capacidad aumentada
        vector=(int*) realloc(vector, sizeof(int)*capacidad);
    }
    */

    return;
}

// Concatena dos listas
void ListaContigua::concatenar(ListaContigua *listaAConcatenar)
{
    // NOTE: Esta precondicion puede ser demasiado restrictiva para el domjudge
    // Compruebo que la lista a concatenar tiene algun elemento
    // assertdomjudge(listaAConcatenar->n>0);
    
    // Implementacion sin sumar la capacidad del segundo vector
    
    // Actualizo la capacidad
    capacidad+=listaAConcatenar->n; // NOTE: no guardo la capacidad del segundo vector

    // Reservo memoria para acomodar los elementos del primer vector, su incremento y los elementos del segundo
    // No reservo memoria para el incremento del segundo
    vector=(int*) realloc(vector, sizeof(int)*(capacidad));
  
    // Añado los elementos del segundo vector, pero no su capacidad
    memmove(&vector[n], listaAConcatenar->vector, sizeof(int)*listaAConcatenar->n);
    
    // Actualizo n
    n+=listaAConcatenar->n;


    /* NOTE: Implementacion sumando la capacidad del segundo vector
    
    // Actualizo los contadores de n y capacidad
    n+=listaAConcatenar->n;
    capacidad+=listaAConcatenar->capacidad; // NOTE: no guardo la capacidad del segundo vector

    // Reservo memoria para acomodar los elementos del primer vector, su incremento y los elementos del segundo
    // No reservo memoria para el incremento del segundo
    vector=(int*) realloc(vector, sizeof(int)*capacidad);
  
    // Añado los elementos del segundo vector, pero no su capacidad
    memmove(&vector[n], listaAConcatenar->vector, sizeof(int)*(listaAConcatenar->capacidad));

    */

    return;
}

// Encontrar el indice del elemento a buscar
int ListaContigua::buscar(int elementoABuscar)
{
    int i=0;

    // Aumento el contador de indice hasta encontar el valor buscado o cuando se llega al final de la lista
    while(vector[i]!=elementoABuscar && i<n) i++;

    // FIXED: Estaba mal la condicion
    // while(vector[i]!=elementoABuscar || i<n) i++;

    // Si el indice es igual al tamaño de la lista lo cambio por -1
    if(i==n) i=-1;

    // Devuelvo el indice o -1
    return i;
    

    /* NOTE: he pensado algo mejor
    int indiceEncontrado=-1;

    for(int i=0;i<n;i++)
    {
        if(vector[i]==elementoABuscar) 
        {
            indiceEncontrado=i;
            break;
        }       
    }

    return indiceEncontrado;
    */

    /* NOTE: esta implementacion esta mal, si no se encuentra el elemento se pasa de memoria
    int i=-1;
    
    do i++;
    while(vector[i]!=elementoABuscar);

    return i;
    */
}

// Destructor
ListaContigua::~ListaContigua()
{
    free(vector);

    // NOTE: Problemas al usar memoria dinamica de c y c++
    // delete [] vector;
}