#include <iostream>
#include "devolverCambio.h"

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

// Devuelve las cantidades de las distintas monedas de pesetas necesarias para de cambio
void devolverCambio(int valor, int* cambio)
{
    // La cantidada de dinero no puede ser negativa
    assertdomjudge(valor>=0);

    // Valores de las distintas monedas
    int valorMoneda[] = {500, 200, 100, 50, 25, 10, 5, 1};

    // Mientras quede cambio por dar
    int i=0;
    while(valor>0)
    {
        // Si lo que queda del valor inicial es menor que la moneda cambio a la siguiente moneda
        while(valor<valorMoneda[i]) i++;
        
        // Resto del valor inicial la moneda que añado al cambio
        valor-=valorMoneda[i]; // FIXED: Es -= no =- *facepalm*
        
        // Aumento la cantidad de la moneda que le resto al cambio
        cambio[i]++;
    
        /*
        // NOTE: hacer esto con todos pero en un bucle
        if(valor>valorMoneda[0])
        {
            valor-valorMoneda[0];
            cambio[0]++;
        }*/
    }

    return;
}

int main()
{
    int dinero;

    // Array de las cantidades de cada modeda, es de tamaño 8 porque hay 8 monedas distintas
    int cambio[] = {0, 0, 0, 0, 0, 0, 0, 0};

    //Bucle para que se repita hasta que entre un valor de dinero negativo
    while(true)
    {
        cin>>dinero;
        
        if(dinero<0) break;
        else 
        {
            // Calculo el cambio
            devolverCambio(dinero, cambio);

            // Imprimo y limpio el array de cambio
            for(int i=0;i<8;i++) 
            {
                cout<<cambio[i]<<" ";
                cambio[i]=0;
            }
            cout<<endl;
        }
    }

    return 0;
}