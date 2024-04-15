#include "RaizCuadrada.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
 
//Calculo de la raiz cuadrada de un numero mediante aproximacion
//NOTE la funcion recursiva puede recivir mas parametros que los que nos dan en el enunciado
void raizCuadradaAprox(const float objetivo, const float minimo, const float maximo, const float error){
    //Tanto el error como los operandos deben ser positivos 
    //Asumo que el error debe ser mayor que 0, sino entraremoes en resursividad infinita en algunos casos
    assertdomjudge(objetivo>=0 && minimo>=0 && maximo>=0 && error>0);

    //Calculo el valor medio y luego su cuadrado
    float valorMedio=(minimo+maximo)/2; //NOTE valor medio de un rango, no la mitad del maximo
    float cuadrado = valorMedio*valorMedio;
    
    //Imprimo la aproximacion
    cout<<valorMedio<<endl;
    
    //Si el error es menor que es requerido se sale de la recursion
    if(fabs(cuadrado-objetivo)<=error) return;
    
    //Si el cuadrado del valor medio en mayor que el objetivo, el valor medio pasa a ser el maximo del nuevo rango
    if(cuadrado>objetivo) raizCuadradaAprox(objetivo, minimo, valorMedio, error);
    //Si es menor, el valor medio pasa a ser el minimo del nuevo rango
    else raizCuadradaAprox(objetivo, valorMedio, maximo, error);
    
    return;
}

int main() {
    float objetivo, minimo, maximo, error;
    
    cin>>objetivo;
    cin>>error;

    raizCuadradaAprox(objetivo, 0, objetivo, error);

    return 0;
}