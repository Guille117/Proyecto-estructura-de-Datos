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

int navegador(int a, int b, int tamaño) {
    OcultarCursor();
    int contador = 1;
    gotoxy(a, b);cout << RED << ">>" << RESET;;
    while (true) {
        int tecla = _getch();

        if (tecla == 224 || tecla == 0) {
            tecla = _getch();
            if (tecla == 80 && contador != tamaño) { // abajo
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

int generarId(unordered_set<int>& Lista) {
    random_device rd;
    mt19937 gen(rd());

    int menor = 1;
    int mayor = 300;
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