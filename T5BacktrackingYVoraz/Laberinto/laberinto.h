#pragma once

using namespace std;

/* 
Muestra un laberinto 10x10
    
    Parámetro: 
        char** laberinto, laberinto a mostrar

    Retorno: 
        Ninguno

    Precondicion:
        Qeue el laberinto sea 10x10
    
    Complejidad Temporal:
        T(n) = 100
        O(1)

    Complejidad Espacial: 
        M(n) = 1
        O(1)
*/
void mostrarLaberinto(char** laberinto);

/* 
Comprueba si el movimiento se encuentra dentro del laberinto y no es hacia una pared o el movimiento anterior
    
    Parámetro: 
        char** laberinto, laberinto
        int x, posicion x
        int y, posicion y

    Retorno: 
        bool valido, si el movimiento es valido

    Precondicion:
        Que el laberinto sea 10x10
    
    Complejidad Temporal:
        T(n) = 1
        O(1)

    Complejidad Espacial: 
        M(n) = 1
        O(1)
*/
bool esMovimientoValido(char** laberinto, int x, int y);

/* 
Resolucion de un laberinto por backtracking, si los caracteres utilizados son los del enunciado y el laberinto es de 10x10
    
    Parámetro: 
        char** laberinto, laberinto
        int posX, posicion x de inicio
        int posY, posicion y de inicio
        bool* exito, booleano de exito

    Retorno: 
        Ninguno

    Precondicion:
        Que el laberinto sea 10x10
        posX >= 0
        posY >= 0
        !*exito
    
    Complejidad Temporal:
        T(n) = 
        O()

    Complejidad Espacial: 
        M(n) = 1
        O(1)
*/
void resolverLaberinto(char** laberinto, int posX, int posY, bool* exito);

