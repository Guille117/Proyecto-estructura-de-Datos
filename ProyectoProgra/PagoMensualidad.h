#pragma once
#ifndef PAGOMENSUALIDAD_H
#define PAGOMENSUALIDAD_H
#include <iostream>
using namespace std;

struct PagoMensualidad {
	int idPago;
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
PagoMensualidad pedirDatos(bool);	
void push(Nodo*&, Nodo *&, PagoMensualidad);
void mostrar(Nodo*);
void pop(Nodo*&, Nodo*&, bool);
void menu();
void iniciar();
void mostrar1Nodo(Nodo*);
void vaciarRegistros(Nodo*&, Nodo*& fin);
Nodo* buscarRegistro(Nodo *);
void modificarRegistro(Nodo* );



#endif
