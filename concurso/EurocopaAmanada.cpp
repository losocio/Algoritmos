#include <iostream>
using namespace std;

char calcular_ganador(char *equipos, int n, int ronda)
{
    //Dividir

    //Si caso no caso trivial, dividir
    if(n>=2)
    {
        //primera mitad
        calcular_ganador(equipos,n/2,ronda++);
        //segunda mitad
        calcular_ganador(equipos,n/2,ronda++);

    }

    //luchar

    char ganador;
    // si ronda es impar
    if(ronda%2)
    {

    }
    //si ronda es par
    else
    {

    }
    //mostrar ganador
    cout<<<<endl;
    return
}

int main()
{
    int n;
    cin >> n;
    char *equipos = new char[n+1];
    for(int i = 0;i <n; i++)
        equipos[i]='A'+i;
    equipos[n]=0;
    
    calcular_ganador(equipos,n,0);
}
