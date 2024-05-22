#include "Supermercado.h"
#include "assertdomjudge.h"
using namespace std;

// Constructor
Supermercado::Supermercado(int n) 
{
	assertdomjudge(n>0);

	n_cajas = n;

	cajas = new ColaPrioridad[n];
}

// Añade un nuevo usuario a una caja
void Supermercado::nuevoUsuario(int n, int id)
{
	assertdomjudge(n>=0 && n<n_cajas);
	
	cajas[n].encolar(id);

	return;
}

// Cerrar una caja, recolocando a sus usuarios
void Supermercado::cerrarCaja(int n)
{
	assertdomjudge(n>=0 && n<n_cajas);

	while(!cajaVacia(n))
	{
		for(int i=0; i<n_cajas; i++)
		{
			// 
			if(cajaVacia(n) || i==n) break;
			// 
			else cajas[i].encolar(cajas[n].desencolar());
		}
	}

	return;
}

// Atiende un usuario, sacandolo de la caja
int Supermercado::atenderUsuario(int n)
{
	assertdomjudge(n>=0 && n<n_cajas);

	return cajas[n].desencolar();
}

// Comprueba si la caja esta vacia
bool Supermercado::cajaVacia(int n)
{
	assertdomjudge(n>=0 && n<n_cajas);

	return cajas[n].estaVacia();
}