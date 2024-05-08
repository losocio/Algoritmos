#include "AgendaDispersionAbierta.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash

//using namespace std;

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

