#pragma once
#ifndef PAGOMENSUALIDAD_H
#define PAGOMENSUALIDAD_H
#include <iostream>
using namespace std;

struct PagoMensualidad {
	string nombre;
	string apellido;
	string identificador;
	string carrera;
	string semestre;
	string mes;
	float cantidad;
};

struct Nodo {
	PagoMensualidad pago;
	Nodo* siguiente;
};

void iniciarCola(Nodo*&, Nodo*&);
PagoMensualidad pedirDatos();	
void push(Nodo*&, Nodo *&, PagoMensualidad);
void mostrar();
void pop();
void menu();
void iniciar();



#endif
