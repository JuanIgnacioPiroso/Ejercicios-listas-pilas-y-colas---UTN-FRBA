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

struct Materia
{
    char nombreMateria[50];
    char fechaAprobacion[11];
    int legajoAlumno;
    int nota;
    int libro;
    int folio;
};

struct NodoMateria
{
    Materia info;
    NodoMateria *sgte;
};

struct NodoAlumno
{
    Alumno info;
    NodoAlumno *sgte;
    NodoMateria *sublistaMaterias = NULL;
};

NodoAlumno *ObtenerSiguiente(NodoAlumno *n)

{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void agregarNodo(NodoAlumno *&listaAlumno, Alumno a)
{
    NodoAlumno *nuevo = new NodoAlumno();
    nuevo->info = a;
    nuevo->sgte = NULL;

    if (listaAlumno == NULL)
    {
        listaAlumno = nuevo;
    }
    else
    {

        NodoAlumno *aux = listaAlumno;

        while (aux->sgte != NULL)
        {
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }

    return;
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

        if (milista->sublistaMaterias)
        {
            while (milista->sublistaMaterias)
            {
                cout << "MATERIA: " << endl;
                cout << milista->sublistaMaterias->info.nombreMateria << endl;
                cout << milista->sublistaMaterias->info.fechaAprobacion << endl;
                cout << milista->sublistaMaterias->info.nota << endl;
                cout << milista->sublistaMaterias->info.libro << endl;
                cout << milista->sublistaMaterias->info.folio << endl;

                milista->sublistaMaterias = milista->sublistaMaterias->sgte;
            }
        }
        else
        {
            cout << "El alumno no tiene materias agregadas" << endl;
        }

        milista = milista->sgte;
    }
}

void agregarSublista(NodoAlumno *listaAlumno, Materia m)
{
    NodoMateria *nuevo = new NodoMateria();
    NodoAlumno *aux = listaAlumno;
    nuevo->info = m;
    nuevo->sgte = NULL;

    if (aux->sublistaMaterias == NULL)
    {
        aux->sublistaMaterias = nuevo;
    }
    else
    {

        NodoMateria *auxSub = aux->sublistaMaterias;

        while (auxSub->sgte != NULL)
        {
            auxSub = auxSub->sgte;
        }

        auxSub->sgte = nuevo;
    }

    return;
}

void agregarMateria(NodoAlumno *listaAlumno, char ruta_archivo[])
{
    FILE *p;
    Materia m;
    p = fopen(ruta_archivo, "rb");
    if (p == NULL)
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    NodoAlumno *aux = listaAlumno;

    while (aux)
    {

        while (fread(&m, sizeof(Materia), 1, p))
        {
            if (aux->info.legajo == m.legajoAlumno)
            {
                agregarSublista(aux, m);
            }
        }
        rewind(p);
        aux = aux->sgte;
    }
    fclose(p);
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

int main()
{

    /* CARGA DE ARCHIVO */
    /*
    FILE *arch = fopen("alumnos.dat", "wb");
    Alumno alumn;

    FILE *arch2 = fopen("materias.dat", "wb");
    Materia mat;

    for (int i = 0; i < 2; i++)
    {
        cout << "Ingrese nombre: ";
        cin >> alumn.nombre;
        cout << "Ingrese apellido: ";
        cin >> alumn.apellido;
        cout << "Ingrese dni: ";
        cin >> alumn.dni;
        cout << "Ingrese legajo: ";
        cin >> alumn.legajo;
        cout << "Ingrese codigo de carrera: ";
        cin >> alumn.codCarrera;

        cin.ignore();
        fwrite(&alumn, sizeof(Alumno), 1, arch);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "MATERIAS" << endl;
        cout << "Ingrese legajo del alumno " << endl;
        cin >> mat.legajoAlumno;
        cout << "Ingrese nombre de la materia: " << endl;
        cin >> mat.nombreMateria;
        cout << "Ingrese fecha de aprobacion: " << endl;
        cin >> mat.fechaAprobacion;
        cout << "Ingrese nota: " << endl;
        cin >> mat.nota;
        cout << "Ingrese libro: " << endl;
        cin >> mat.libro;
        cout << "Ingrese folio: " << endl;
        cin >> mat.folio;

        fwrite(&mat, sizeof(Materia), 1, arch2);
    }

    fclose(arch);
    fclose(arch2);
    */
    /*
            arch = fopen("alumnos.dat", "rb");
            arch2 = fopen("materias.dat", "rb");

            while (fread(&alumn, sizeof(Alumno), 1, arch) && fread(&mat, sizeof(Materia), 1, arch2))
            {
                cout << "Nombre: " << alumn.nombre << endl;
                cout << "Apellido: " << alumn.apellido << endl;
                cout << "DNI: " << alumn.dni << endl;
                cout << "Legajo:  " << alumn.legajo << endl;
                cout << "Codigo de carrera: " << alumn.codCarrera << endl;
                cout << "MATERIA: " << endl;
                cout << "Legajo alumno: " << mat.legajoAlumno << endl;
                cout << "Nombre de Materia: " << mat.nombreMateria << endl;
                cout << "Fecha de aprobacion: " << mat.fechaAprobacion << endl;
                cout << "Nota: " << mat.nota << endl;
                cout << "Libro: " << mat.libro << endl;
                cout << "Folio: " << mat.folio << endl;
                cout << "-----------------" << endl;
            }
            fclose(arch);
            fclose(arch2);
*/

    NodoAlumno *listaAlumno = NULL;

    insertarEnLista("alumnos.dat", listaAlumno);

    agregarMateria(listaAlumno, "materias.dat");

    MostrarLista(listaAlumno);
}