#include"Utilidades.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <random>
#define RED "\033[1\033[31m"
#define RESET "\033[36m";
using namespace std;

void gotoxy(int x, int y) {
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadas);
}

void borrarLineas(int xInicio, int yInicio, int xFinal, int yFinal) {
	for (int f = xInicio; f <= xFinal;f++) {
		for (int c = yInicio; c <= yFinal;c++) {
			gotoxy(f, c); cout << " ";
		}
	}
}

bool esPar(int num) {
	return num % 2;
}

// esta funci�n recibe tres parametros: coordenadas en X, coordenadas en Y, y numero de opciones.
int navegador(int a, int b, int tama�o) {
    OcultarCursor();
    int contador = 1;
    gotoxy(a, b);cout << RED << ">>" << RESET;;
    while (true) {
        int tecla = _getch();

        if (tecla == 224 || tecla == 0) {
            tecla = _getch();
            if (tecla == 80 && contador != tama�o) { // abajo
                gotoxy(a, b);cout << " ";
                gotoxy(a + 1, b); cout << " ";
                gotoxy(a, ++b);cout << RED << ">>" << RESET;
                contador++;
            }
            else if (tecla == 72 && contador != 1) {
                gotoxy(a, b);cout << " ";
                gotoxy(a + 1, b); cout << " ";
                gotoxy(a, --b);cout << RED << ">>" << RESET;
                contador--;
            }
        }
        if (tecla == 13) {
            return contador;
        }
    }
}

void OcultarCursor() {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void MostrarCursor() {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// funciones que sirven para generar numeros aleatorios
// para usar esta funci�n deber� crear y pasar una lista para guardar los n�meros generados.
int generarId(unordered_set<int>& Lista) {
    random_device rd;
    mt19937 gen(rd());

    int menor = 1;
    int mayor = 100;
    int numero = 0;

    uniform_int_distribution<>dis(menor, mayor);

    do {
        numero = dis(gen);
    } while (existeId(numero, Lista));

    return numero;
}

bool existeId(int numero, unordered_set<int>& listaNumeros) {
    if (listaNumeros.find(numero) == listaNumeros.end()) {
        return false;
    }
    else {
        return true;
    }
}

// funciones que sirven para generar numeros aleatorios