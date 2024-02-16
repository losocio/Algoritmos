#include "Matriz.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Constructor por defecto
//Matriz::Matriz() : matriz(NULL), n_filas(0), n_columnas(0) {} //Uso intializer lists, algo nuevo de c++
Matriz::Matriz(){
    matriz=NULL;

    n_filas=0;
    n_columnas=0;
}

//Constructor por parametros
/*Matriz::Matriz(int n_filas, int n_columnas) : n_filas(n_filas) n_columnas(n_columnas){
	//Reservo un array de punteros a int para guardar la columnas
    matriz = new int* [n_filas];

	//Lleno esos punteros con arrays que seran las columnas
	for(int i=0;i<n_filas;i++){
		matriz[i]=new int[n_columnas];
	}
}*/
Matriz::Matriz(int n_filas, int n_columnas) {
    n_filas = n_filas;
    n_columnas = n_columnas;

    //Reservo un array de punteros a int para guardar la columnas
    matriz = new double* [n_filas];

	//Lleno esos punteros con arrays que seran las columnas
	for(int i=0;i<n_filas;i++){
		matriz[i]=new double[n_columnas];
	}
}

//Constructor copia
//Matriz::Matriz(Matriz & matrizOld) : matriz(matrizOld->matrin_filas(matrizOld->n_filas), n_columnas(matrizOld->n_columnas) {}
Matriz::Matriz(Matriz & matrizAntigua) {
    
    //assertdomjudge(matrizAntigua);
	//Copio numero de filas y columnas
	n_filas=matrizAntigua.n_filas; //No uso la flecha, ya que es una referencia. Con punteros si
	n_columnas=matrizAntigua.n_columnas;

    /*
	//Esto esta mal. Solo creo una nueva referencia a la matriz original, no cero una segunda copia
	matriz=matriz.matriz;
    */

    //Copio los elementos de la matriz original a una nueva
    matriz = new double* [n_filas];
    for(int i = 0;i<matrizAntigua.n_filas;i++){
        matriz[i]=new double[n_columnas];
        for(int j=0;j<n_columnas;j++){
            assertdomjudge(matrizAntigua.matriz[i][j]);
            matriz[i][j]=matrizAntigua.matriz[i][j]; 
        }
    }
}

//Destructor
Matriz::~Matriz() {
    assertdomjudge(matriz);
    for(int i=0;i<n_filas;i++){
        delete [] matriz[i];
    }
    delete matriz;
}

//Asignacion de matrices
Matriz& Matriz::operator = (const Matriz & m) {
    if (matriz != NULL) {
        for (int i = 0; i < n_filas; i++)
            delete[] matriz[i];

        delete[] matriz;
        matriz = NULL;
    }

    this -> n_filas = m.n_filas;
    this -> n_columnas = m.n_columnas;
    this -> matriz = NULL;
    if (n_filas > 0 && n_columnas > 0) {
        matriz = new double * [n_filas];

        for (int i = 0; i < n_filas; i++) {
            matriz[i] = new double[n_columnas];
            for (int j = 0; j < n_columnas; j++)
                matriz[i][j] = m.matriz[i][j];
        }
    }

    return ( * this);
}

//Suma de matrices
Matriz& Matriz::operator + (const Matriz & m2) {
    //TODO Assert para que las dimensiones sean iguales
    //TODO asser para que existan las matrices
    Matriz resultado = new Matriz(m2.n_filas, m2.n_columnas);
    
    for(int i=0;i<m2.n_filas;i++){
        for(int j=0;j<m2.n_columnas;j++){
            resultado.matriz[i][j]=matriz[i][j]+m2.matriz[i][j];
        }
    }

    return resultado;
}

//Resta de matrices
Matriz& Matriz::operator - (const Matriz & m2) {
    //TODO Assert para que las dimensiones sean iguales
    //TODO asser para que existan las matrices
    Matriz resultado = new Matriz(m2.n_filas, m2.n_columnas);
    
    for(int i=0;i<m2.n_filas;i++){
        for(int j=0;j<m2.n_columnas;j++){
            resultado.matriz[i][j]=matriz[i][j]-m2.matriz[i][j];
        }
    }

    return resultado;
}

//TODO no se si se puede M*3 y 3*M
//Producto de matriz por escalar
Matriz & Matriz::operator * (const double & escalar) {

    //TODO assert para que exista la matriz
    Matriz resultado = new Matriz(n_filas, n_columnas);
    
    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            resultado.matriz[i][j]=matriz[i][j]*escalar;
        }
    }

    return resultado;
}

//Producto de matriz por matriz
Matriz& Matriz::operator * (const Matriz & m2) {

    //TODO implementar el algoritmo
    //TODO assert para que exista la matriz
    Matriz resultado = new Matriz(n_filas, n_columnas);
    
    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            resultado.matriz[i][j]=matriz[i][j]*escalar;
        }
    }

    return resultado;
}

//Caluclar matriz traspuesta
Matriz calcularTraspuesta(const Matriz &m1) {

    //Creo una nueva matriz con las filas cambiadas por la columnas
    Matriz traspuesta = new Matriz(m1.n_columnas, m1.n_filas);

    for(int i=0;i<m1.n_filas;i++){
        for(int j=0;j<m1.n_columnas;j++){
            //Sencillamente cambio las filas por la columnas, [2,3] -> [3,2]
            traspuesta.matriz[j][i]=m1.matriz[i][j];
        }
    }

    return traspuesta;
}

//Obtener elemento maximo de una matriz
double Matriz::obtenerMaximo(const Matriz &m) {
    //TODO assert para que exista la matriz
    //Le pongo una valor de la matriz por si esta tiene valores muy extremos
    double max=m.matriz[0][0];
    
    for(int i=0;i<m1.n_filas;i++){
        for(int j=0;j<m1.n_columnas;j++){
            if(max<m.matriz[i][j]) max=m.matriz[i][j];
        }
    }

    return max;
}
 
//Obtener elemento minimo de una matriz
double Matriz::obtenerMinimo(const Matriz &m) {
    //TODO assert para que exista la matriz
    
    //Le pongo una valor de la matriz por si esta tiene valores muy extremos
    double min=m.matriz[0][0];

    for(int i=0;i<m1.n_filas;i++){
        for(int j=0;j<m1.n_columnas;j++){
            if(min>m.matriz[i][j]) min=m.matriz[i][j];
        }
    }

    return min;
}

// Leer matriz
void Matriz::rellenarManual() {
    double elemento;
    for (int i = 0; i < n_filas; i++) {
        cout << "Fila " << i << endl;
        for (int j = 0; j < n_columnas; j++) {
            cout << "Elemento " << j << endl;
            cin >> elemento;
            matriz[i][j] = elemento;
        }
        cout << endl;
    }

}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed) {
    srand(seed);
    for (int i = 0; i < n_filas; i++)
        for (int j = 0; j < n_columnas; j++)
            matriz[i][j] = rand();

}

// Imprimir Matriz
void Matriz::mostrarMatriz() {
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}