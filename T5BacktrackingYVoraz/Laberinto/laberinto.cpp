#include <iostream>
#include "laberinto.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/* NOTE: Laberinto

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

// Comprueba si el movimiento se encuentra dentro del laberinto y no es hacia una pared
bool esMovimientoValido(char laberinto[][10], int x, int y)
{
    return laberinto[x][y] != '*' && x > -1 && x < 10 && y > -1 && y < 10;
}

// Resolucion de un laberinto por backtracking, si los caracteres utilizados son los del enunciado y el laberinto es de 10x10
void resolverLaberinto(char laberinto[][10], int posX, int posY, bool* exito)
{
    // Arrays de movimientos como se especifico: Arriba, Derecha, Abajo e Izquierda
    int movimientosX[]={-1, 0, 1, 0};
    int movimientosY[]={0, 1, 0, -1};

    // FIX: Se queda en un bucle infinito de algun tipo, pero no es verdaderamente infinito
    int i=0;
    do
    {
        // Determino la nueva posicion a la que moverse
        int siguienteX = posX + movimientosX[i];
        int siguienteY = posY + movimientosY[i];

        // Si el movimiento no es valido prueba con el siguiente movimiento
        if(esMovimientoValido(laberinto, siguienteX, siguienteY))
        {
            if(laberinto[siguienteX][siguienteY]!='X')
            {
                // Anoto el movimiento como valido
                laberinto[siguienteX][siguienteY] = 'X';

                // Si el movimiento es la solucion ('T')
                if(laberinto[siguienteX][siguienteY]=='T')
                {
                    // Marco exito a true
                    *exito=true;

                    // Muestro solucion
                    cout<<"ENCONTRADO "<<siguienteX<<' '<<siguienteY<<endl;
                }
                // Si el movimiento es el camino ('.')
                else
                {
                    // Recurrencia
                    //cout<<"Recursion"<<endl;
                    resolverLaberinto(laberinto, siguienteX, siguienteY, exito);

                    // TODO: puede que necesite un if()
                    // Desanoto el movimiento como valido
                    if(!*exito) laberinto[siguienteX][siguienteY]='.';
                    else cout<<"INALCANZABLE"<<endl;
                }
            }
        }

        // TODO: puede que haya que poner esto al principio
        i++;

    }
    while(i<4 && !*exito);
    
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

    bool exito=false;

    // Resuelvo el laberinto
    resolverLaberinto(laberinto, 0, 0, &exito);

    return 0;
}
