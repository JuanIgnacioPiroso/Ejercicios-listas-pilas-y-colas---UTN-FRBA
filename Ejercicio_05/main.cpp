#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct Alumno
{
    char nombre[50];
    char apellido[50];
    char dni[10];
    int legajo;
    int codCarrera;
};

struct NodoAlumno
{
    Alumno info;
    NodoAlumno *sgte;
};


void agregarNodo(NodoAlumno *&p, Alumno a)
{
    NodoAlumno *nuevo = new NodoAlumno();
    nuevo->info = a;
    nuevo->sgte = NULL;

    if (p == NULL)
    {
        p = nuevo;
    }
    else
    {

        NodoAlumno *aux = p;

        while (aux->sgte != NULL)
        {
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }

    return;
}

NodoAlumno *ObtenerSiguiente(NodoAlumno *n)

{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void insertarEnLista(char ruta_archivo[], NodoAlumno *&listaAlumno)
{
    Alumno a;

    FILE *archivoAlumnos = fopen(ruta_archivo, "rb");

    while (fread(&a, sizeof(Alumno), 1, archivoAlumnos))
    {
        agregarNodo(listaAlumno, a);
    }

    fclose(archivoAlumnos);
}

void MostrarLista(NodoAlumno *milista)
{
    while (milista)
    {
        cout << "LECTURA DESDE LA LISTA " << endl;
        cout << milista->info.nombre << endl;
        cout << milista->info.apellido << endl;
        cout << milista->info.dni << endl;
        cout << milista->info.legajo << endl;
        cout << milista->info.codCarrera << endl;
        cout << "-----------------------" << endl;

        milista = ObtenerSiguiente(milista);
    }
}

int main()
{

    /* CARGA DE ARCHIVO */

    /* ******************************************************* */
    /*
    FILE *arch = fopen("alumnos.dat", "wb");
    Alumno alumn;
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese nombre: ";
        cin.getline(alumn.nombre, 50);
        cout << "Ingrese apellido: ";
        cin.getline(alumn.apellido, 50);
        cout << "Ingrese dni: ";
        cin.getline(alumn.dni,10);
        cout << "Ingrese legajo: ";
        cin >> alumn.legajo;
        cout << "Ingrese codigo de carrera: ";
        cin >> alumn.codCarrera;
        cin.ignore();
        fwrite(&alumn, sizeof(Alumno), 1, arch);
    }


    fclose(arch);

    arch = fopen("alumnos.dat", "rb");

    while (fread(&alumn, sizeof(Alumno), 1, arch))
    {
        cout << alumn.nombre << endl;
        cout << alumn.apellido << endl;
        cout << alumn.dni << endl;
        cout << alumn.legajo << endl;
        cout << alumn.codCarrera << endl;
        cout << "-----------------" << endl;
    }
    /* ******************************************************* */

    NodoAlumno *listaAlumno = NULL;

    insertarEnLista("alumnos.dat",listaAlumno);


    MostrarLista(listaAlumno);
}