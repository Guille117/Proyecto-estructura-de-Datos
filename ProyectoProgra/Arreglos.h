
#ifndef ARREGLOS_H
#define ARREGLOS_H
#include <iostream>
#include <string>
using namespace std;

extern const std::string Carrera[];
extern const string Mes[];
extern const float cantidad[];
extern const string semestre[];

int RecorrerArregloString(const string arreglo[], int x, int y);
int RecorrerArregloString2(const string arreglos[], int x, int y, int inicioArreglo, int tam);		// esta función permite un entero que sirve como tamaño para indicar hasta donde se recorre

#endif
