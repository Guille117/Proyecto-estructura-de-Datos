#include"Utilidades.h"
#include"Arreglos.h"
#include"PagoMensualidad.h"
#include<iostream>
#include<conio.h>
using namespace std;
int x = 0, y = 0;			//coordenadas 
int idPago = 1;				// servirá para asignarle un id a cada pago

void iniciarCola(Nodo*& inicio, Nodo*& final) {
	inicio = nullptr;
	final = nullptr;
}

int menuCola() {
	int y = 7, x = 30;
	system("cls");
	gotoxy(x-5, y);cout << "  Opciones para Pago de Mensualidad.";
	gotoxy(x, y+=3);cout << "Realizar pago. ";
	gotoxy(x, y+=1);cout << "Mostrar pagos. ";
	gotoxy(x, y+=1);cout << "Buscar pago. ";
	gotoxy(x, y+=1);cout << "Modificar pago. ";
	gotoxy(x, y+=1);cout << "Eliminar pago. ";
	gotoxy(x, y+=1);cout << "Vaciar pagos. ";
	gotoxy(x, y+=1);cout << "Atras. ";
	return navegador(x - 3, y -6, 7);
}

void iniciar() {
	int opcion = 0;
	Nodo* inicio;
	Nodo* fin;
	iniciarCola(inicio, fin);

	do {
		
		opcion = menuCola();

		switch (opcion) {
		case 1: system("cls"); push(inicio, fin, pedirDatos(false));break;
		case 2: system("cls"); mostrar(inicio);break;
		case 3: system("cls"); mostrar1Nodo(buscarRegistro(inicio)); break;
		case 4: system("cls"); modificarRegistro(inicio);break;
		case 5: system("cls"); pop(inicio, fin, false);break;
		case 6: system("cls"); vaciarRegistros(inicio, fin);break;
		case 7: system("cls"); break;
		default: system("cls"); gotoxy(10, 3);cout << " Opcion incorrecta " << endl; system("pause");
		}

	} while (opcion != 7);

}


// esta función la usaremos en dos partes distintas, servirá para recibir los datos para crear el nodo y también para pedir los datos para la 
// actualización de datos, por eso recibe un dato bool para indicar en que se usará para definir  las coordenadas

PagoMensualidad pedirDatos(bool modificar) {	
	MostrarCursor();
	if (modificar) {
		y += 4;
	}
	else {
		 y = 2;
	}
	x = 20;
	
	int aux=0;				// guardará el índice seleccionado de los items 
	PagoMensualidad p;


	p.idPago = idPago;									// ingresamos el id de pago

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
		aux += 5;														// si escoge un semestre de segundo ciclo aumentamos 5 por los meses anteriores
	}
	else {
		aux = (RecorrerArregloString2(Mes, x + 1, y + 2, 0, 5));		
		//cout << aux;
	}
	gotoxy(x, y);   cout << " Mes: " << Mes[aux-1];
	p.mes = Mes[aux-1];


	gotoxy(x, y += 1); cout << " Total: " << p.cantidad << endl << endl;
	
	idPago++;																// aumentamos id para el próximo

	return p;
}

void push(Nodo*& inicio, Nodo*& fin, PagoMensualidad pagoM) {
	Nodo* nuevoNodo = new Nodo();		// crear espacio en memoria
	nuevoNodo->pago = pagoM;			// rellenar datos;
	nuevoNodo->siguiente = nullptr;  	// es null por que siempre sera el fin de la cola

	if (inicio == nullptr) {			// preguntamos si hay elementos en la cola
		inicio = nuevoNodo;
	}
	else {
		fin->siguiente = nuevoNodo;		// decimos que ahora el fin ya no es el fin y apuntamos al nuevo nodo
	}

	fin = nuevoNodo;					// cambiamos el fin

	gotoxy(x, y + 2); cout << "Dato ingresado con exito.";_getch();
}

void mostrar(Nodo* inicio) {
	system("cls");
	x = 4, y = 9;

	if (inicio != nullptr) {
		gotoxy(x+40, y-4);cout << "Mostrando pagos de mensualidades";

		int contador = 0, contadorY = 0;

		while (inicio != nullptr) {
			gotoxy(x, y++);cout << " Id pago: " << inicio->pago.idPago;
			gotoxy(x, y++);cout << " Nombre: "<<inicio->pago.nombre;
			gotoxy(x, y++);cout << " Apellido: "<<inicio->pago.apellido;
			gotoxy(x, y++);cout << " No. de carne: "<<inicio->pago.identificador;
			gotoxy(x, y++);cout << " Facultad: "<<inicio->pago.carrera;
			gotoxy(x, y++);cout << " Semestre: "<<inicio->pago.semestre;
			gotoxy(x, y++);cout << " Mes:  "<<inicio->pago.mes;
			gotoxy(x, y++);cout << " Cantidad: " << inicio->pago.cantidad << endl << endl;
			gotoxy(x, y++);cout << " Dir. memoria: " << inicio << endl << endl;
			inicio = inicio->siguiente;

			contador++;

			if (contador < 4) {
				
					gotoxy(x, y + 1); cout << "------->    ----->    ------->";

				
				y -= 9;																// si se agregan mas o menos lines alterar y
				x += 40;
				if (contador == 3) {
					y += 11;															// si se agregan mas o menos lines alterar y
					for (int i = 0; i < 6;i++) {
						gotoxy(x-15, y++);cout << "|";
					}	
					x -= 40; y += 1;
				}
			}
			else {
				if (contador <= 6) {
					
					gotoxy(x, y + 1); cout << "<-------    <-----    <-------";
					y -= 9; x -= 40;												// si se agregan mas o menos lines alterar y
					

					if(contador == 6){
						x += 58; y += 11;										    // si se agregan mas o menos lines alterar y
						for (int i = 0; i < 6;i++) {
							gotoxy(x - 15, y++);cout << "|";
						}

						x -= 17; y += 1;
						contador = 0;
					}
											
				}
				
			}
		}
		gotoxy(36,y+15);system("pause");
	}
	else {
		gotoxy(40, 7);cout << "No hay pagos para mostrar...";
		_getch();
	}
	
}

void mostrar1Nodo(Nodo* nodo) {
	
	if (nodo != nullptr) {
		x = 10, y = 6;

		gotoxy(x, y++);cout << " Id pago: " << nodo->pago.idPago;
		gotoxy(x, y++);cout << " Nombre: " << nodo->pago.nombre;
		gotoxy(x, y++);cout << " Apellido: " << nodo->pago.apellido;
		gotoxy(x, y++);cout << " Carne: " << nodo->pago.identificador;
		gotoxy(x, y++);cout << " Facultad: " << nodo->pago.carrera;
		gotoxy(x, y++);cout << " Semestre: " << nodo->pago.semestre;
		gotoxy(x, y++);cout << " Mes: " << nodo->pago.mes;
		gotoxy(x, y++);cout << " Cantidad: " << nodo->pago.cantidad;
		gotoxy(x, y++);cout << " Direccin de memoria: " << nodo << " ";_getch();
	}
	
}

void modificarRegistro(Nodo* inicio) {

		Nodo* aux;
		PagoMensualidad pgo;

		aux = buscarRegistro(inicio);
		mostrar1Nodo(aux);
		if (aux != nullptr) {
			gotoxy(10, 16);cout << " Reingreso de datos.";
			pgo = pedirDatos(true);
			pgo.idPago = aux->pago.idPago;

			aux->pago = pgo;
			idPago--;
			cout << "			Registro modificado con exito...";
			_getch();
		}
		
		

}

Nodo* buscarRegistro(Nodo* inicio) {


	bool estado = false;
	Nodo* aux = nullptr;
	int id;

	system("cls");
	MostrarCursor();
	gotoxy(10, 2); cout << " Ingrese el numero de id del pago a buscar: ";
	cin >> id;

	while ((inicio != nullptr) && (!estado)) {
		if (id == inicio->pago.idPago) {
			aux = inicio;
			estado = true;
		}
		else {
			inicio = inicio->siguiente;
		}
	}

	if (!estado) {
		gotoxy(10, 4); cout << "No se encontro ningun pago asociado al numero de id proporcionado...";_getch();
		return nullptr;
	}
	else {
		gotoxy(10, 4); cout << "Pago encontrado.";
		return aux;
	}

	
}

void pop(Nodo*& frente, Nodo*& fin, bool vaciarCola) {
	if (frente != nullptr) {
		Nodo* aux = frente;
		system("cls");
		if (!vaciarCola) {
			gotoxy(10, 3);cout << "Datos a eliminar...";
			mostrar1Nodo(frente);
		}

		if (frente == fin) {			// si ya no hay elementos en la cola
			frente = nullptr;
			fin = nullptr;
		}
		else {
			frente = frente->siguiente;			// asignamos el nuevo elemento
		}

		delete aux;
	}
	else {
		gotoxy(10, 3);cout << "No hay pagos a eliminar...";_getch();
	}

}

void vaciarRegistros(Nodo*& inicio, Nodo*&fin) {
	if (inicio == nullptr) {
		system("cls");
		gotoxy(10, 3);cout << "No hay pago que eliminar...";_getch();
	}
	else {
		while (inicio != nullptr) {
			pop(inicio, fin, true);
		}
		system("cls");
		gotoxy(10,3);cout << "Todos los pagos fueron eliminados...";_getch();
	}
	
}








 
