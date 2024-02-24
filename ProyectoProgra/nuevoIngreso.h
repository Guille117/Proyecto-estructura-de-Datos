#pragma once
#ifndef NUEVOINGRESO_H
#define NUEVOINGRESO_H
#include <iostream>
using namespace std;

//structura de pila
struct Estudiante
{
    char nombre[30];
    char apellido[30];
    char carrera[100];
    int id;
    Estudiante* siguiente;
};


//menus principales
void menuPila();
void menuPilaOp();
void IngresardatosPila(Estudiante*& pila);
void VerdatosPila(Estudiante*& pila);
void ModificardatosPila(Estudiante*& pila);
void BuscardatosPila(Estudiante*& pila);
void EliminartodoPila(Estudiante*& pila);
void EliminardatoPila(Estudiante*& pila);
void Msgnohaydatos();


#endif // !NUEVOINGRESO_H

