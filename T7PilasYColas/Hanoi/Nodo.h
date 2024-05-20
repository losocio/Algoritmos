#include <stdlib.h>

class Nodo
{
public:
	// Valor del nodo
	int valor;

	// Siguiente nodo
	Nodo *siguiente;
  
	// Constructor
  	Nodo(int v, Nodo *sig=NULL)
	{
		valor=v;
		siguiente=sig;
    }
};