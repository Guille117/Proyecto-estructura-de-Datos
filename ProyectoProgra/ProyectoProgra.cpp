
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Utilidades.h"
#include <conio.h>
#include "PagoMensualidad.h"
#include "nuevoIngreso.h"
#include "ListaDE.h"
#define COLOR "\033[36m"

using namespace std;

void portada();
int menuPrincipal();



int main() {
    cout << COLOR;
    int op = 0;

    portada();

    do {
        
        op = menuPrincipal();

        switch (op) {
        case 1: menuPila(); break;
        case 2: iniciar(); break;
        case 3: system("cls"); gotoxy(35, 10); cout << "Lista enlazada simple...\n\n\n\n\n"; _getch();break;
        case 4: system("cls"); gotoxy(35, 10); cout << "Lista enlazada circular...\n\n\n\n\n";_getch(); break;
        case 5: iniciarListaDE();break;
        case 6: system("cls"); gotoxy(35, 10); cout << "Fin del programa...\n\n\n\n\n"; _getch();break;
        default: system("cls"); gotoxy(35, 10); cout << "Opcion incorrecta...";_getch();
        }
    } while (op != 6);
    
}


void portada() {
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

int menuPrincipal() {
    system("cls");
    setlocale(LC_ALL, "");

        gotoxy(30, 5); cout << "**** UNIVERSIDAD DEL OCCIDENTE ******";
        gotoxy(34, 8); cout << " Inscripcion Ordinaria.     (Pila)";
        gotoxy(34, 9); cout << " Pago de Mensualidad.       (Cola)";
        gotoxy(34, 10); cout << " Pendiente.                 (Lista enlazada simple)";
        gotoxy(34, 11); cout << " Pendiente.                 (Lista enlazada simple circular)";
        gotoxy(34, 12); cout << " Pago de semestre.          (Lista enlazada doble)";
        gotoxy(34, 13); cout << " Cierre del Programa.";

        return navegador(32, 8, 6);
}