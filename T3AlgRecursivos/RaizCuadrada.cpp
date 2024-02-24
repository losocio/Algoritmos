#include <iostream>
#include <stdlib.h>
#include <cmath>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

using namespace std;

/*  
Calculo de la raiz cuadrada de un numero mediante aproximacion
    Parámetro: Numero de que se quiere calcular la raiz (objetivo) y el error maximo permitido
    Retorno: Ninguno
    Precondicion: objetivo >= 0, error > 0
    Complejidad Temporal: 
    Complejidad Espacial: 
*/
void raizCuadradaAprox(const float objetivo, const float error){
    //Tanto el error como el operando deben ser positivos 
    assertdomjudge(objetivo>=0 && error>0); //TODO puede que objetivo tenga se ser mayor que 0

    float medioObjetivo=objetivo/2;
    float cuadrado = medioObjetivo*medioObjetivo;
    
    cout<<cuadrado<<endl;
    
    //Si el error es mayor que es requerido se continua
    if(fabs(cuadrado-objetivo)>error){ //TODO floating absolute value
        if(cuadrado>objetivo){
            float objetivoMenor;
            raizCuadradaAprox(objetivoMenor, error);
        }else{
            float objetivoMenor;
            raizCuadradaAprox(objetivoMenor, error);
        }
    } else return;
}

int main() {
    float objetivo, error;
    
    cin>>objetivo;
    cin>>error;

    raizCuadradaAprox(objetivo, error);

    return 0;
}