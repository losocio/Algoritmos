#include "Supermercado.h"
#include "assertdomjudge.h"
using namespace std;

Supermercado::Supermercado(int n) {
	cajas = new ColaPrioridad[n];
	this->n_cajas = n;
}

void Supermercado::nuevoUsuario(int n, int id) {
	assertdomjudge(n >= 0 && n < this->n_cajas);
	this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n) {
	assertdomjudge(n >= 0 && n < this->n_cajas);
	while (!this->cajaVacia(n)) {
		for (int i = 0; i < this->n_cajas; i++) {
			if (this->cajaVacia(n) == true || i == n) {
				break;
			}
			else {
 				this->cajas[i].encolar(this->cajas[n].desencolar());
			}
		}
	}
}

int Supermercado::atenderUsuario(int n) {
	assertdomjudge(n >= 0 && n < this->n_cajas);
	return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n) {
	assertdomjudge(n >= 0 && n < this->n_cajas);
	return this->cajas[n].estaVacia();
}