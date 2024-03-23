#pragma once
#ifndef NOTAFINAL_H
#define NOTAFINAL_H
#include<iostream>
#include<string>
using namespace std;

struct EstudianteA {
    string nombre;
    int numeroEstudiante;
    float nota;
};

struct NodoLista {
    EstudianteA estudiante;
    NodoLista* siguiente;
};

/// Declaraciones de funciones
void menulistacircular();
void menuseccircu(int x, int y);
void IngresarCircular(NodoLista*& cabeza, NodoLista*& ultimo);
void MostrarCircular(NodoLista* cabeza, NodoLista* ultimo);
void ModificarCircular(NodoLista*& cabeza);
void EliminarCircular(NodoLista*& cabeza, NodoLista*& ultimo);
void VaciarCircular(NodoLista*& cabeza, NodoLista*& ultimo);


#endif // !NOTAFINAL_H