#include<iostream>
//#include<unordered_set>
#include<conio.h>
#include"ListaDE.h"
#include "Utilidades.h"
#include"Arreglos.h"

using namespace std;

int a = 0,b = 0;
unordered_set<int> listaNumeros;

int menuLista() {

	b = 7, a = 30;
	system("cls");
	gotoxy(a - 5, b);cout << "  Opciones para Pago de Semestre.";
	gotoxy(a, b += 3);cout << "Realizar pago. ";
	gotoxy(a, b += 1);cout << "Mostrar pagos. ";
	gotoxy(a, b += 1);cout << "Mostrar pagos descendentemente. ";
	gotoxy(a, b += 1);cout << "Buscar pago. ";
	gotoxy(a, b += 1);cout << "Modificar pago. ";
	gotoxy(a, b += 1);cout << "Eliminar pago. ";
	gotoxy(a, b += 1);cout << "Vaciar Lista de pagos. ";
	gotoxy(a, b += 1);cout << "Atras. ";
	return navegador(a - 3, b - 7, 8);
}

void iniciarListaDE() {
	int opcion = 0;
	LDE_Nodo* inicio = nullptr;
	LDE_Nodo* fin = nullptr;

	do {
		opcion = menuLista();

		switch (opcion) {
		case 1: system("cls"); ingresar(inicio, fin); break;
		case 2: system("cls"); mostrar(inicio); break;
		case 3: system("cls"); mostrarInverso(fin); break;
		case 4: system("cls"); mostrar1Pago(buscarPagoLDE(inicio, fin)); _getch(); break;
		case 5: system("cls"); ModificarPagoLDE(inicio, fin); break;
		case 6: system("cls"); eliminarLDE(inicio, fin); break;
		case 7: system("cls"); vaciarLDE(inicio, fin); break;
		case 8: system("cls");
		}
	} while (opcion != 8);
}

PagoSemestre pedirDatosLDE(bool modificar) {
	PagoSemestre p;

	MostrarCursor();
	if (modificar) {
		b += 4;
	}
	else {
		b = 2;
		p.id = generarId(listaNumeros);							// generando un id aleatorio y asignarselo al pago
		listaNumeros.insert(p.id);								// guardamos el id generado en la lista de ids existentes
	}
	a = 20;

	int aux = 0;
	float auxTotalAPagar = 0;

	gotoxy(a, b); cout << "  Ingreso de datos para Pago de Semestre ";

	gotoxy(a += 10, b += 3); cout << " Nombre: ";
	cin >> p.nombre;
	gotoxy(a, b += 1);	 cout << " Apellido: ";
	cin >> p.apellido;
	gotoxy(a, b += 1);   cout << " No. de carne: ";
	cin >> p.carne;

	// Items seleccionables...

	gotoxy(a, b += 1);	 cout << " Facultad: ";						// primera vez que se muestra 
	aux = (RecorrerArregloString(Carrera, a + 1, b + 2) - 1);			// mostramos las posibles opciones y almacenamos la selección, ademas borramos pantalla
	gotoxy(a, b);		 cout << " Facultad: " << Carrera[aux];		// mostramos por ultima vez
	p.carrera = Carrera[aux];										// almecenamos el dato
	
	auxTotalAPagar = cantidad[aux];										// asignamos el coste de la carrera


	gotoxy(a, b += 1);   cout << " Semestre:  ";
	aux = (RecorrerArregloString(semestre, a + 1, b + 2) - 1);		// menos 1 por que el usuario observa las opciones a partir de 1
	gotoxy(a, b);		 cout << " Semestre: " << semestre[aux];
	p.semestre = semestre[aux];

	auxTotalAPagar = auxTotalAPagar + (aux * 10);							// completamos el total a pagar, cada semestre la mensualidad aumenta 10 Q
	auxTotalAPagar *= 5;													// multiplicamos la cantidad por la cantidad de meses de un semestre.

	p.sinDescuento = auxTotalAPagar;										// asignamos donde corresponde
	p.conDescuento = (auxTotalAPagar - (auxTotalAPagar * 0.07));				// aplicamos descuento y asignamos

	gotoxy(a, b += 1);   cout << " Total sin descuento:  "<<p.sinDescuento;
	gotoxy(a, b += 1);   cout << " Total con descuento:  " << p.conDescuento;

	return p;	
}

void ingresar(LDE_Nodo*& inicio, LDE_Nodo*& fin) {
	LDE_Nodo* nuevo = new LDE_Nodo();
	nuevo->pago = pedirDatosLDE(false);

	int num = nuevo->pago.id;

	if (inicio == nullptr) {                         // primer dato
		nuevo->anterior = nullptr;
		nuevo->siguiente = nullptr;
		inicio = nuevo;
		fin = nuevo;

	}
	else {

		if (num <= inicio->pago.id) {                       // dato menor que todos
			nuevo->anterior = nullptr;
			inicio->anterior = nuevo;
			nuevo->siguiente = inicio;
			inicio = nuevo;
		}
		else if (num >= fin->pago.id) {                 // dato mayor que todos
			nuevo->siguiente = nullptr;
			fin->siguiente = nuevo;
			nuevo->anterior = fin;
			fin = nuevo;
		}
		else {                                      // dato entre datos
			// si el dato que queremos ingresar es menor que la madiana nuestro corredor sera igual a inicio, sino al final
			// esto con el fin de realizar la menor cantidad de iteraciones posibles
			LDE_Nodo* corredor = (num < (fin->pago.id / 2)) ? inicio : fin;

			if (corredor == inicio) {                   // dato menor que la media, recorre de inicio a fin
				while (corredor->pago.id < num) {
					corredor = corredor->siguiente;
				}

				corredor->anterior->siguiente = nuevo;
				nuevo->anterior = corredor->anterior;
				nuevo->siguiente = corredor;
				corredor->anterior = nuevo;

			}
			else {											// dato mayor a la media, recorre de fin a inicio
				while (corredor->pago.id > num) {
					corredor = corredor->anterior;
				}

				corredor->siguiente->anterior = nuevo;
				nuevo->siguiente = corredor->siguiente;
				nuevo->anterior = corredor;
				corredor->siguiente = nuevo;

			}
		}
	}
	gotoxy(a, b + 2); cout << "Dato ingresado con exito.";_getch();
}

void mostrar(LDE_Nodo* inicio) {
	system("cls");
	a = 4, b = 9;

	if (inicio != nullptr) {
		gotoxy(a + 40, b - 4);cout << "Mostrando pagos de Semestre";
		while (inicio != nullptr) {
			gotoxy(a, b++);cout << " Id pago: " << inicio->pago.id;
			gotoxy(a, b++);cout << " Nombre: " << inicio->pago.nombre;
			gotoxy(a, b++);cout << " Apellido: " << inicio->pago.apellido;
			gotoxy(a, b++);cout << " No. de carne: " << inicio->pago.carne;
			gotoxy(a, b++);cout << " Facultad: " << inicio->pago.carrera;
			gotoxy(a, b++);cout << " Semestre: " << inicio->pago.semestre;
			gotoxy(a, b++);cout << " Total sin descuento: " << inicio->pago.sinDescuento;
			gotoxy(a, b++);cout << " Total con descuento: " << inicio->pago.conDescuento;
			gotoxy(a, b++);cout << " Dir. memoria: " << inicio;
			inicio = inicio->siguiente;
			b += 3;
		}
		gotoxy(36, b + 5);system("pause");
	}
	else {
		gotoxy(40, 7);cout << "No hay pagos para mostrar...";
		_getch();
	}
	
}

void mostrarInverso(LDE_Nodo* fin) {
	system("cls");
	a = 4, b = 9;

	if (fin != nullptr) {
		gotoxy(a + 40, b - 4);cout << "Mostrando pagos de Semestre";
		while (fin != nullptr) {
			gotoxy(a, b++);cout << " Id pago: " << fin->pago.id;
			gotoxy(a, b++);cout << " Nombre: " << fin->pago.nombre;
			gotoxy(a, b++);cout << " Apellido: " << fin->pago.apellido;
			gotoxy(a, b++);cout << " No. de carne: " << fin->pago.carne;
			gotoxy(a, b++);cout << " Facultad: " << fin->pago.carrera;
			gotoxy(a, b++);cout << " Semestre: " << fin->pago.semestre;
			gotoxy(a, b++);cout << " Total sin descuento: " << fin->pago.sinDescuento;
			gotoxy(a, b++);cout << " Total con descuento: " << fin->pago.conDescuento;
			gotoxy(a, b++);cout << " Dir. memoria: " << fin;
			fin = fin->anterior;
			b += 3;
		}
		gotoxy(36, b + 5);system("pause");
	}
	else {
		gotoxy(40, 7);cout << "No hay pagos para mostrar...";
		_getch();
	}

}

LDE_Nodo* buscarPagoLDE(LDE_Nodo* inicio, LDE_Nodo* fin) {
	system("cls");
	LDE_Nodo* aux = nullptr;

	if (inicio != nullptr) {
		int dato;
		gotoxy(5,2);cout << " Ingrese dato a buscar: ";
		cin >> dato;


		if (dato == inicio->pago.id) {
			aux = inicio;
		}
		else if (dato == fin->pago.id) {
			aux = fin;
		}
		else {
			bool encontrado = false;
			LDE_Nodo* corredor = nullptr;
			if ((fin->pago.id / 2) < dato) {
				corredor = inicio;
				while (!encontrado && corredor != nullptr) {
					if (dato == corredor->pago.id) {
						aux = corredor;
					}
					else {
						corredor = corredor->siguiente;
					}
				}

			}
			else {
				corredor = fin;
				while (!encontrado && corredor != nullptr) {
					if (dato == corredor->pago.id) {
						encontrado = true;
						aux = corredor;
					}
					else {
						corredor = corredor->anterior;
					}
				}

			}
		}
		
	}
	return aux;
}

void mostrar1Pago(LDE_Nodo* nodo) {
	a = 4, b = 9;

	if (nodo != nullptr) {
		gotoxy(a + 40, b - 4);cout << "Pago de semestre encontrado";
		gotoxy(a, b++);cout << " Id pago: " << nodo->pago.id;
		gotoxy(a, b++);cout << " Nombre: " << nodo->pago.nombre;
		gotoxy(a, b++);cout << " Apellido: " << nodo->pago.apellido;
		gotoxy(a, b++);cout << " No. de carne: " << nodo->pago.carne;
		gotoxy(a, b++);cout << " Facultad: " << nodo->pago.carrera;
		gotoxy(a, b++);cout << " Semestre: " << nodo->pago.semestre;
		gotoxy(a, b++);cout << " Total sin descuento: " << nodo->pago.sinDescuento;
		gotoxy(a, b++);cout << " Total con descuento: " << nodo->pago.conDescuento;
		gotoxy(a, b++);cout << " Dir. memoria: " << nodo;


		//gotoxy(36, b + 1);_getch();
	}
	else {
		gotoxy(40, 7);cout << "Pago no encotrado o lista vacia...";
		_getch();
	}
}

void ModificarPagoLDE(LDE_Nodo* inicio, LDE_Nodo* fin) {

	LDE_Nodo* aux = buscarPagoLDE(inicio, fin);
	PagoSemestre nu;
	if (inicio != nullptr) {
		if (aux != nullptr) {
			mostrar1Pago(aux); _getch();
			gotoxy(10, 19);cout << " Reingreso de datos.";
			nu = pedirDatosLDE(true);
			nu.id = aux->pago.id;
			aux->pago = nu;
			cout << "\n\n			Registro modificado con exito...";
			_getch();
		}
	}
	else {
		gotoxy(40, 7);cout << "Lista vacia...";_getch();
	}
}

void eliminarLDE(LDE_Nodo*& inicio, LDE_Nodo*& fin) {
	if (inicio != nullptr) {
		
		LDE_Nodo* aEliminar = buscarPagoLDE(inicio, fin);

		if (aEliminar != nullptr) {
			if (aEliminar == inicio) {                         // el dato se encuentra en el inicio
				if (inicio->siguiente != nullptr) {
					inicio = inicio->siguiente;
					inicio->anterior = nullptr;
				}
				else {
					inicio = nullptr;
					fin = nullptr;
				}

				
			}
			else if (aEliminar == fin) {                         // el dato se encuentra en el final
				fin = fin->anterior;
				fin->siguiente = nullptr;
			}
			else {
				aEliminar->anterior->siguiente = aEliminar->siguiente;
				aEliminar->siguiente->anterior = aEliminar->anterior;
			}

			mostrar1Pago(aEliminar);
			delete aEliminar;
			cout << "\n\n			 Pago eliminado con exito...";_getch();
		}
		else {
			cout << "\n\n		 Dato no encontrado...\n";
			_getch();
		}
	}
	else {
		cout << "\n\n		  La lista esta vacia...\n";
		_getch();
	}
	
}

void vaciarLDE(LDE_Nodo*& inicio, LDE_Nodo*& fin) {
	if (inicio != nullptr) {
		LDE_Nodo* aux = nullptr;
		while (inicio != nullptr) {
			aux = inicio;
			inicio = inicio->siguiente;
			delete aux;
		}
		fin = nullptr;
	}

	gotoxy(40, 7);cout << "Lista vaciada...";
	_getch();
	
}