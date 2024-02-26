#include"Matriz.h"
#include<iostream>

int main() {
    Matriz * temp = NULL;
    Matriz * copia = NULL;
    Matriz a, b, c;
    int n_filas;
    int n_columnas;
    double scalar;
    long semilla;

    cout << "Creando nueva matriz" << endl;
    cout << "Introduzca numero filas y columnas ";
    cin >> n_filas;
    cin >> n_columnas;
    temp = new Matriz(n_filas, n_columnas);
    temp -> rellenarManual();
    temp->mostrarMatrizIndices();
}