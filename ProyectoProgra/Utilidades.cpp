#include"Utilidades.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
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
    gotoxy(a, b);cout << ">>";
    while (true) {
        int tecla = _getch();

        if (tecla == 224 || tecla == 0) {
            tecla = _getch();
            if (tecla == 80 && contador != tamaño) { // abajo
                gotoxy(a, b);cout << " ";
                gotoxy(a + 1, b); cout << " ";
                gotoxy(a, ++b);cout << ">>";
                contador++;
            }
            else if (tecla == 72 && contador != 1) {
                gotoxy(a, b);cout << " ";
                gotoxy(a + 1, b); cout << " ";
                gotoxy(a, --b);cout << ">>";
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