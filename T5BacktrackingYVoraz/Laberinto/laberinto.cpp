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

Otro laberinto
. . * * * * * * * *
* . * . . . . . . *
* . * . * * * * . *
* . * . * * * * . *
* . * . . T * * . *
* . * * * * * * . .
* . * . . . . * . *
* . * . * * . * . *
* . . . * . . . . *
* * * * * * * * * *

*/

// Muestra un laberinto 10x10
void mostrarLaberinto(char** laberinto)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++) cout<<laberinto[i][j];
        cout << endl;
    }

    return;
}

// Comprueba si el movimiento se encuentra dentro del laberinto y no es hacia una pared o el movimiento anterior
bool esMovimientoValido(char** laberinto, int x, int y)
{
    /* FIXED: Si entra una x o y negativa no puedo buscar esos indices en el laberinto,
    primero hay que comprobar que los indices no son negativos

    return laberinto[x][y] != '*' && laberinto[x][y] != 'X' && x >= 0 && x < 10 && y >= 0 && y < 10;
    */

    // Si los indices se salen de los limites devuelve false
    if(x < 0 || x >= 10 || y < 0 || y >= 10) return false;
    // Si los caracteres son * o X devuelve false
    else if(laberinto[x][y] == '*' || laberinto[x][y] == 'X') return false;
    // De lo contrario devuelvo true
    else return true;
}

// Resolucion de un laberinto por backtracking, si los caracteres utilizados son los del enunciado y el laberinto es de 10x10
void resolverLaberinto(char** laberinto, int posX, int posY, bool* exito)
{
    // Precondicion, que el laberinto sea 10x10
    assertdomjudge(posX>=0 && posY>=0);
    assertdomjudge(!*exito);

    // Arrays de movimientos como se especifico: Arriba, Derecha, Abajo e Izquierda
    int movimientosX[]={-1, 0, 1, 0};
    int movimientosY[]={0, 1, 0, -1};

    int i=0;

    // Mientras no se recorran los 4 movimientos y exito sea false
    while(i<4 && !*exito)
    {
        // Determino la nueva posicion a la que moverse
        int siguienteX = posX + movimientosX[i];
        int siguienteY = posY + movimientosY[i];

        // 
        if(esMovimientoValido(laberinto, siguienteX, siguienteY))
        {            
            /* FIXED: seria posX y posY no siguienteX y siguienteY
            // Anoto el movimiento como valido
            laberinto[siguienteX][siguienteY] = 'X';
            */

            // Anoto el movimiento como valido
            laberinto[posX][posY] = 'X';

            // Si el movimiento es la solucion
            if(laberinto[siguienteX][siguienteY]=='T')
            {
                // Marco exito a true para poder terminar
                *exito=true;

                // Muestro solucion
                mostrarLaberinto(laberinto);
                cout<<"ENCONTRADO "<<siguienteX<<' '<<siguienteY;
            }
            // Si el movimiento es no es la solucion continuo la busqueda
            else
            {
                // Si en el siguiente paso no exite posible solucion se saldra de esta recursion
                resolverLaberinto(laberinto, siguienteX, siguienteY, exito);

                // Y por lo tanto se desanotara el paso
                laberinto[posX][posY] = '.';
            }
        }

        // Aumento contador para probar el siguiente movimiento en la secuencia en la siguiente pasada del bucle
        i++;
    }

    return;
}

int main()
{
    /*

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

    // Reservo memoria para laberinto 10x10 y lo relleno con el input
    char** laberinto;
    laberinto = new char* [10];
	for(int i=0; i<10; i++)	
    {
        laberinto[i] = new char[10];
        for(int j=0; j<10; j++)
        {
            cin>>laberinto[i][j];
        }
    }

    // Resuelvo el laberinto
    resolverLaberinto(laberinto, 0, 0, &exito);

    // Si salgo de la llamada original con exito a false no exite solucion
    if(!exito) cout<<"INALCANZABLE";

    // Libero memoria
    for(int i=0; i<10; i++)	delete[] laberinto[i];
    delete[] laberinto;

    return 0;
}

/*
    // Matriz con el laberinto alcanzable
    char laberintoAlcanzable[10][10]={
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
*/