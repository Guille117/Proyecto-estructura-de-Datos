

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "rlutil.h"
#include <cstring>
#include "nuevoIngreso.h"
using namespace std;

void menuPila() {
    system("cls");

    //pila
    Estudiante* pila = NULL;

    //varibles de menu
    int opcion = 1;
    int y = 0;
    rlutil::locate(5, 3);
    cout << "Opciones a realizar sobre el Estudiante";

    do
    {
        menuPilaOp();
        int totalOpciones = 7;
        rlutil::locate(3, 5 + y);
        cout << (char)175 << endl;
        int key = rlutil::getkey();
        rlutil::locate(3, 5 + y);
        cout << " " << endl;

        switch (key)
        {
        case 14:
            y--;
            if (y < 0) y = totalOpciones - 1;
            break;
        case 15:
            y++;
            if (y >= totalOpciones) y = 0;
            break;
        case 1:
            switch (y)
            {
            case 0:
                IngresardatosPila(pila);
                break;
            case 1:
                VerdatosPila(pila);
                break;
            case 2:
                ModificardatosPila(pila);
                break;
            case 3:
                BuscardatosPila(pila);
                break;
            case 4:
                EliminartodoPila(pila);
                break;
            case 5:
                EliminardatoPila(pila);
                break;
            case 6:
                opcion = 0;
                break;
            default:
                break;
            }
        default:
            break;
        }

    } while (opcion != 0);
    system("cls");
}

void menuPilaOp() {
    rlutil::hidecursor();
    rlutil::locate(5, 5);
    cout << "Ingresar datos del Estudiante";
    rlutil::locate(5, 6);
    cout << "Ver datos del Estudiante";
    rlutil::locate(5, 7);
    cout << "Modificar datos del Estudiante";
    rlutil::locate(5, 8);
    cout << "Buscar por estudiante";
    rlutil::locate(5, 9);
    cout << "Eliminar datos";
    rlutil::locate(5, 10);
    cout << "Eliminar un dato";
    rlutil::locate(5, 11);
    cout << "Salir";
}

void IngresardatosPila(Estudiante*& pila) {
    system("cls");
    rlutil::showcursor();
    Estudiante* nuevoEstudiante = new Estudiante();

    cout << "Nombre del Estudiante: " << endl;
    cin.ignore();
    cin.getline(nuevoEstudiante->nombre, 30, '\n');

    cout << "Apellido del Estudiante: " << endl;
    cin.getline(nuevoEstudiante->apellido, 30, '\n');

    cout << "Ingrese el No. del Estudiante: " << endl;
    cin >> nuevoEstudiante->id;

    cout << "Carrera a seguir: " << endl;
    cout << "1. Ingeniería" << endl;
    cout << "2. Medicina" << endl;
    cout << "3. Derecho" << endl;
    cout << "4. Economía" << endl;
    cout << "5. Arquitectura" << endl;

    int opcionCarrera;
    cin >> opcionCarrera;

    switch (opcionCarrera) {
    case 1:
        strcpy_s(nuevoEstudiante->carrera, "Ingeniería");
        break;
    case 2:
        strcpy_s(nuevoEstudiante->carrera, "Medicina");
        break;
    case 3:
        strcpy_s(nuevoEstudiante->carrera, "Derecho");
        break;
    case 4:
        strcpy_s(nuevoEstudiante->carrera, "Economía");
        break;
    case 5:
        strcpy_s(nuevoEstudiante->carrera, "Arquitectura");
        break;

    default:
        cout << "Opción inválida. Se asignará 'Sin definir' como carrera." << endl;
        strcpy_s(nuevoEstudiante->carrera, "Sin definir");
        break;
    }

    nuevoEstudiante->siguiente = pila;
    pila = nuevoEstudiante;
    system("cls");
}

void VerdatosPila(Estudiante*& pila) {
    int e = 0;
    system("cls");
    struct Estudiante* temporal = pila;

    if (temporal != NULL)
    {
        rlutil::locate(5, 2);
        cout << "DATOS DEL ESTUDIANTE" << endl;
        while (temporal != NULL)
        {

            rlutil::locate(5, 4 + e);
            cout << "ID: " << endl;
            rlutil::locate(20, 4 + e);
            cout << temporal->id << endl;

            rlutil::locate(5, 5 + e);
            cout << "Nombre: " << endl;
            rlutil::locate(20, 5 + e);
            cout << temporal->nombre << endl;

            rlutil::locate(5, 6 + e);
            cout << "Apellido: " << endl;
            rlutil::locate(20, 6 + e);
            cout << temporal->apellido << endl;

            rlutil::locate(5, 7 + e);
            cout << "Carrera: " << endl;
            rlutil::locate(20, 7 + e);
            cout << temporal->carrera << endl;

            rlutil::locate(5, 8 + e);
            cout << "Direccion: " << endl;
            rlutil::locate(20, 8 + e);
            cout << temporal << endl;

            rlutil::locate(5, 9 + e);
            cout << "Direccion Anterior: " << endl;
            rlutil::locate(20, 9 + e);
            cout << temporal->siguiente << endl;

            temporal = temporal->siguiente;
            e = e + 8;
        }
    }
    else
    {
        rlutil::locate(5, 3);
        cout << "NO HAY DATOS AUN" << endl;
    }
    system("pause");
    system("cls");
}

void ModificardatosPila(Estudiante*& pila) {
    system("cls");
    rlutil::showcursor();
    struct Estudiante* aux1 = pila;
    if (aux1 != NULL)
    {
        bool encontrado = false;
        int id = 0;
        rlutil::locate(5, 5);
        cout << "Ingrese el No. del Estudiante: ";
        cin >> id;

        while (aux1 != NULL && encontrado != true)
        {
            if (aux1->id == id) {
                rlutil::locate(5, 7);
                cout << "El No. del estudiante " << id << " fue encontrado" << endl;
                rlutil::locate(5, 9);
                cout << "ingrese la nueva carrera del estudiante" << endl;
                cin.ignore();
                rlutil::locate(5, 10);
                cin.getline(aux1->carrera, 100, '\n');
                encontrado = true;
            }
            aux1 = aux1->siguiente;
        }

        if (encontrado == false)
        {
            rlutil::locate(5, 7);
            cout << "No se encontro el estudiante" << endl;
        }
    }
    else
    {
        cout << "La pila esta vacia" << endl;
    }
    system("pause");
    system("cls");
}

void BuscardatosPila(Estudiante*& pila) {
    system("cls");
    rlutil::showcursor();
    struct Estudiante* aux2 = pila;
    if (aux2 != NULL)
    {
        bool encontrado = false;
        int id = 0;
        rlutil::locate(5, 3);
        cout << "Ingrese el No. del Estudiante :" << endl;
        rlutil::locate(5, 4);
        cin >> id;

        while (aux2 != NULL && encontrado != true)
        {
            if (aux2->id == id) {
                rlutil::locate(5, 6);
                cout << "El No. del estudiante " << id << " fue encontrado" << endl;
                rlutil::locate(5, 8);
                cout << "Nombre: " << aux2->nombre << endl;
                rlutil::locate(5, 9);
                cout << "Apellido: " << aux2->apellido << endl;
                rlutil::locate(5, 10);
                cout << "Carrera: " << aux2->carrera << endl;
                encontrado = true;
            }
            aux2 = aux2->siguiente;
        }

        if (encontrado == false)
        {
            cout << "No se encontro el Estudiante" << endl;
        }

    }
    else
    {
        cout << "La pila esta vacia" << endl;
    }
    system("pause");
    system("cls");
}

void EliminartodoPila(Estudiante*& pila) {
    system("cls");
    while (pila != NULL)
    {
        Estudiante* aux3 = pila;
        pila = aux3->siguiente;
        delete aux3;
    }
    cout << "TODOS LOS DATOS DE LA PILA HAN SIDO ELIMINADO" << endl;
    system("pause");
    system("cls");
}

void EliminardatoPila(Estudiante*& pila) {
    system("cls");
    if (pila != NULL)
    {
        system("cls");
        Estudiante* aux3 = pila;

        rlutil::setColor(14);
        rlutil::locate(50, 16); cout << "HEMOS ELIMINADO EL ESTUDIANTE CON EL NOMBRE: ";
        rlutil::setColor(2);
        rlutil::locate(100, 16); cout << aux3->nombre;
        rlutil::setColor(3);

        pila = aux3->siguiente;
        delete aux3;

        cout << endl; cout << endl;
        rlutil::setColor(8);
        system("pause");
        system("cls");
        VerdatosPila(pila);
        return;
    }
    Msgnohaydatos();
    system("cls");
};

void Msgnohaydatos() {
    system("cls");
    cout << "NO SE ENCONTRO NINGUN DATO PARA ELIMINAR";
}



