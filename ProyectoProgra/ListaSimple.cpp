#include<iostream>
#include<Windows.h>
#include<conio.h>
#include "ListaSimple.h"
#include "Arreglos.h"
#include "Utilidades.h"

using namespace std;
int xs = 0, ys = 0;

int menuLS() {
	ys = 7, xs = 30;
	system("cls");
	gotoxy(xs - 5, ys);cout << "  Opciones para Pago de Mora.";
	gotoxy(xs, ys += 3);cout << "Realizar pago. ";
	gotoxy(xs, ys += 1);cout << "Mostrar pagos. ";
	gotoxy(xs, ys += 1);cout << "Buscar pago. ";
	gotoxy(xs, ys += 1);cout << "Eliminar pago. ";
	gotoxy(xs, ys += 1);cout << "Vaciar Lista de pagos. ";
	gotoxy(xs, ys += 1);cout << "Atras. ";
	return navegador(xs - 3, ys - 5, 6);
}

void iniciarListaS() {
	int opcion = 0;
	NodoS* inicioS = nullptr;
	NodoS* finS = nullptr;
	
	do {
		opcion = menuLS();

		switch (opcion) {
		case 1: agregarPagoS(inicioS, finS);break;
		case 2: mostrarPagoS(inicioS); break;
		case 3: buscarYmostrar(inicioS, finS);break;
		case 4: eliminarPagoS(inicioS, finS);break;
		case 5: vaciarListaS(inicioS, finS);break;
		case 6: break;
		}
	} while (opcion != 6);
	
}


Pago PedirDatosLS() {
	Pago pa;
	xs = 20; ys = 2;
	int aux = 0;
	system("cls");
	MostrarCursor();
	gotoxy(xs, ys); cout << "  Ingreso de datos para Pago de Mora ";

	gotoxy(xs += 10, ys += 3); cout << " Nombre: ";
	cin >> pa.nombre;
	gotoxy(xs, ys += 1);	 cout << " Apellido: ";
	cin >> pa.apellido;
	gotoxy(xs, ys += 1);   cout << " No. de carne: ";
	cin >> pa.numCarnet;

	// escoger carrera

	gotoxy(xs, ys += 1);	 cout << " Carrera: ";						// primera vez que se muestra 
	aux = (RecorrerArregloString(Carrera, xs + 1, ys + 2) - 1);			// mostramos las posibles opciones y almacenamos la selección, ademas borramos pantalla
	gotoxy(xs, ys);		 cout << " carrera: " << Carrera[aux];		// mostramos por ultima vez
	pa.carrera = Carrera[aux];

	//asignar mora de un mes dependiendo de la carrera aplicando el 2%
	pa.totalMulta = cantidad[aux] * 0.02;
	MostrarCursor();
	gotoxy(xs, ys += 1);   cout << " Numeros de meses de mora: ";
	cin >> pa.mesesMulta;

	pa.totalMulta *= pa.mesesMulta;

	gotoxy(xs, ys += 1);   cout << " Total a pagar: "<<pa.totalMulta;

	return pa;
}

void agregarPagoS(NodoS*& inicioLS, NodoS*& finLS) {
	NodoS* nuevo = new NodoS();
	nuevo->pago = PedirDatosLS();

	if (inicioLS == nullptr) {
		nuevo->siguiente = nullptr;
		inicioLS = nuevo;
		finLS = nuevo;
	}
	else {
		int auxCarnet = nuevo->pago.numCarnet;
		if (auxCarnet <= inicioLS->pago.numCarnet) {
			nuevo->siguiente = inicioLS;
			inicioLS = nuevo;
		}
		else {
			if (auxCarnet >= finLS->pago.numCarnet) {
				nuevo->siguiente = nullptr;
				finLS->siguiente = nuevo;
				finLS = nuevo;
			}
			else {
				bool encontrado = false;
				NodoS* corredor = inicioLS;
				while (corredor != nullptr && !encontrado) {
					if (corredor->siguiente->pago.numCarnet < nuevo->pago.numCarnet) {
						corredor = corredor->siguiente;
					}
					else {
						encontrado = true;
						nuevo->siguiente = corredor->siguiente;
						corredor->siguiente = nuevo;
					}
				}
			}
		}
	}

	gotoxy(xs, ys + 2); cout << "Dato ingresado con exito.";_getch();

}

void mostrarPagoS(NodoS* inicio) {
	system("cls");
	xs = 4, ys = 9;

	if (inicio != nullptr) {
		gotoxy(xs + 40, ys - 4);cout << "Pagos de mora";
		while (inicio != nullptr) {
			mostrar1PagoS(inicio,ys);
			
			inicio = inicio->siguiente;
			ys += 9;
		}
		_getch();
	}
	else {
		gotoxy(40, 7);cout << "Lista vacia...";
		_getch();
	}
	
}

void mostrar1PagoS(NodoS* nodo, int y) {
	gotoxy(5, y++); cout << "Nombre: " << nodo->pago.nombre;
	gotoxy(5, y++); cout << "Apellido: " << nodo->pago.apellido;
	gotoxy(5, y++); cout << "No. de Carne: " << nodo->pago.numCarnet;
	gotoxy(5, y++); cout << "Carrera: " << nodo->pago.carrera;
	gotoxy(5, y++); cout << "Meses de mora: " << nodo->pago.mesesMulta;
	gotoxy(5, y++); cout << "Total: " << nodo->pago.totalMulta;
	gotoxy(5, y++); cout << "Dir. memoria: " << nodo;
}

NodoS* buscarPagoS(NodoS* in, NodoS* fin, int Ncarnet) {
	NodoS* aux = nullptr;

	if (Ncarnet == in->pago.numCarnet) {
		aux = in;
	}
	else {
		if (Ncarnet == fin->pago.numCarnet) {
			aux = fin;
		}
		else {
			bool encontrado = false;
			NodoS* corredor = in;
			while (corredor != nullptr && !encontrado) {
				if (Ncarnet == corredor->pago.numCarnet) {
					encontrado = true;
					aux = corredor;
				}
				else {
					corredor = corredor->siguiente;
				}
			}
		}
			
	}
	return aux;
}

void buscarYmostrar(NodoS* in, NodoS* fin) {
	system("cls");
	if (in != nullptr) {
		int auxCarnet = 0;
		
		gotoxy(4, 2);cout << "Ingrese numero de carnet a buscar: ";
		cin >> auxCarnet;
		
		NodoS* aux = buscarPagoS(in, fin, auxCarnet);
		
		if (aux != nullptr) {
			gotoxy(4, 4);cout << "Pago encontrado...";
			mostrar1PagoS(aux, 6);
			_getch();
		}
		else {
			gotoxy(40, 7);cout << "Pago no encontrado...";
			_getch();
		}
	}
	else {
		gotoxy(40, 7);cout << "Lista vacia...";
		_getch();
	}
	
}

void eliminarPagoS(NodoS*& in, NodoS*& fin) {
	system("cls");
	if (in != nullptr) {
		int auxCarnet = 0;
		NodoS* aux = nullptr;

		gotoxy(4, 2);cout << "Ingrese numero de carnet a buscar: ";
		cin >> auxCarnet;

		if (in->pago.numCarnet == auxCarnet) {
			aux = in;
			in = in->siguiente;
		}
		else {
			bool encontrado = false;
			NodoS* corredor = in;
				while (corredor->siguiente != nullptr && !encontrado) {
					if (corredor->siguiente->pago.numCarnet == auxCarnet) {
						encontrado = true;
						aux = corredor->siguiente;
						if (auxCarnet == fin->pago.numCarnet) {		// si el dato a eliminar esta al final de la lista
							corredor->siguiente = nullptr;
							fin = corredor;
						}
						else {		// sino
							corredor->siguiente = aux->siguiente;
						}
					}
					else {
						corredor = corredor->siguiente;
					}
				}
			
			
			if (!encontrado) {
				gotoxy(40, 7);cout << "Registro no encontrado...";
				_getch();
			}
			
		}
		if (aux != nullptr) {
			mostrar1PagoS(aux, 5);
			delete aux;
			gotoxy(40, 13);cout << "Registro eliminado...";
			_getch();
		}
		
	}
	else {
		gotoxy(40, 7);cout << "Lista vacia...";
		_getch();
	}
}

void vaciarListaS(NodoS*& in, NodoS*& fin) {
	system("cls");
	if (in != nullptr) {
		NodoS* aux;
		while (in != nullptr) {
			aux = in;
			in = in->siguiente;
			delete aux;
		}
		fin = nullptr;
		gotoxy(40, 7);cout << "Lista vaciada...";
		_getch();
	}
	else {
		gotoxy(40, 7);cout << "Lista vacia...";
		_getch();
	}
}