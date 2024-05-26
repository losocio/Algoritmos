#include "Palindromo.h"
#include <iostream>
#include <cstring>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Palidromo recursivo
int esPalindromo(const char palindromo[], int i){
    //Si dos letras simetricas no son iguales ya no es palindromo
    if(palindromo[i]!=palindromo[strlen(palindromo)-i-1]) return 0;

    //Si llego al final del string, retornar 1
    if(strlen(palindromo)/2==i) return 1;

    //Si no es el final, hacer recursion
    return esPalindromo(palindromo, ++i);
    
    /* 
    
    // NOTE: Los corchetes son para guarros

    if(pal[i]==pal[strlen(pal)-i-1]){
        //Si llego al final del string, retornar 1
        if(strlen(pal)/2==i) return 1;
        //Si no es el final, hacer recursion
        return esPalindromo(pal, ++i);
    //Si dos letras simetricas no son iguales ya no es palindromo
    } else return 0;
    
    */
}

int main(){
    char palindromo[20];

    cin>>palindromo;
    cout<<esPalindromo(palindromo, 0);

    return 0;
}