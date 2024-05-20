#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"
using namespace std;

ABB::ABB() {
    n = 0;
    raiz = NULL;
}

ABB::~ABB() {
    eliminarSubarbol(this->raiz);
}

/*BUSCARHUECO
* INSERTAR EN LUGAR CORRESP CAMBIANDO "ENLACES"
*/
void ABB::insertar(int nuevoElemento) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->contenido = nuevoElemento;
    nuevoNodo->hijoDerecho = NULL;
    nuevoNodo->hijoIzquierdo = NULL;
    
    if (this->raiz == nullptr){
        nuevoNodo->padre = NULL;
        this->raiz = nuevoNodo;
    }
    else {
        Nodo* padreDeNuevo = buscarHueco(this->raiz, nuevoElemento);

        nuevoNodo->padre = padreDeNuevo;

        if (padreDeNuevo->contenido > nuevoElemento) {
            padreDeNuevo->hijoIzquierdo = nuevoNodo;
        }
        else {
            padreDeNuevo->hijoDerecho = nuevoNodo;
        }
    }

    n++;
}

Nodo* ABB::buscar(int elementoABuscar) {
    return buscarRecursivo(this->raiz, elementoABuscar);
}

/*BUSCAR NODO, VER SI HOJA
*   SI HOJA-> BORRAR Y OLVIDAR
* SI INTERNO: VER DONDE SUSTITUIR:
*   SI SOLO UN LADO: ESE LADO
*   SI AMBOS HIJOS: HIJO MAYOR ALTURA
* REPETIR OPERACION CON HIJO ELEGIDO SUSTITUCION HASTA LLEGAR A HOJA
*/
void ABB::eliminar(int elementoAEliminar) {
    Nodo* nodoAEliminar = buscar(elementoAEliminar);

    if (nodoAEliminar->hijoDerecho == NULL && nodoAEliminar->hijoIzquierdo == NULL) {       //Ver si es hoja
        if (nodoAEliminar->padre != NULL) {     //Eliminando nodo no raíz
            if (nodoAEliminar->padre->hijoIzquierdo == nodoAEliminar) {     //Eliminar conexion correspondiente en padre
                nodoAEliminar->padre->hijoIzquierdo = NULL;
            }
            else {
                nodoAEliminar->padre->hijoDerecho = NULL;
            }
        }
        else {      //Si eliminando raíz
            this->raiz = NULL;
        }
        
        delete nodoAEliminar;
    }
    else {      //Nodo es interno
        eliminarNodo(nodoAEliminar);
    }
    n--;
}

void ABB::imprimir()
{
    if (raiz == NULL)
        cout << "VACIO" << endl;
    else
        imprimirRecorrido(raiz);
}

bool ABB::esABB() {
    return esSubABB(this->raiz);
}

bool ABB::esAVL() {
    return esSubAVL(this->raiz);
}

void ABB::leerArbol()
{
    raiz = leerSubarbol(NULL);
}

//PROTECTED ============================================================================

/* INVOCAR RECURSIVAMENTE HASTA HOJAS
* ELIMINAR HOJAS AL LLEGAR 
*/
void ABB::eliminarSubarbol(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol != NULL);
    if (raizSubarbol != NULL) {
        if (raizSubarbol->hijoDerecho != NULL || raizSubarbol->hijoIzquierdo != NULL) {     //No es hoja
            if (raizSubarbol->hijoDerecho != NULL) {
                eliminarSubarbol(raizSubarbol->hijoDerecho);
            }
            if (raizSubarbol->hijoIzquierdo != NULL) {
                eliminarSubarbol(raizSubarbol->hijoIzquierdo);
            }
        }
        else {
            eliminarNodo(raizSubarbol);
        }
    }
}

/*COMPROBAR TAMAÑO: VER SI MAYOR O MENOR QUE RAIZ, PASAR A LADO CORRESPONDIENTE
*   REPETIR COMPROBACION HASTA LLEGAR A NODO DONDE LADO CORRESPONDIENTE VACIO
*   DEVOLVER PUNTERO A PADRE LADO CORR VACIO
*/
Nodo* ABB::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar) {
    Nodo* nodoRes = NULL;
    if (raizSubarbol == nullptr) {
        nodoRes = raizSubarbol;
    }
    else {
        if (elementoAInsertar > raizSubarbol->contenido) {
            if (raizSubarbol->hijoDerecho != NULL) {
                buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
            }
            else {
                nodoRes = raizSubarbol;
            }
        }
        else {
            if (raizSubarbol->hijoIzquierdo != NULL) {
                buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
            }
            else {
                nodoRes = raizSubarbol;
            }
        }
    }

    return nodoRes;
}

/*COMO BUSCARHUECO, COMPROBANDO IGUALDAD
*/
Nodo* ABB::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
    if (raizSubarbol == nullptr) {
        return NULL;
    } if (raizSubarbol->contenido == elementoABuscar) {
        return raizSubarbol;
    }
    else if (elementoABuscar > raizSubarbol->contenido) {
        return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    }
    else {
        return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    }

    /*if (raizSubarbol == nullptr) {
        return NULL;
    }
    else if (raizSubarbol->contenido == elementoABuscar) {
        return raizSubarbol;
    } 
    else {
        if (raizSubarbol->hijoDerecho != NULL && elementoABuscar < raizSubarbol->contenido) {
            return buscarHueco(raizSubarbol->hijoDerecho, elementoABuscar);
        }
        else if (raizSubarbol->hijoIzquierdo != NULL && elementoABuscar > raizSubarbol->contenido) {
            return buscarHueco(raizSubarbol->hijoIzquierdo, elementoABuscar);
        }
        else {
            return NULL;
        }
    }*/
}

/* IR HACIA LA DERECHA HASTA LLEGAR A HOJA SIN HIJO DERECHO
*/
Nodo* ABB::buscarMaximo(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol != NULL);
    Nodo* maxActual = raizSubarbol;

    if (raizSubarbol->hijoDerecho != NULL) {
        maxActual = buscarMinimo(raizSubarbol->hijoDerecho);
    }

    return maxActual;
}

/* IR HACIA LA IZQUIERDA HASTA LLEGAR A HOJA SIN HIJO IZQUIERDO
*/
Nodo* ABB::buscarMinimo(Nodo* raizSubarbol) {
    assertdomjudge(raizSubarbol != NULL);
    Nodo* minActual = raizSubarbol;

    if (raizSubarbol->hijoIzquierdo != NULL) {
        minActual = buscarMinimo(raizSubarbol->hijoIzquierdo);
    }
    
    return minActual;

    //if (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo != NULL) {     // Solo hijo izquierdo
    //    minActual = buscarMinimo(raizSubarbol->hijoIzquierdo);
    //}
    //else if (raizSubarbol->hijoDerecho != NULL && raizSubarbol->hijoIzquierdo == NULL) {     // Solo hijo derecho
    //    minActual = buscarMinimo(raizSubarbol->hijoDerecho);
    //}
    //else if (raizSubarbol->hijoDerecho != NULL && raizSubarbol->hijoIzquierdo != NULL) {      // Ambos hijos existen
    //    Nodo* minI= buscarMinimo(raizSubarbol->hijoIzquierdo);
    //    Nodo* minD = buscarMinimo(raizSubarbol->hijoDerecho);

    //    if (minI->contenido > minD->contenido) {
    //        minActual = minD;
    //    }
    //    else {
    //        minActual = minI;
    //    }
    //}

    //if (!(minActual->contenido > raizSubarbol->contenido)) {
    //    minActual = raizSubarbol;
    //}

    //return minActual;
}

/* SI INTERNO: VER DONDE SUSTITUIR:
*   SI SOLO UN LADO: ESE LADO
*   SI AMBOS HIJOS: HIJO MAYOR ALTURA
* REPETIR OPERACION CON HIJO ELEGIDO SUSTITUCION HASTA LLEGAR A HOJA
*/
void ABB::eliminarNodo(Nodo* nodoParaEliminar) {
    int auxCont = nodoParaEliminar->contenido;
    Nodo* auxCambio;
    if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo != NULL) {       //Solo hijo izquierdo
        auxCambio = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = auxCambio->contenido;
        auxCambio->contenido = auxCont;
        eliminarNodo(auxCambio);
    }
    else if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo == NULL) {        //Solo hijo derecho
        auxCambio = buscarMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = auxCambio->contenido;
        auxCambio->contenido = auxCont;
        eliminarNodo(auxCambio);
    }
    else if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL) {      //Ambos hijos
        if (alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo)) {
            auxCambio = buscarMinimo(nodoParaEliminar->hijoDerecho);
            nodoParaEliminar->contenido = auxCambio->contenido;
            auxCambio->contenido = auxCont;
            eliminarNodo(auxCambio);
        }
        else {
            auxCambio = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
            nodoParaEliminar->contenido = auxCambio->contenido;
            auxCambio->contenido = auxCont;
            eliminarNodo(auxCambio);
        }
    } else {        //Hoja
        if (nodoParaEliminar->padre->hijoIzquierdo == nodoParaEliminar) {     //Eliminar conexion correspondiente en padre
            nodoParaEliminar->padre->hijoIzquierdo = NULL;
        }
        else {
            nodoParaEliminar->padre->hijoDerecho = NULL;
        }
        delete nodoParaEliminar;
    }
}

/*CAMINO MAS LARGO DESDE RAIZ A HOJAS
* ALTURA SUBARBOL IZQ O DER, ELEGIR MAXIMO -> SUMAR 1 A MAX
* RECURSIVIDAD
*/
int ABB::alturaNodo(Nodo* raizSubarbol) {
    int altura = -1;
    
    if (raizSubarbol != NULL) {
        altura++;
        if (raizSubarbol->hijoDerecho != NULL || raizSubarbol->hijoIzquierdo != NULL) {
            int alturaI = 1 + this->alturaNodo(raizSubarbol->hijoIzquierdo);
            int alturaD = 1 + this->alturaNodo(raizSubarbol->hijoDerecho);

            if (alturaI < alturaD) {
                altura = alturaD;
            }
            else {
                altura = alturaI;
            }
        }
    }

    return altura;
}

void ABB::imprimirRecorrido(Nodo* raizSubarbol)
{
    cout << raizSubarbol->contenido << endl;
    if (raizSubarbol->hijoIzquierdo != NULL)
    {
        cout << "I";
        imprimirRecorrido(raizSubarbol->hijoIzquierdo);
        cout << endl;
    }
    if (raizSubarbol->hijoDerecho != NULL)
    {
        cout << "D";
        imprimirRecorrido(raizSubarbol->hijoDerecho);
        cout << endl;
    }
}

/* COMPROBAR TAMAÑOS PARA DEVOLVER TRUE
*/
bool ABB::esSubABB(Nodo* raizSubarbol) {
    if (raizSubarbol == NULL || (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo == NULL)) {
        //Si es vacio u hoja sola, ABB automaticamente
        return true;
    }
    else {
        bool cumpleD = true;
        bool cumpleI = true;
        
        if (raizSubarbol->hijoDerecho != NULL) {
            if (this->buscarMinimo(raizSubarbol->hijoDerecho)->contenido > raizSubarbol->contenido) {
                cumpleD = esSubABB(raizSubarbol->hijoDerecho);
            }
            else {
                cumpleD = false;
            }
        }
        if (raizSubarbol->hijoIzquierdo != NULL) {
            if (this->buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido < raizSubarbol->contenido) {
                cumpleI = esSubABB(raizSubarbol->hijoIzquierdo);
            }
            else {
                cumpleI = false;
            }
        }
            return (cumpleD && cumpleI);
    }
}

/* CONDICION: ARBOL BINARIO
* DIFERENCIA ALTURAS NODOS HIJOS
* IDEA: USAR && LOGICO????
*/
bool ABB::esSubAVL(Nodo* raizSubarbol) {
    bool cumpleAltura = true;

    if (raizSubarbol == NULL) {
        return true;
    }
    else {
        if ((alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho) > 1) ||
            (alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho) < -1)) {
            cumpleAltura = false;
        }

        return (cumpleAltura && esSubAVL(raizSubarbol->hijoDerecho) && esSubAVL(raizSubarbol->hijoIzquierdo) && esSubABB(raizSubarbol));
    }
    /*if (raizSubarbol->hijoDerecho->hijoDerecho != NULL && raizSubarbol->hijoDerecho->hijoIzquierdo != NULL && 
    raizSubarbol->hijoIzquierdo->hijoIzquierdo != NULL && raizSubarbol->hijoIzquierdo->hijoDerecho != NULL) {
        return(esSubAVL(raizSubarbol->hijoDerecho) && esSubAVL(raizSubarbol->hijoIzquierdo));
    }
    else {
        return ((alturaNodo(raizSubarbol->hijoDerecho) - alturaNodo(raizSubarbol->hijoIzquierdo) <= 1) &&
        (alturaNodo(raizSubarbol->hijoDerecho) - alturaNodo(raizSubarbol->hijoIzquierdo) >= -1));
    }*/
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}


