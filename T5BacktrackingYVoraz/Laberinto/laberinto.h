#pragma once

using namespace std;

// TODO: escribir los comentarios

// Muestra un laberinto 10x10
void mostrarLaberinto(char** laberinto);

// Comprueba si el movimiento se encuentra dentro del laberinto y no es hacia una pared o el movimiento anterior
bool esMovimientoValido(char** laberinto, int x, int y);

/* 
Resolucion de un laberinto por backtracking, si los caracteres utilizados son los del enunciado y el laberinto es de 10x10
    Parámetro: 


    Retorno: 
        Ninguno

    Precondicion:
        
    
    Complejidad Temporal:
        T(n) = 
        O()

    Complejidad Espacial: 
        M(n) = 
        O()
*/
void resolverLaberinto(char** laberinto, int posX, int posY, bool* exito);

