#include <iostream>
#include <conio.h>
using namespace std;
// Ejercicio_03

struct Nodo
{
    int info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, int ainsertar)
{
    Nodo *paux = lista;
    Nodo *anterior = NULL;
    while (paux && paux->info < ainsertar)
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if (paux != lista)
    {
        anterior->sgte = new Nodo();
        anterior->sgte->info = ainsertar;
        anterior->sgte->sgte = paux;
    }
    else
    {
        lista = new Nodo();
        lista->sgte = paux;
        lista->info = ainsertar;
    }
    return;
}

Nodo *ObtenerSiguiente(Nodo *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void MostrarLista(Nodo *milista)
{
    while (milista)
    {
        cout << milista->info << endl;
        milista = ObtenerSiguiente(milista);
    }
}

void buscarMayorElemento(Nodo *lista)
{
    int max = 0;
    if (lista)
    {
        while (lista)
        {
            if (lista->info > max)
            {
                max = lista->info;
            }

            lista = lista->sgte;
        }

        cout << "El mayor elemento es: " << max << endl;
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
}

int calcularPromedioLista(Nodo *lista)
{
    int contador = 0;
    int acu = 0;
    int promedio = 0;
    if (lista)
    {
        while (lista)
        {
            acu += lista->info;
            contador++;
            lista = lista->sgte;
        }
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }

    promedio = acu / contador;

    return promedio;
}

void agregarNodo(Nodo *&p, int x)
{
    Nodo *nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sgte = NULL;

    if (p == NULL)
    {
        p = nuevo;
    }
    else
    {

        Nodo *aux = p;

        while (aux->sgte != NULL)
        {
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }

    return;
}

void concatenarLista(Nodo *listaA, Nodo *listaB, Nodo *&listaC)
{

    while (listaA != NULL && listaB != NULL)
    {
        agregarNodo(listaC,listaA->info);
        listaA = listaA ->sgte;
        agregarNodo(listaC,listaB->info);
        listaB = listaB->sgte;
    }

    while (listaA)
    {
        agregarNodo(listaC,listaA->info);
        listaA = listaA ->sgte;
    }
    while(listaB)
    {
        agregarNodo(listaC,listaB->info);
        listaB = listaB->sgte;
    }
    
    

    return;
}

int main()
{
    Nodo *listaA = NULL;
    insertarOrdenado(listaA, 5);
    insertarOrdenado(listaA, 90);
    insertarOrdenado(listaA, 65);
    insertarOrdenado(listaA, 24);
     insertarOrdenado(listaA, 10);
      insertarOrdenado(listaA, 11);

    cout << "LISTA A: " << endl;

    MostrarLista(listaA);

    cout << "---------------" << endl;

    Nodo *listaB = NULL;

    insertarOrdenado(listaB, 20);
    insertarOrdenado(listaB, 67);
    insertarOrdenado(listaB, 15);
    insertarOrdenado(listaB, 1);

    cout << "LISTA B: " << endl;

    MostrarLista(listaB);

    cout << "----------------" << endl;

    Nodo *listaC = NULL;

    concatenarLista(listaA,listaB,listaC);

    Nodo *aux = listaC;

    cout << "LISTA C: " << endl;

    MostrarLista(aux);
    
}
