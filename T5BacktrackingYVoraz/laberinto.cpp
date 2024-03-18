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

//
void resolverLaberinto(char** laberinto, int sizeX, int sizeY, int)
{
    // Movimientos en orden
    int movimientoX[]={-1, 0, 1, 0};
    int movimientoY[]={0, 1, 0, -1};

    // 4 movimientos
    for(int i=0;i<4;i++)
    {
        // Si a donde te vas a mover es * (pared)
        if(laberinto[movimientoX[i]][movimientoY[i]]=='*')
        {

        }
    }

    return;
}

int main()
{
    // Arrays de movimientos como se especifico: Arriba, Derecha, Abajo e Izquierda
    
    // Matriz con el laberinto
    char laberinto[][]={
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



    return 0;
}