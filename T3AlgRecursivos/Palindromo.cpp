#include <iostream>
#include <stdlib.h>
#include <cstring>

bool esPalindromo(char pal, int i){

    if(pal[i]==pal[strlen(pal)-i-1]){
        // Si llego al final del string, retornar 1
        if(0==strlen(pal)-1) return true;
        // Si no es el final hacer recursion
        return esPalindromo(pal, --i);
    // Si dos letras simetricas no son iguales ya no es palindromo
    } else return false;
}

int main(){
    char pal[20] = "ojorojo";
    char noPal[20] = "ojor4jo";
    
    cout<<"ya";
    //cout<<esPalindromo(pal);

    return 0;
}