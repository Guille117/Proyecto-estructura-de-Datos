#pragma once
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include<iostream>
using namespace std;

struct Pago {
	string nombre;
	string apellido;
	int numCarnet;
	string carrera;
	int mesesMulta;
	float totalMulta;
};

struct NodoS {
	Pago pago;
	NodoS* siguiente;
};

int menuLS();
void iniciarListaS();
Pago PedirDatosLS();
void agregarPagoS(NodoS*&, NodoS*&);
void mostrarPagoS(NodoS*);
void mostrar1PagoS(NodoS*, int);
NodoS* buscarPagoS(NodoS*, NodoS*, int);
void buscarYmostrar(NodoS*, NodoS*);
void eliminarPagoS(NodoS*&, NodoS*&);
void vaciarListaS(NodoS*&, NodoS*&);


#endif // !LISTASIMPLE_H

