#include "Matriz.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Constructor por defecto
//Matriz::Matriz() : matriz(NULL), n_filas(0), n_columnas(0) {} //Uso intializer lists, algo nuevo de c++
Matriz::Matriz(){
    n_filas=0;
    n_columnas=0;
    matriz=NULL;
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
    //Numero de filas y columnas
    this->n_filas = n_filas; //NOTE aqui es estrictamente necesario usar this, sino no se crea la matriz correctamente. Esto no es Java
    this->n_columnas = n_columnas;

    //Reservo un array de punteros a double para guardar la columnas
    matriz = new double* [n_filas]; //NOTE aqui No es necesario poner this

	//Lleno esos punteros con arrays que seran las columnas
	for(int i=0;i<n_filas;i++){
		matriz[i]=new double[n_columnas];
	}
    
}

//Constructor copia
//Matriz::Matriz(Matriz & matrizOld) : matriz(matrizOld->matrin_filas(matrizOld->n_filas), n_columnas(matrizOld->n_columnas) {}
Matriz::Matriz(Matriz& m) {
    
    //assertdomjudge(matriz);
	//Copio numero de filas y columnas
	n_filas=m.n_filas; //NOTE No uso la flecha para las filas, ya que es una referencia. Con punteros si
	n_columnas=m.n_columnas;

    /*
	//Esto esta mal. Solo creo una nueva referencia a la matriz original, no cero una segunda copia
	matriz=matriz.matriz;
    */

    //Copio los elementos de la matriz original a una nueva
    matriz = new double* [n_filas];
    for(int i = 0;i<n_filas;i++){
        matriz[i]=new double[n_columnas];
        for(int j=0;j<n_columnas;j++){
            assertdomjudge(m.matriz[i][j]); //NOTE No era necesario comprobar que existe la matriz, seguramente no sera necesario en el resto de funcs
            matriz[i][j]=m.matriz[i][j]; 
        }
    }
}

//Destructor
Matriz::~Matriz() {
    assertdomjudge(matriz); //No era necesario
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

    //TODO no se si te puedes saltar los this ->
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

    //No creo que sea necesario usar ()
    return ( * this);
}

//Suma de matrices
Matriz& Matriz::operator + (const Matriz & m2) {
    //TODO Assert para que las dimensiones sean iguales
    //TODO asser para que existan las matrices
    Matriz *resultado = new Matriz(m2.n_filas, m2.n_columnas);
    
    for(int i=0;i<m2.n_filas;i++){
        for(int j=0;j<m2.n_columnas;j++){
            resultado->matriz[i][j]=matriz[i][j]+m2.matriz[i][j];
        }
    }

    //TODO understand this referencing
    return *resultado;
}

//Resta de matrices
Matriz& Matriz::operator - (const Matriz & m2) {
    //TODO Assert para que las dimensiones sean iguales
    //TODO asser para que existan las matrices
    Matriz* resultado = new Matriz(m2.n_filas, m2.n_columnas);
    
    for(int i=0;i<m2.n_filas;i++){
        for(int j=0;j<m2.n_columnas;j++){
            resultado->matriz[i][j]=matriz[i][j]-m2.matriz[i][j];
        }
    }

    return *resultado;
}

//TODO no se si se puede M*3 y 3*M
//Producto de matriz por escalar
Matriz & Matriz::operator * (const double & escalar) {

    //TODO assert para que exista la matriz
    Matriz* resultado = new Matriz(n_filas, n_columnas);
    
    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            resultado->matriz[i][j]=matriz[i][j]*escalar;
        }
    }

    return *resultado;
}

//Producto de matriz por matriz
Matriz& Matriz::operator * (const Matriz & m2) {

    //TODO implementar el algoritmo
    //TODO assert para que exista la matriz
    //TODO assert dimensiones compatibles para multiplicar
    Matriz* resultado = new Matriz(n_filas, m2.n_columnas);
    
    double temp;
    for(int i=0;i<n_filas;i++){
        temp = 0;
        for(int j=0;j<n_columnas;j++){
            temp += matriz[i][j]*m2.matriz[j][i];
        }
        //resultado->matriz[i][j]=temp;
    }

    return *resultado;
}

//Calcular matriz traspuesta
Matriz& Matriz::calcularTraspuesta() {

    //Creo una nueva matriz con las filas cambiadas por la columnas
    Matriz* traspuesta = new Matriz(n_columnas, n_filas);

    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            //Sencillamente cambio las filas por la columnas, [2,3] -> [3,2]
            traspuesta->matriz[j][i]=matriz[i][j];
        }
    }

    return *traspuesta;
}

//Obtener elemento maximo de una matriz
double Matriz::obtenerMaximo() {
    //TODO assert para que exista la matriz
    //Le pongo una valor de la matriz por si esta tiene valores muy extremos
    double max=matriz[0][0];
    
    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            if(max<matriz[i][j]) max=matriz[i][j];
        }
    }

    return max;
}
 
//Obtener elemento minimo de una matriz
double Matriz::obtenerMinimo() {
    //TODO assert para que exista la matriz
    
    //Le pongo una valor de la matriz por si esta tiene valores muy extremos
    //NOTE bien esto esta bien hecho
    double min=matriz[0][0];

    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            if(min>matriz[i][j]) min=matriz[i][j];
        }
    }

    return min;
}

//Comprobar simetria
bool Matriz::esSimetrica(){
    //TODO assert si es cuadrada
    bool simetrica=true;

    //TODO implementar de manera que te saltas
    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_columnas;j++){
            if(matriz[i][j]!=matriz[j][i]) simetrica=false;
        }
    }

    return simetrica;
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
    for (int i = 0; i < n_filas; i++){
        for (int j = 0; j < n_columnas; j++){
            matriz[i][j] = rand();
        }
    }
}

// Imprimir Matriz
void Matriz::mostrarMatriz() {
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_columnas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}