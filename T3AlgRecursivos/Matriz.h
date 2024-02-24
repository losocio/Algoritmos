#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
    private: 
    
	int n_filas;
    int n_columnas;

	double ** matriz;

    public:
	
    /* Constructor por defecto.
			Parámetro: Ninguno.
			Retorno: Objeto de Matriz con dimension 0x0 y un puntero a NULL.
			Precondicion: Ninguno.
			Complejidad Temporal: O(1)
			Complejidad Espacial: 
    */
    Matriz();

    /*  Constructor por parametros
    	   Parámetro: numero de filas y columnas de la matriz
    	   Retorno: una nueva matriz con la matriz pasada como parámetro.
    	   Precondicion: Ninguno.
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(n_filas*n_columnas)
    */
    Matriz(int n_filas, int n_colmunas);

    /* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
    	    Parámetro: la matriz que se va a asignar
    	    Retorno: una nueva matriz con la matriz pasada como parámetro.
    	    Precondicion: Ninguno.
    	    Complejidad Temporal: O(n_filas*n_columnas)
    	    Complejidad Espacial: O(n_filas*n_columnas)
    */
    Matriz(Matriz & m);

    /* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
    	   Parámetro: la matriz que se va a asignar
    	   Retorno: una nueva matriz con la matriz pasada como parámetro.
    	   Precondicion: Ninguno.
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(n_filas*n_columnas)
    */
    ~Matriz();

    /* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
    	   Parámetro: la matriz que se va a asignar
    	   Retorno: una nueva matriz con la matriz pasada como parámetro.
    	   Precondicion: Ninguno.
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(n_filas*n_columnas)
    */
    Matriz & operator = (const Matriz & m);

    /* Suma dos matrices.Crea una nueva matriz con el resultado.
    	   Parámetro: las matrices operando con las mismas dimensiones
    	   Retorno: una nueva matriz con el resultado.
    	   Precondicion: Que existan las dos matrices operador y sean de la misma dimension.
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(n_filas*n_columnas)
    */
    Matriz & operator + (const Matriz & m2);

	/* Resta dos matrices en el orden de los argumentos. Crea una nueva matriz con el resultado.
    	   Parámetro: las matrices operando con las mismas dimensiones
    	   Retorno: una nueva matriz con el resultado.
    	   Precondicion: Que exsitan las dos matrices operador y sean de la misma dimension.
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(n_filas*n_columnas)
    */
    Matriz & operator - (const Matriz & m2);

    /* Producto una matriz por un escalar 
    	   Parámetro: Una matriz y double escalar
    	   Retorno: una nueva matriz con el resultado.
    	   Precondicion: La matriz deve exsistir
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    Matriz & operator * (const double & escalar); //TODO puede que el escalar no necesite &

	/* Producto una matriz por matriz 
    	   Parámetro: Dos matrices
    	   Retorno: una nueva matriz con el resultado.
    	   Precondicion: La matriz debe exsistir y las
			filas_m1 == columnas_m2 && columnas_m1 == filas_m2
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    Matriz & operator * (const Matriz &m2);

	/* Calcular la matriz traspuesta
    	   Parámetro: Ninguno
    	   Retorno: Matriz traspuesta
    	   Precondicion: La matriz debe exsistir
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
	Matriz& calcularTraspuesta();

	/*  Obtener el valor maximo de una matriz
    	   Parámetro: Ninguno
    	   Retorno: double maximo
    	   Precondicion: La matriz debe existir
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
	double obtenerMaximo();

	/* Obtener el valor maximo de una matriz
    	   Parámetro: Ninguno
    	   Retorno: double minimo
    	   Precondicion:La matriz debe existir
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
	double obtenerMinimo();

	/* Comprueba si la matriz es simetrica 
    	   Parámetro: Ninguno
    	   Retorno: booleano segun simetria
    	   Precondicion: La matriz no debe estar vacía
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    bool esSimetrica();

    /* Comprueba si la matriz es simetrica 
    	   Parámetro: Ninguno
    	   Retorno: booleano segun simetria
    	   Precondicion: La matriz no debe estar vacía
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    double calcularAdjunto(int fila, int columna);

    /* Comprueba si la matriz es simetrica 
    	   Parámetro: Ninguno
    	   Retorno: booleano segun simetria
    	   Precondicion: La matriz no debe estar vacía
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    double calcularDeterminante();
    

    /* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
    	   Parámetro: Ninguno
    	   Retorno: Ninguno
    	   Precondicion: La matriz no debe estar vacía
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    void rellenarManual();

    /* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
    	   Parámetro: semilla que se utiliza para el generador aleatorio
    	   Retorno: Ninguno
    	   Precondicion: La matriz no debe estar vacía
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    void rellenarAleatorio(long seed);

    /* Imprime por pantalla todos los elementos de la matriz del objeto actual  
    	   Parámetro: Ninguno
    	   Retorno: Ninguno
    	   Precondicion: La matriz no debe estar vacía
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    void mostrarMatriz();

	/* Imprime por pantalla todos los elementos de la matriz del objeto actual con sus indices  
    	   Parámetro: Ninguno
    	   Retorno: Ninguno
    	   Precondicion: Ninguna
    	   Complejidad Temporal: O(n_filas*n_columnas)
    	   Complejidad Espacial: O(1)
    */
    void mostrarMatrizIndices();
};

#endif // MATRIZ_H