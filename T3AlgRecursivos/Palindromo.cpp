#include <iostream>
#include <stdlib.h>
#include <cstring>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

using namespace std;

/* 
Palidromo recursivo.
    Parámetro: Array de longitud inferior a 20.
    Retorno: int segun si es palidromo.
    Precondicion: Ninguno.
    Complejidad Temporal: O(1)
    Complejidad Espacial: O()
*/
int esPalindromo(const char pal[], int i){

    if(pal[i]==pal[strlen(pal)-i-1]){
        // Si llego al final del string, retornar 1
        if(strlen(pal)/2==i) return 1;
        // Si no es el final, hacer recursion
        return esPalindromo(pal, ++i);
    // Si dos letras simetricas no son iguales ya no es palindromo
    } else return 0;
}

int main(){
    char pal[20];

    cin>>pal;
    cout<<esPalindromo(pal, 0);

    return 0;
}