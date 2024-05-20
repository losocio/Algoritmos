#include "ColaPrioridad.h"
#include <iostream>
using namespace std;

//HIJO I: POS PADRE *2
//HIJO D: POS PADRE *2 -1

/*COLOCAR EN ULTIMO ELEMENTO QUE CORRESPONDERIA(FINAL)
* REESTRUCTURAR: COMPRUEBO VALOR PADRE (SUMAR 1 DIVIDIR /2)
*	SI MENOR QUE PADRE INTERCAMBIO
*	REPETIR HASTA LLEGAR A RAIZ
*/
void ColaPrioridad::encolar(int nuevoElemento) {
	//Insertar valor al final
	this->vector.insertarAlFinal(nuevoElemento);
	
	this->reestructurar();
	////Comprobar que está en el lugar correcto
	//bool finMovimiento = false;
	//int posNuevo = this->vector.buscar(nuevoElemento);
	//int posPadre;
	//if (posNuevo % 2 == 0) {
	//	posPadre = posNuevo / 2;
	//}
	//else {
	//	posPadre = (posNuevo - 1) / 2;
	//}

	//while (!finMovimiento) {
	//	if (this->vector.getValor(posNuevo) < this->vector.getValor(posPadre)) {
	//		//Cambio de valores
	//		int auxCambio = this->vector.getValor(posNuevo);
	//		this->vector.setValor(posNuevo, this->vector.getValor(posPadre));
	//		this->vector.setValor(posPadre, auxCambio);
	//		//Asignar nuevos valores a variables para siguiente ciclo
	//		posNuevo = this->vector.buscar(nuevoElemento);
	//		if (posNuevo % 2 == 0) {
	//			posPadre = posNuevo / 2;
	//		}
	//		else {
	//			posPadre = (posNuevo - 1) / 2;
	//		}
	//	}
	//	else {
	//		//Nada más que cambiar
	//		finMovimiento = true;
	//	}
	//}
}

/*COGER ELEMENTO CABEZA PARA DEVOLVER
* INTERCAMBIAR CON ULTIMO
* REESTRUCTURAR
*/
int ColaPrioridad::desencolar() {
	int valor = this->vector.getValor(0);
	//El primer elemento será sustituido por el último elemento.
	this->vector.setValor(0, this->vector.getValor(this->vector.getN() - 1));
	//El último elemento de la cola será eliminado
	this->vector.eliminarAlFinal();
	//Se deberá reestructurar el montículo usando el método reestructurar.
	this->reestructurar();

	return valor;
}

bool ColaPrioridad::estaVacia() {
	return (this->vector.getN() == 0);
}

/* REESTRUCTURAR: COMPRUEBO VALOR PADRE (SUMAR 1 DIVIDIR /2)
*	SI MENOR QUE PADRE INTERCAMBIO
*	REPETIR HASTA LLEGAR A RAIZ 
*/
void ColaPrioridad::reestructurar() {
	for (int i = 0; i < this->vector.getN() - 1; i++) {
		// Last i elements are already 
		// in place 
		for (int j = 0; j < (this->vector.getN() - i) - 1; j++) {
			if (this->vector.getValor(j) > this->vector.getValor(j+1)) {
				int auxCambio = this->vector.getValor(j);
				this->vector.setValor(j, this->vector.getValor(j+1));
				this->vector.setValor(j+1, auxCambio);
			}
		}	
	}

	//int posComprob = 0;
	//int posHijoI = 1;
	//int posHijoD = 2;

	//bool finMovimiento = false;
	////Mientras el padre sea mayor que ambos hijos, se mueve hacia abajo
	//if (this->vector.getN() <= 1) {

	//}
	//else if (this->vector.getN() == 2) {
	//	if (this->vector.getValor(posComprob) > this->vector.getValor(posHijoI)) {
	//		//Cambio de valores
	//		int auxCambio = this->vector.getValor(posComprob);
	//		this->vector.setValor(posComprob, this->vector.getValor(posHijoI));
	//		this->vector.setValor(posHijoI, auxCambio);
	//		posComprob = posHijoI;
	//	}
	//}
	//else {
	//	while (!finMovimiento) {
	//		if (this->vector.getValor(posComprob) > this->vector.getValor(posHijoI) && this->vector.getValor(posComprob) > this->vector.getValor(posHijoD)) {
	//			if (this->vector.getValor(posHijoD) < this->vector.getValor(posHijoI)) {
	//				//Cambio de valores
	//				int auxCambio = this->vector.getValor(posComprob);
	//				this->vector.setValor(posComprob, this->vector.getValor(posHijoD));
	//				this->vector.setValor(posHijoD, auxCambio);
	//				posComprob = posHijoD;
	//			}
	//			else {
	//				//Cambio de valores
	//				int auxCambio = this->vector.getValor(posComprob);
	//				this->vector.setValor(posComprob, this->vector.getValor(posHijoI));
	//				this->vector.setValor(posHijoI, auxCambio);
	//				posComprob = posHijoI;
	//			}
	//			posHijoI = (posComprob * 2) - 1;
	//			posHijoD = posComprob * 2;
	//		}
	//		else {
	//			finMovimiento = true;
	//		}
	//	}
	//}
}