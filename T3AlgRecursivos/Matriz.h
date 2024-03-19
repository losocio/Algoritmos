#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
    private: 
    
	int n_filas;
    int n_columnas;

	double ** matriz;

    public:

	/*
	Siendo:
		a = número de filas de la matriz del objecto actual
		b = número de columnas de la matriz del objecto actual
		c = número de filas de la matriz pasada como parámetro (si existe)
		d = número de columnas de la matriz pasada como parámetro (si existe)
	*/
	
	/*  
	Constructor por defecto, crea una matriz vacia
		Parámetro: 
			Ninguno

		Retorno: 
			Objeto de Matriz con dimension 0x0 y un puntero a NULL.
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 1
			O(1)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    Matriz();

	/*  
	Constructor por parametros, crea una matriz con las dimensiones dadas
		Parámetro: 
			n_filas: Numero de filas de la matriz
			n_columnas: Numero de columnas de la matriz

		Retorno: 
			Una nueva matriz con la matriz pasada como parámetro.
		
		Precondicion: 
			n_filas >= 0
			n_columnas >= 0
		
		Complejidad Temporal:
			T(n) = a
			O(a)

		Complejidad Espacial: 
			M(n) = a
			O(a)
	*/
    Matriz(int n_filas, int n_colmunas);


	/*  
	Constructor copia, copia una matriz a otra nueva
		Parámetro: 
			m: la matriz que se va a copiar

		Retorno: 
			Una nueva matriz con la matriz pasada como parámetro.
		
		Precondicion: 
			m.n_filas>=0
			m.n_columnas>=0
		
		Complejidad Temporal:
			T(n) = cd
			O(cd)

		Complejidad Espacial: 
			M(n) = c 
			O(c)
	*/
    Matriz(Matriz &m);


	/*  
	Destructor
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = a
			O(a)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    ~Matriz();


	/*  
	Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado.
		Parámetro: 
			m: Matriz que se va a asignar

		Retorno: 
			Una nueva matriz con la matriz pasada como parámetro.
		
		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = ab
			O(ab)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    Matriz & operator = (const Matriz & m);


	/*  
	Suma dos matrices.Crea una nueva matriz con el resultado.
		Parámetro: 
			m2: Matriz a sumar

		Retorno: 
			Una nueva matriz con el resultado.
		
		Precondicion: 
			Las matrices deben existir
			Las matrices deben de ser de las mismas dimensiones
		
		Complejidad Temporal:
			T(n) = ab+a
			O(ab)

		Complejidad Espacial: 
			M(n) = ab // Aunque dudo
			O(ab)
	*/
    Matriz & operator + (const Matriz & m2);


	/*  
	Resta dos matrices en el orden de los argumentos. Crea una nueva matriz con el resultado.
		Parámetro: 
			m2: Matriz a restar

		Retorno: 
			Una nueva matriz con el resultado.
		
		Precondicion: 
			Las matrices deben existir
			Las matrices deben de ser de las mismas dimensiones
		
		Complejidad Temporal:
			T(n) = ab+a
			O(ab)

		Complejidad Espacial: 
			M(n) = ab // Aunque dudo
			O(ab)
	*/
    Matriz & operator - (const Matriz & m2);

	
	/*  
	Producto una matriz por un escalar 
		Parámetro: 
			escalar: double escalar para multiplicar

		Retorno: 
			Una nueva matriz con la matriz pasada como parámetro.
		
		Precondicion: 
			La matriz debe existir
		
		Complejidad Temporal:
			T(n) = ab+a
			O(ab)

		Complejidad Espacial: 
			M(n) = ab // Aunque dudo
			O(ab)
	*/
    Matriz & operator * (const double & escalar); //TODO puede que el escalar no necesite &

 

	/*  
	Producto una matriz por matriz 
		Parámetro: 
			m2: Segunda matriz para multiplicar

		Retorno: 
			Una nueva matriz con el resultado.
		
		Precondicion: 
			La matriz debe existir
			n_columnas == m2.n_filas
		
		Complejidad Temporal:
			T(n) = abd+a
			O(abd)

		Complejidad Espacial: 
			M(n) = ad // Aunque dudo
			O(ad)
	*/
    Matriz & operator * (const Matriz &m2);


	/*  
	Calcular la matriz traspuesta
		Parámetro: 
			Ninguno

		Retorno: 
			Matriz traspuesta
		
		Precondicion: 
			La matriz debe existir
		
		Complejidad Temporal:
			T(n) = ab+b
			O(ab)

		Complejidad Espacial: 
			M(n) = ab // Aunque dudo 
			O(ab)
	*/
	Matriz& calcularTraspuesta();


	/*  
	Obtener el valor maximo de una matriz
		Parámetro: 
			Ninguno

		Retorno: 
			double con el maximo
		
		Precondicion: 
			La matriz debe existir
		
		Complejidad Temporal:
			T(n) = ab
			O(ab)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	double obtenerMaximo();



	/*  
	Obtener el valor maximo de una matriz
		Parámetro: 
			Ninguno

		Retorno: 
			double con el minimo
		
		Precondicion: 
			La matriz debe existir
		
		Complejidad Temporal:
			T(n) = ab
			O(ab)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
	double obtenerMinimo();


	/*  
	Comprueba si la matriz es simetrica 
		Parámetro: 
			Ninguno

		Retorno: 
			booleano segun simetria
		
		Precondicion: 
			n_filas == n_columnas
		
		Complejidad Temporal:
			T(n) = ab
			O(ab)

		Complejidad Espacial: 
			M(n) = 1
			O(1)
	*/
    bool esSimetrica();

	/*  
	Calcula el menor complamentario de un elemento de una matriz
		Parámetro: 
			i_fila: Indice de la fila del elemento de que hacer el calculo
			i_columna: Indice de la columna del elemento de que hacer el calculo

		Retorno: 
			Matriz con el menor complementario
		
		Precondicion: 
			n_filas == n_columnas
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
	Matriz& calcularMatrizMenorComplementario(int i_fila, int i_columna);
	
	/*  
	Calcula el determinante de una matriz
		Parámetro: 
			Ninguno

		Retorno: 
			double con el determianante
		
		Precondicion: 
			n_filas == n_columnas
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    double calcularDeterminante();


	/*  
	Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno
		
		Precondicion: 
			La matriz no debe estar vacía
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void rellenarManual();


	/*  
	Constructor por parametros
		Parámetro: 
			seed: semilla que se utiliza para el generador aleatorio

		Retorno: 
			Ninguna
		
		Precondicion: 
			La matriz no debe estar vacía
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void rellenarAleatorio(long seed);


	/*  
	Imprime por pantalla todos los elementos de la matriz del objeto actual
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno
		
		Precondicion: 
			La matriz no debe estar vacía
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void mostrarMatriz();



	/*  
	Imprime por pantalla todos los elementos de la matriz del objeto actual con sus indices  
		Parámetro: 
			Ninguno

		Retorno: 
			Ninguno 

		Precondicion: 
			Ninguno
		
		Complejidad Temporal:
			T(n) = 
			O()

		Complejidad Espacial: 
			M(n) = 
			O()
	*/
    void mostrarMatrizIndices();

};

#endif