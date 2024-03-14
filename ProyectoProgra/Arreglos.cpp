#include"Arreglos.h"
#include"Utilidades.h"
#include<iostream>
using namespace std;

const std::string Carrera[] = {				
"INGENIERIA EN SISTEMAS",
"PSICOLOGIA",
"DERECHO",
"CRIMINOLOGIA",
"TRABAJO SOCIAL"
};

const string Mes[] = {
	"Febrero",
	"Marzo",
	"Abril",
	"Mayo",
	"Junio",
	"Julio",
	"Agosto",
	"Septiembre",
	"Octubre",
	"Noviembre"
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
	int a = x, b = y;
	int opcion = 0, contador = y, inicioY = y;
	int elementos = 0;

	for (int i = 0; !arreglos[i].empty(); i++) {
		gotoxy(x, y++); cout << arreglos[i] << ". ";
		contador++;
		elementos++;
	}
	opcion = navegador(x - 3, y -elementos, elementos);

	borrarLineas(0, inicioY-2 , 150, contador+5);

	return opcion;
}

int RecorrerArregloString2(const string arreglos[], int x, int y, int inicioArreglo, int tam) {
	int opcion = 0, contador = y, inicioY = y;

	for (int i = inicioArreglo; i<tam; i++) {
		gotoxy(x, y++); cout << arreglos[i] << ". ";
		contador++;
	}

	opcion = navegador(x - 3, y - 5, 5);

	borrarLineas(0, inicioY - 2, 150, contador + 5);

	return opcion;
}