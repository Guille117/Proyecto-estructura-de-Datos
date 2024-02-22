#include"Utilidades.h"
#include<iostream>
#include<Windows.h>
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