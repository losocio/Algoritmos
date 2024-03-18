#include "ListaContigua.h"
//#include "assetdomjudge.h"

/* TODO
    Creo que aqui hay que poner * :
    memmove(*vector[posicion+1], *vector[posicion], (n-posicion)*sizeof(int));


*/


ListaContigua::ListaContigua(int incremento)
{
    // NOTE: Aqui es estrictamente necesario usar this, por ser llamarse igual las variables. This Is Not Java
    this->incremento=incremento;

    // TODO: entiendo que comienzan a 0 al estar vacia la lista
    // 
	n=0;

    // TODO: La lista comienza con capacidad del tamaño des incremento
	capacidad=incremento;

    //int *vector;
    vector=new int[capacidad];
	
}

ListaContigua::~ListaContigua()
{
    delete [] vector;
}

int ListaContigua::getValor(int posicion)
{
    //TODO: Precondicion de que exista un valor para ese indice
    assertdomjudge(posicion<=n);
    return vector[posicion];
}


ListaContigua::setValor(int posicion, int nuevoValor)
{
    //TODO: precondicion de que el valor haya sido insertado
    assertdomjudge(posicion<=n);
    vector[posicion]=nuevoValor;
    return;
}


int ListaContigua::getN() 
{
    return n;
}


int ListaContigua::getCapacidad() 
{
    return capacidad;
}


ListaContigua::insertar(int posicion, int nuevoValor)
{
    //TODO: precondicion, puede que este MAL
    assertdomjudge(posicion<=n);

    // TODO: condicion que compruebe si queda espacio en el vector, si no hay crecerlo por el incremento
    if(n>=capacidad)
    {   
        //void *realloc(void *ptr, size_t size)
        //void *realloc(puntero a la memoria dinamica por redimensionar, nuevo tamaño total)
        
        // 
        realloc(vector, capacidad+incremento);

        // Aumento la capacidad para reflejar los cambios
        capacidad+=incremento;
    }

    //void *memmove(void *str1, const void *str2, size_t n)
    //void *memmove(vector destino, vector origen, Numero de bytes a mover)
    memmove(vector[posicion+1], vector[posicion], (n-posicion)*sizeof(int));

    // Inserto el valor
    vector[posicion]=nuevoValor;
    
    //TODO: incrementar n
    n++;

    //void *realloc(void *ptr, size_t size)
    return;
}


ListaContigua::eliminar(int posicion)
{
    //TODO: precondicion, puede que este MAL
    assertdomjudge(posicion<=n);

    //void *memmove(void *str1, const void *str2, size_t n)
    //void *memmove(vector destino, vector origen, Numero de bytes a mover)
    memmove(vector[posicion], vector[posicion+1], (n-posicion)*sizeof(int)); //TODO: poner bien el tamaño este

    return;
}


ListaContigua::concatenar(ListaContigua *listaAConcatenar)
{
    // Aumento el vectro para poder añadir los elemetos del otro vector
    realloc(vector, capacidad+listaAConcatenar->capacidad);
    memmove(*vector[FINAL], listaAConcatenar->vector, (n-posicion)*sizeof(int));

    return;
}


int ListaContigua::buscar(int elementoABuscar)
{
    int i=-1;
    do
    {
        i++;
    }while(vector[i]!=elementoABuscar);

    return vector[i];
}
