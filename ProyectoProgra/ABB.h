#pragma once
#ifndef ABB_H
#define ABB_H

#include<iostream>
using namespace std;

struct PrestamoToga {
	int id;
	string nombre;
	string apellido;
	string carnet;
	string carrera;
	float total;
};

struct NodoToga {
	PrestamoToga pres;
	NodoToga* padre;
	NodoToga* izquierda;
	NodoToga* derecha;
};

int menuA();
void iniciarArbol();
NodoToga* crearNodoT();
PrestamoToga pedirDatos();
void mostrar1PrestamoT(NodoToga*);
void mostrarPrestamos();
/////////////////Recorridos//////////////////////////////////
void guardarPrestamo(NodoToga*&, NodoToga*);
void AUXguardarPrestamo(NodoToga*&);

NodoToga* BuscarAlqui(NodoToga*, int dato);
NodoToga* AUXBuscarAlqui(NodoToga*);

void RecorrerInOrden(NodoToga*);
void AUXInOrden(NodoToga*);

void RecorrerPreOrden(NodoToga*);
void AUXPreOrden(NodoToga*);

void RecorrerPostOrden(NodoToga*);
void AUXPostOrden(NodoToga*);

void eliminarT(NodoToga*&, NodoToga*&);
void AuxEliminarT(NodoToga*&);

void ELIMhoja(NodoToga*&, NodoToga*&);
void ELIMnodo1hijo(NodoToga*&, NodoToga*&);
void ELIMnodo2hijos(NodoToga*&, NodoToga*&);


/////////////////Recorridos//////////////////////////////////

NodoToga* HallarHeredero(NodoToga*);

void ayuda1(NodoToga*&, int);



#endif // !ABB_H
