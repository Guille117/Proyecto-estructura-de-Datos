#include <iostream>
#include <string>
#include <cstdlib>
#include "rlutil.h"
#include"NotaFinal.h"
using namespace std;


void menulistacircular() {
    system("cls");

    NodoLista* cabeza = nullptr;
    NodoLista* ultimo = nullptr;

    int opcion = 1;
    int y = 0;
    rlutil::locate(5, 3);
    cout << "Opciones a realizar sobre el estudiante";

    do {
        menuseccircu(3, 5); // Cambio de posición fija a parámetros
        int totalOpciones = 6;
        rlutil::locate(3, 5 + y);
        cout << (char)175 << endl;
        int key = rlutil::getkey();
        rlutil::locate(3, 5 + y);
        cout << " " << endl;

        switch (key) {
        case 14:
            y--;
            if (y < 0) y = totalOpciones - 1;
            break;
        case 15:
            y++;
            if (y >= totalOpciones) y = 0;
            break;
        case 1:
            switch (y) {
            case 0:
                IngresarCircular(cabeza, ultimo);
                break;
            case 1:
                MostrarCircular(cabeza, ultimo);
                break;
            case 2:
                ModificarCircular(cabeza);
                break;
            case 3:
                EliminarCircular(cabeza, ultimo);
                break;
            case 4:
                VaciarCircular(cabeza, ultimo);
                break;
            case 5:
                opcion = 0;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    } while (opcion != 0);
    system("cls");
}

///menu secundaria
void menuseccircu(int x, int y) {
    rlutil::hidecursor();
    rlutil::locate(x, y);
    cout << "Ingresar datos del estudiante";
    rlutil::locate(x, y + 1);
    cout << "Ver datos del estudiante";
    rlutil::locate(x, y + 2);
    cout << "Modificar datos del estudiante";
    rlutil::locate(x, y + 3);
    cout << "Eliminar datos del estudiante";
    rlutil::locate(x, y + 4);
    cout << "Vaciar datos del estudiante";
    rlutil::locate(x, y + 5);
    cout << "Salir";
}

//ingresar datos
void IngresarCircular(NodoLista*& cabeza, NodoLista*& ultimo) {
    rlutil::cls();
    rlutil::showcursor();

    NodoLista* nuevoNodo = new NodoLista();
    cout << "Nombre del estudiante: ";
    cin.ignore();
    getline(cin, nuevoNodo->estudiante.nombre);
    cout << "Numero del estudiante: ";
    cin >> nuevoNodo->estudiante.numeroEstudiante;
    cout << "Nota Final: ";
    cin >> nuevoNodo->estudiante.nota;
    nuevoNodo->siguiente = nullptr;
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        ultimo = nuevoNodo;
        ultimo->siguiente = cabeza;
    }
    else {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabeza;
        ultimo = nuevoNodo;
    }
    rlutil::cls();
}

//mostrar
void MostrarCircular(NodoLista* cabeza, NodoLista* ultimo) {
    system("cls");
    int xG = 0;
    int yG = 3;

    if (cabeza != nullptr) {
        NodoLista* actual = cabeza;
        do {
            cout << "Nombre: " << actual->estudiante.nombre << endl;
            cout << "Numero del estudiante: " << actual->estudiante.numeroEstudiante << endl;
            cout << "Nota Final: " << actual->estudiante.nota << endl;
            cout << endl;

            actual = actual->siguiente;
        } while (actual != cabeza);
    }
    else {
        cout << "No hay datos para mostrar." << endl;
    }
    cout << endl << endl << endl << endl << endl << endl;
    system("pause");
    system("cls");
}

//modificar
void ModificarCircular(NodoLista*& cabeza) {
    system("cls");
    if (cabeza == nullptr) {
        cout << "No hay datos para modificar." << endl;
        system("pause");
        system("cls");
        return;
    }

    int numeroEstudiante;
    cout << "Ingrese el numero del estudiante cuya nota desea modificar: ";
    cin >> numeroEstudiante;

    NodoLista* actual = cabeza;
    do {
        if (actual->estudiante.numeroEstudiante == numeroEstudiante) {
            float nuevaNota;
            cout << "Ingrese la nueva nota final: ";
            cin >> nuevaNota;

            actual->estudiante.nota = nuevaNota;

            cout << "La nota final ha sido modificada exitosamente." << endl;
            cout << endl;
            system("pause");
            system("cls");
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    cout << "No se encontro ningun estudiante con el numero ingresado." << endl;
    cout << endl;
    system("pause");
    system("cls");
}

//eliminar
void EliminarCircular(NodoLista*& cabeza, NodoLista*& ultimo) {
    system("cls");
    if (cabeza == nullptr) {
        cout << "No hay datos para eliminar." << endl;
        system("pause");
        system("cls");
        return;
    }
    int numeroEstudiante;
    cout << "Ingrese el numero del estudiante cuya nota desea eliminar: ";
    cin >> numeroEstudiante;

    NodoLista* actual = cabeza;
    NodoLista* anterior = nullptr;
    bool encontrado = false;
    do {
        if (actual->estudiante.numeroEstudiante == numeroEstudiante) {
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);

    if (!encontrado) {
        cout << "No se encontro ningun estudiante con el número ingresado." << endl;
        cout << endl;
        system("pause");
        system("cls");
        return;
    }
    if (actual == cabeza) {
        if (cabeza->siguiente == cabeza) {
            delete cabeza;
            cabeza = nullptr;
            ultimo = nullptr;
        }
        else {
            cabeza = cabeza->siguiente;
            ultimo->siguiente = cabeza;
            delete actual;
        }
    }
    else {
        anterior->siguiente = actual->siguiente;
        if (actual == ultimo) {
            ultimo = anterior;
        }
        delete actual;
    }

    cout << "La nota final del estudiante ha sido eliminada exitosamente." << endl;
    cout << endl;
    system("pause");
    system("cls");
}

//vaciar
void VaciarCircular(NodoLista*& cabeza, NodoLista*& ultimo) {
    system("cls");
    if (cabeza == nullptr) {
        cout << "No hay datos para vaciar." << endl;
        system("pause");
        system("cls");
        return;
    }

    NodoLista* actual = cabeza;
    NodoLista* siguiente;
    do {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);

    cabeza = nullptr;
    ultimo = nullptr;

    cout << "Todas las notas finales de los estudiantes han sido eliminadas exitosamente." << endl;

    cout << endl;
    system("pause");
    system("cls");
}