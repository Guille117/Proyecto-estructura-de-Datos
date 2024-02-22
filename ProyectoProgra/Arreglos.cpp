#include"Arreglos.h"
#include"Utilidades.h"
#include<iostream>
using namespace std;

const std::string Carrera[] = {
"INGENIERIA EN SISTEMAS",
"PSICOLOGIA",
"DERECHO",
"ADMINISTRACION DE EMPRESAS",
"TRABAJO SOCIAL"
};

const string Mes[] = {
	"FEBRERO",
	"MARZO",
	"ABRIL",
	"MAYO",
	"JUNIO",
	"JULIO",
	"AGUSTO",
	"SEPTIEMBRE",
	"OCTUBRE",
	"NOVIEMBRE"
};

const float cantidad[] = {
	450,
	320,
	340,
	420,
	500
};

const string semestre[] = {
	"Primero",
	"Segundo",
	"Tercero",
	"Cuarto",
	"Quinto",
	"Sexto",
	"Septimo",
	"Octavo",
	"Noveno",
	"Decimo"
};

int RecorrerArregloString(const string arreglos[], int x, int y) {
	int opcion = 0, contador = y, inicioY = y;

	for (int i = 0; !arreglos[i].empty(); i++) {
		gotoxy(x, y++); cout << i + 1 << " " << arreglos[i] << ". ";
		contador++;
	}

	gotoxy(x, contador+1); cout << "Opcion: ";
	cin >> opcion;

	borrarLineas(0, inicioY-2 , 150, contador+5);

	return opcion;
}

int RecorrerArregloString2(const string arreglos[], int x, int y, int inicioArreglo, int tam) {
	int opcion = 0, contador = y, inicioY = y;

	for (int i = inicioArreglo; i<tam; i++) {
		gotoxy(x, y++); cout << i + 1 << " " << arreglos[i] << ". ";
		contador++;
	}

	gotoxy(x, contador + 1); cout << "Opcion: ";
	cin >> opcion;

	borrarLineas(0, inicioY - 2, 150, contador + 5);

	return opcion;
}