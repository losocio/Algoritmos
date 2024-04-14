#include "Supermercado.h"

// Constructor, reserva n cajas
Supermercado::Supermercado(int n)
{
    assertdomjudge(n>0);

    // Guardo numero de cajas
    n_cajas=n;

    // Reservo memoria
    cajas=new Cola[n];

    // Inicilizo objetos en dicha memoria
    for(int i=0;i<n;i++) cajas[i]=Cola();

}

// Añade un usuario nuevo a la caja elegida
void Supermercado::nuevoUsuario(int n, int id)
{
    assertdomjudge(n>=0 && n<n_cajas);

    // NOTE: Al ser el orden de llegada no puede ser negativo
    assertdomjudge(id>=0);

    // Encolo el id en la caja n
    cajas[n].encolar(id);
    
    return;
}  

// Reparte los usuarios encolados en la caja a cerrar entre el resto de cajas
void Supermercado::cerrarCaja(int n)
{
    assertdomjudge(n>=0 && n<n_cajas);

    // Mientras queden usuarios en la caja
    while(!cajas[n].estaVacia())
    {
        for(int i=0;i<n_cajas;i++){
            
            // FIXED: !cajas[i].estaVacia() se cumple siempre, no se desencola nada y por tanto el bucle de fuera es infinito
            // Si la iteracion pasa por la caja a cerrar o una caja vacia, me la salto
            if(i==n || cajas[i].estaVacia()) continue;

            // Desencolo en la caja a borra y encolo en otra caja
            cajas[i].encolar(cajas[n].desencolar());
        }
    }

    return;
}  

// Desencola un usuario
int Supermercado::atenderUsuario(int n)
{
    assertdomjudge(n>=0 && n<n_cajas);

    // Desencolo de la caja n
    return cajas[n].desencolar();
}

// Comprueba si esta vacia la caja n
bool Supermercado::cajaVacia(int n)
{
    assertdomjudge(n>=0 && n<n_cajas);

    // Uso el metodo estaVacia() de la clase Cola
    return cajas[n].estaVacia();
}