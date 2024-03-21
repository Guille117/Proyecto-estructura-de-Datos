#pragma once
#ifndef LISTADE_H
#define LISTADE_H
#include<iostream>
#include<unordered_set>
using namespace std;

struct PagoSemestre {
	int id;
	string nombre;
	string apellido;
	string carne;
	string carrera;
	string semestre;
	float sinDescuento;
	float conDescuento;
};

struct LDE_Nodo {
	PagoSemestre pago;
	LDE_Nodo* anterior;
	LDE_Nodo* siguiente;
};



int menuLista();
void iniciarListaDE();
PagoSemestre pedirDatosLDE(bool);
void ingresar(LDE_Nodo*&, LDE_Nodo*&);
void mostrar(LDE_Nodo*);
void mostrarInverso(LDE_Nodo*);
void eliminarLDE(LDE_Nodo*&, LDE_Nodo*&);
void vaciarLDE(LDE_Nodo*&, LDE_Nodo*&);
LDE_Nodo* buscarPagoLDE(LDE_Nodo*, LDE_Nodo*);
void mostrar1Pago(LDE_Nodo*);
void ModificarPagoLDE(LDE_Nodo*, LDE_Nodo* );




#endif // LISTADE_H
