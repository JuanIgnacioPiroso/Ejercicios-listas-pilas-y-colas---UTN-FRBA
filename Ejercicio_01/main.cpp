#include <iostream>
#include <conio.h>
using namespace std;

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
        cout << milista->info << "   " << milista << endl;
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

int main()
{
    Nodo *lista = NULL;
    insertarOrdenado(lista, 5);
    insertarOrdenado(lista, 90);
    insertarOrdenado(lista, 65);
    insertarOrdenado(lista, 24);

    MostrarLista(lista);

    buscarMayorElemento(lista);

    int promedio = calcularPromedioLista(lista);

    cout << "El promedio es: " << promedio << endl;
}
