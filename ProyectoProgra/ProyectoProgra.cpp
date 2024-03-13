
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Utilidades.h"
#include <conio.h>
#include "PagoMensualidad.h"
#include "nuevoIngreso.h"
using namespace std;

void portada();
void menuPrincipal();



int main() {
    int op = 0;

    portada();

    do {
        menuPrincipal();
        cin >> op;

        switch (op) {
        case 1: menuPila(); break;
        case 2: iniciar(); break;
        case 3: system("cls"); gotoxy(35, 10); cout << "Fin del programa...\n\n\n\n\n"; break;
        default: system("cls"); gotoxy(35, 10); cout << "Opcion incorrecta...";_getch();
        }
    } while (op != 3);
    
}


void portada() {
    system("color 0B");
    setlocale(LC_ALL, "");
    gotoxy(15, 5);  wcout << "*********************************************" << std::endl;
    gotoxy(15, 6); wcout << "* BIENVENIDO A LA UNIVERSIDAD DEL OCCIDENTE *" << std::endl;
    gotoxy(15, 7); wcout << "*********************************************" << std::endl;
    gotoxy(15, 8); wcout << "-                                           -" << std::endl;
    gotoxy(15, 9); wcout << "- Nombre: Universidad del Occidente         -" << std::endl;
    gotoxy(15, 10); wcout << "- Direccion: Solola, Guatemala              -" << std::endl;
    gotoxy(15, 11); wcout << "- Telefono: 56789054                        -" << std::endl;
    gotoxy(15, 12); wcout << "-                                           -" << std::endl;
    gotoxy(15, 13); wcout << "---------------------------------------------" << std::endl;
    gotoxy(15, 14); wcout << "-               PROGRAMADORES               -" << std::endl;
    gotoxy(15, 15); wcout << "---------------------------------------------" << std::endl;
    gotoxy(15, 16); wcout << "-     Carlos Enrique Bocel Coj              -" << std::endl;
    gotoxy(15, 17); wcout << "-     Guillermo Francisco Bixcul Coroxon    -" << std::endl;
    gotoxy(15, 18); wcout << "-     Suany Alexia Samantha Avila Julajuj   -" << std::endl;
    gotoxy(15, 19); wcout << "---------------------------------------------" << std::endl;
    gotoxy(15, 20); wcout << "Precione ENTER para continuar:  ";_getch();
}

void menuPrincipal() {
    system("cls");
    system("color 0B");
    setlocale(LC_ALL, "");

        gotoxy(30, 5); cout << "**** UNIVERSIDAD DEL OCCIDENTE ******";
        gotoxy(30, 6); cout << "**  Ingreso de Datos (Pila)....[1] **";
        gotoxy(30, 7); cout << "**  Pago de matricula (Cola)...[2] **";
        gotoxy(30, 8); cout << "**  Cierre del Programa........[3] **";
        gotoxy(30, 9); cout << "*************************************";
        gotoxy(30, 10); cout << " Ingrese Una Opcion: ";
}