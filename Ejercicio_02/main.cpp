#include <iostream>
#include <conio.h>
using namespace std;
// Ejercicio_02

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

void MostrarLista(Nodo *milista)
{
    while (milista)
    {
        cout << milista->info << "   " << milista << endl;
        milista = milista->sgte;
    }
}
void InsertarSiguiente(Nodo *&n, int x)
{
    Nodo *nuevo = new Nodo();
    nuevo->info = x;
    if (n)
    {
        nuevo->sgte = n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte = n;
        n = nuevo;
    }
    return;
}


void unirListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC)
{

    while (listaA != NULL)
    {
        InsertarSiguiente(listaC, listaA->info);
        listaA = listaA->sgte;
    }

    while (listaB != NULL)
    {
        InsertarSiguiente(listaC, listaB->info);
        listaB = listaB->sgte;
    }
}

//Ordenamiento burbuja para ordenar la lista
void ordenarLista(Nodo *&lista)
{
    Nodo *paux = lista;
    Nodo *siguiente = NULL;
    int aux;
    while (paux)
    {
        siguiente = paux->sgte;
        while (siguiente)
        {
            if (paux->info > siguiente->info)
            {
                aux = paux->info;
                paux->info = siguiente->info;
                siguiente->info = aux;
            }
            siguiente = siguiente->sgte;
        }
        paux = paux->sgte;
    }
}

int main()
{

    Nodo *listaA = NULL;
    insertarOrdenado(listaA, 5);
    insertarOrdenado(listaA, 90);
    insertarOrdenado(listaA, 65);
    insertarOrdenado(listaA, 24);

    Nodo *listaB = NULL;

    insertarOrdenado(listaB, 1);
    insertarOrdenado(listaB, 12);
    insertarOrdenado(listaB, 76);
    insertarOrdenado(listaB, 100);

    cout << "LISTA A: " << endl;
    MostrarLista(listaA);
    cout << "--------------------------" << endl;

    cout << "LISTA B: " << endl;
    MostrarLista(listaB);
    cout << "--------------------------" << endl;

    Nodo *listaC = NULL;
    unirListas(listaA, listaB, listaC);

    Nodo *aux = listaC;

    ordenarLista(aux);

    while (aux)
    {
        cout << aux->info << endl;
        aux = aux->sgte;
    }

    return 0;
}
