#include <iostream>
#include "laberinto.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/*
Laberinto

..********
*.*......*
*.*.****.*
*.*.*..*.*
*.*.*T.*.*
*.*.**.*.*
*.*....*.*
*.******.*
*........*
**********

Mas bonito 
. . * * * * * * * *
* . * . . . . . . *
* . * . * * * * . *
* . * . * . . * . *
* . * . * T . * . *
* . * . * * . * . *
* . * . . . . * . *
* . * * * * * * . *
* . . . . . . . . *
* * * * * * * * * *
*/

// Resolucion de un laberinto por backtracking, si los caracteres utilizados son los del enunciado y el laberinto es de 10x10
void resolverLaberinto(char laberinto[][10], int posX, int posY, bool* exito)
{
    // Arrays de movimientos como se especifico: Arriba, Derecha, Abajo e Izquierda
    int movimientosX[]={-1, 0, 1, 0};
    int movimientosY[]={0, 1, 0, -1};

    // 4 movimientos
    for(int i=0; i<4; i++)
    {
        // Determino la nueva posicion a la que moverse
        int siguienteX = posX + movimientosX[i];
        int siguienteY = posY + movimientosY[i];

        // TODO: Ademas de verificar que sea *, que no se salga de los limites del laberinto (para el inicio)
        // Si el cadidato es valido ('.' o 'T', pero no '*')
        // Sino prueba con el siguiente movimiento
        if(laberinto[siguienteX][siguienteY] != '*' && (siguienteX > -1 && siguienteX < 10) && (siguienteY > -1 && siguienteY < 10))
        {
            // Anoto el candidato valido
            laberinto[siguienteX][siguienteY] = 'X';

            // Si el candidato es la solucion ('T')
            if(laberinto[siguienteX][siguienteY]=='T')
            {
                // Marco exito a true
                *exito=true;
            }
            // Si el candidato es el camino ('.')
            else
            {
                // Recurrencia
                resolverLaberinto(laberinto, siguienteX, siguienteY, exito);

            }
        }
    }

    // Si ningun movimiento es valido no ocurre la recurrencia
    // Por tanto, se vuelve al paso anterior y se prueba el siguiente movimiento del paso anterior
    return;
}

int main()
{

    // TODO: Puede lo cambie para que el input del laberinto lo haga el usuario
    /*
    Laberinto

    ..********
    *.*......*
    *.*.****.*
    *.*.*..*.*
    *.*.*T.*.*
    *.*.**.*.*
    *.*....*.*
    *.******.*
    *........*
    **********
    */

    bool exito=false;

    // Matriz con el laberinto alcanzable
    char laberinto[10][10]={
        {'.', '.', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '.', '*', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '.', '*', '.', '*', '*', '*', '*', '.', '*'},
        {'*', '.', '*', '.', '*', '.', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '*', 'T', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '*', '*', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '.', '.', '.', '*', '.', '*'},
        {'*', '.', '*', '*', '*', '*', '*', '*', '.', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    // Matriz con el laberinto inalcanzable
    char laberintoInalcanzable[10][10]={
        {'.', '.', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '.', '.', '.', '.', '.', '.', '*'}, // Aqui se queda sin salida, al principio
        {'*', '.', '*', '.', '*', '*', '*', '*', '.', '*'},
        {'*', '.', '*', '.', '*', '.', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '*', 'T', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '*', '*', '.', '*', '.', '*'},
        {'*', '.', '*', '.', '.', '.', '.', '*', '.', '*'},
        {'*', '.', '*', '*', '*', '*', '*', '*', '.', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    resolverLaberinto(laberinto, 0, 0, &exito);


    return 0;
}