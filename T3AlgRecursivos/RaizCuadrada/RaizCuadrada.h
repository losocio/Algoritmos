#ifndef RAIZ_CUADRADA_H
#define RAIZ_CUADRADA_H

using namespace std;

/*  
Calculo de la raiz cuadrada de un numero mediante aproximacion
    Parámetro: Numero de que se quiere calcular la raiz (objetivo) y el error maximo permitido
    Retorno: Ninguno
    Precondicion: objetivo >= 0, error > 0
*/
void raizCuadradaAprox(const float objetivo, const float minimo, const float maximo, const float error);

#endif