#include"Utilidades.h"
#include"Arreglos.h"
#include"PagoMensualidad.h"
#include<iostream>
using namespace std;
int x = 0, y = 0;			//coordenadas 

void inicarCola(Nodo*& inicio, Nodo*& final) {
	inicio = nullptr;
	final = nullptr;
}

PagoMensualidad pedirDatos() {
	x = 20; y = 2;
	int ciclo, aux=0;
	PagoMensualidad p;

	system("cls");

	gotoxy(x, y); cout << "  Ingreso de datos para Pago de Mensualidad ";

	gotoxy(x+=10, y+=3); cout << " Nombre: ";
						 cin >> p.nombre;
	gotoxy(x, y += 1);	 cout << " Apellido: ";
					     cin >> p.apellido;
	gotoxy(x, y += 1);   cout << " No. de carne: ";
						 cin >> p.identificador;
						 
						 // Items seleccionables...

	gotoxy(x, y += 1);	 cout << " Facultad: ";						// primera vez que se muestra 
	aux = (RecorrerArregloString(Carrera, x + 1, y + 2)-1);			// mostramos las posibles opciones y almacenamos la selección, ademas borramos pantalla
	gotoxy(x, y);		 cout << " Facultad: " << Carrera[aux];		// mostramos por ultima vez
	p.carrera = Carrera[aux];										// almecenamos el dato
/**/	p.cantidad = cantidad[aux];										// asignamos la primera cantidad, cada carrera tiene un costo diferente


	gotoxy(x, y += 1);   cout << " Semestre:  ";
	aux = (RecorrerArregloString(semestre, x + 1, y + 2) -1);		// menos 1 por que el usuario observa las opciones a partir de 1
	gotoxy(x, y);		 cout << " Semestre: " << semestre[aux];
	p.semestre = semestre[aux];
	p.cantidad = p.cantidad + (aux * 10);							// completamos la cantidad a pagar, cada semestre la mensualidad aumenta 10 Q


	gotoxy(x, y += 1);   cout << " Mes: ";
	if (esPar(aux)) {													// separamos los meses a corde el semestre
		aux = (RecorrerArregloString2(Mes, x + 1, y + 2, 5, 10));
	}
	else {
		aux = (RecorrerArregloString2(Mes, x + 1, y + 2, 0, 5));
	}
	gotoxy(x, y);   cout << " Mes: " << Mes[aux-1];
	p.mes = Mes[aux-1];


	gotoxy(x, y += 1); cout << " Total: " << p.cantidad << endl << endl;
	
	return p;
}

void push(Nodo*& inicio, Nodo*& fin, PagoMensualidad pagoM) {
	Nodo* nuevoNodo = new Nodo();		// crear espacio en memorio
	nuevoNodo->pago = pagoM;			// rellenar datos;
	nuevoNodo->siguiente = nullptr;  	// es null por que siempre sera el fin de la cola

	if (inicio == nullptr) {			// preguntamos si hay elementos en la cola
		inicio = nuevoNodo;
	}
	else {
		fin->siguiente = nuevoNodo;		// decimos que ahora el fin ya no es el fin y apuntamos al nuevo nodo
	}

	fin = nuevoNodo;					// cambiamos el fin

	gotoxy(x, y + 2);cout << "Dato ingresado con exito." << endl << endl;
	system("pause");
}

void mostrar(Nodo* inicio) {
	system("cls");
	x = 6, y = 5;

	if (inicio != nullptr) {
		gotoxy(x+30, y);cout << "Mostrando pagos de mensualidades";

		while (inicio != nullptr) {
			y = 9;
			gotoxy(x, y++);cout << " Nombre: "<<inicio->pago.nombre;
			gotoxy(x, y++);cout << " Apellido: "<<inicio->pago.apellido;
			gotoxy(x, y++);cout << " No. de carne: "<<inicio->pago.identificador;
			gotoxy(x, y++);cout << " Facultad: "<<inicio->pago.carrera;
			gotoxy(x, y++);cout << " Semestre:  "<<inicio->pago.semestre;
			gotoxy(x, y++);cout << " Mes:  "<<inicio->pago.mes;
			gotoxy(x, y++);cout << " Cantidad: " << inicio->pago.cantidad << endl << endl;
			inicio = inicio->siguiente;
			x += 40;
		}
		system("pause");
	}
	else {
		gotoxy(x + 30, y+8);cout << "No hay pagos para mostrar...\n\n\n";
		system("pause");
	}
	
}

void menu() {
	int y = 7, x = 30;
	system("cls");
	gotoxy(x-5, y);cout << "  Opciones para Pago de Mensualidad.";
	gotoxy(x, y+=3);cout << "  1. Realizar pago. ";
	gotoxy(x, y+=1);cout << "  2. Mostrar pagos. ";
	gotoxy(x, y+=1);cout << "  3. Eliminar pago. ";
	gotoxy(x, y+=1);cout << "  4. Salir. ";
}

void iniciar() {
	int opcion = 0;
	Nodo* inicio;
	Nodo* fin;
	inicarCola(inicio, fin);

	do {
		menu();
		cin >> opcion;

		switch (opcion) {
		case 1: push(inicio, fin, pedirDatos());break;
		case 2: mostrar(inicio);break;
		case 4: system("cls"); cout << " Fin de programa" << endl; system("pause"); break;
		default: system("cls"); cout << " Opcion incorrecta " << endl; system("pause");
		}

	} while (opcion != 4);

}
