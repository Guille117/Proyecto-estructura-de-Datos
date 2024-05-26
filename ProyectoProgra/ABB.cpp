#include<conio.h>
#include "ABB.h"
#include "Utilidades.h"
#include"Arreglos.h"

unordered_set<int> Lista;
int xa = 0, ya = 0;


int menuA() {
	system("cls");
	xa = 40; ya = 3;

	gotoxy(xa + 5, ya);cout << "Menu de opciones.";
	
	gotoxy(xa, ya+=3);cout << "Ingresar registro.";
	gotoxy(xa, ya+=1);cout << "Mostrar arbol.";
	gotoxy(xa, ya+= 1);cout << "Mostrar alquileres in orden.";
	gotoxy(xa, ya+= 1);cout << "Mostrar alquileres pre orden.";
	gotoxy(xa, ya+= 1);cout << "Mostrar alquileres post orden.";
	gotoxy(xa, ya += 1);cout << "Buscar Registro de alquiler.";
	gotoxy(xa, ya += 1);cout << "Eliminar registro de alquiler.";
	gotoxy(xa, ya+= 1);cout << "Atras.";
	return navegador(xa - 3, ya - 7, 8);
}

void iniciarArbol() {
	NodoToga* raiz = nullptr;
	int op = 0;

	do {
		op = menuA();

		switch (op) {
		case 1: AUXguardarPrestamo(raiz);break;
		case 2: break;
		case 3: AUXInOrden(raiz);break;
		case 4: AUXPreOrden(raiz); break; 
		case 5: AUXPostOrden(raiz); break;
		case 6: AUXBuscarAlqui(raiz);break;
		case 7: AuxEliminarT(raiz);break;
		case 8: system("cls");break;
		}
	} while (op != 8);
}

PrestamoToga pedirDatos() {
	system("cls");
	PrestamoToga p1;
	xa = 35; ya = 6;
	int aux;

	gotoxy(xa+5, ya-3);cout << "Ingreso de datos para alquiler de toga";

	//p1.id = generarId(Lista);
	gotoxy(xa, ya++);cout << "Id: ";
	cin >> p1.id;
	gotoxy(xa, ya++);cout << "Nombre: ";
	cin >> p1.nombre;
	gotoxy(xa, ya++);cout << "Apellido: ";
	cin >> p1.apellido;
	gotoxy(xa, ya++);cout << "Carnet: ";
	cin >> p1.carnet;

	gotoxy(xa, ya++);	 cout << "Facultad: ";						// primera vez que se muestra 
	aux = (RecorrerArregloString(Carrera, xa + 1, ya + 2) - 1);			// mostramos las posibles opciones y almacenamos la selección, ademas borramos pantalla
	gotoxy(xa, ya-1);		 cout << "Facultad: " << Carrera[aux];		// mostramos por ultima vez
	p1.carrera = Carrera[aux];										// almecenamos el dato
	
	p1.total = 150;
	gotoxy(xa, ya++);cout << "Total: " << p1.total<<endl<<endl;
	
	return p1;
}

NodoToga* crearNodoT() {
	NodoToga* nuevo = new NodoToga();
	nuevo->pres = pedirDatos();
	nuevo->padre = nullptr;
	nuevo->derecha = nullptr;
	nuevo->izquierda = nullptr;
	return nuevo;
}

void guardarPrestamo(NodoToga*& raiz, NodoToga* nuevo, NodoToga* padre) {
	if (raiz == nullptr) {
		nuevo->padre = padre;
		raiz = nuevo;

	}
	else {
		if (nuevo->pres.id < raiz->pres.id) {
			guardarPrestamo(raiz->izquierda, nuevo, raiz);
		}
		else {
			guardarPrestamo(raiz->derecha, nuevo, raiz);
		}
	}
}
void AUXguardarPrestamo(NodoToga*& raiz) {
	NodoToga* p = nullptr;
	p = crearNodoT();

	guardarPrestamo(raiz, p, nullptr);

	cout << "\n\n			Registro guardado con exito.\n";_getch();
}

void mostrar1PrestamoT(NodoToga* nodo) {
	cout << "\n\n\n	  Id: " << nodo->pres.id;
	cout << "\n	  Nombre: " << nodo->pres.nombre;
	cout << "\n	  Apellido: " << nodo->pres.apellido;
	cout << "\n	  Carnet: " << nodo->pres.carnet;
	cout << "\n	  Carrera: " << nodo->pres.carrera;
	cout << "\n	  Total: " << nodo->pres.total;
	cout << "\n	  Dir. memoria: " << nodo;
}

void RecorrerInOrden(NodoToga* raiz) {
	if (raiz == nullptr) {
		return;
	}
	else {
		RecorrerInOrden(raiz->izquierda);	

		mostrar1PrestamoT(raiz);
		
		RecorrerInOrden(raiz->derecha);		// recorrer lado derecho aplicando recursividad
	}
}
void AUXInOrden(NodoToga* raiz) {
	system("cls");
	xa = 25, ya = 6;

	if (raiz == nullptr) {
		gotoxy(40, 7);cout << "No hay registros para mostrar\n\n";
		_getch();
	}
	else {
		gotoxy(xa + 14, ya - 3);cout << "Registro de Alquileres de toga (In orden)\n";
		RecorrerInOrden(raiz);
		
	}
	cout << "\n\n";_getch();
}

void RecorrerPreOrden(NodoToga* raiz) {
	if (raiz == nullptr) {		// si el arbol esta vacio
		return;
	}
	else {		
		mostrar1PrestamoT(raiz);
		RecorrerPreOrden(raiz->izquierda);		// aplicar recusividad pasando primero por el lado izquierdo
		RecorrerPreOrden(raiz->derecha);		// aplicar recursividad pasando ahora por el lado derecho
	}
}
void AUXPreOrden(NodoToga* raiz) {
	system("cls");
	xa = 25, ya = 6;

	if (raiz == nullptr) {
		gotoxy(40, 7);cout << "No hay registros para mostrar\n\n";
		_getch();
	}
	else {
		gotoxy(xa + 14, ya - 3);cout << "Registro de Alquileres de toga (Pre orden)\n";
		RecorrerPreOrden(raiz);

	}
	cout << "\n\n";_getch();
}

void RecorrerPostOrden(NodoToga* raiz) {
	if (raiz == nullptr) {		// si el árbol esta vacío
		return;		// retorna
	}
	else {
		RecorrerPostOrden(raiz->izquierda);		// recorrer lado izquierdo aplicando recursividad
		RecorrerPostOrden(raiz->derecha);		// recorrer lado derecho aplicando recursividad
		mostrar1PrestamoT(raiz);
	}
}
void AUXPostOrden(NodoToga* raiz) {
	system("cls");
	xa = 25, ya = 6;

	if (raiz == nullptr) {
		gotoxy(40, 7);cout << "No hay registros para mostrar\n\n";
		_getch();
	}
	else {
		gotoxy(xa + 14, ya - 3);cout << "Registro de Alquileres de toga (Post orden)\n";
		RecorrerPostOrden(raiz);

	}
	cout << "\n\n";_getch();
}

NodoToga* BuscarAlqui(NodoToga* raiz, int dato) {
	if (raiz == nullptr) {
		return nullptr;
	}
	else {
		if (dato == raiz->pres.id) {
			return raiz;
		}
		else {
			if (dato < raiz->pres.id) {
				BuscarAlqui(raiz->izquierda, dato);
			}
			else {
				BuscarAlqui(raiz->derecha, dato);
			}
		}
	}
}
NodoToga* AUXBuscarAlqui(NodoToga* raiz) {
	system("cls");
	NodoToga* aux = nullptr;
	if (raiz != nullptr) {
		int id;
		cout << "\n\n			Ingrese id del alquiler a buscar: ";
		cin >> id;

		aux = BuscarAlqui(raiz, id);

		if (aux != nullptr) {
			cout << "\n\n		Registro encontrado... ";
			mostrar1PrestamoT(aux);
			_getch();
		}
		else {
			cout << "\n\n			No existe registro de este ID de alquiler... ";_getch();
		}

		
	}
	else {
		cout << "\n\n			No hay registros de alquileres...";_getch();
	}
	return aux;
}

void eliminarT(NodoToga*& raiz, NodoToga*& eliminar) {
	NodoToga* aux = nullptr;

	// caso 1 Nodo hoja.
	if (eliminar->izquierda == nullptr && eliminar->derecha == nullptr) {
		ELIMhoja(raiz, eliminar);
		
	}
	else {
		// caso 2 Nodo con un hijo.
		if (eliminar->izquierda == nullptr || eliminar->derecha == nullptr) {
			ELIMnodo1hijo(raiz, eliminar);
		}	// caso 3 nodo con dos hijos
		else {
			ELIMnodo2hijos(raiz, eliminar);
		}
	}

	delete eliminar;
}
void AuxEliminarT(NodoToga*& raiz) {
	system("cls");
	if (raiz != nullptr) {
		int id;
		cout << "\n\n		Ingrese ID de registro a elimiar: ";
		cin >> id;
		
		NodoToga* aEliminar = BuscarAlqui(raiz, id);

		if (aEliminar != nullptr) {
			//system("cls");
			cout << "\n	    Registro a eliminar.";
			mostrar1PrestamoT(aEliminar);
			eliminarT(raiz, aEliminar);
			cout << "\n\n	Registro eliminado con exito.";_getch();
		}
		else {
			cout << "\n\n			No existe registro de este ID de alquiler...";_getch();
		}
	}
	else {
		cout << "\n\n			No hay registros para eliminar...";_getch();
	}
}

void ELIMhoja(NodoToga*& raiz, NodoToga*& eliminar) {
	if (eliminar->padre == nullptr) {		// si es el nodo raiz
		raiz = nullptr;
	}
	else {
		int idPadre = eliminar->padre->pres.id;
		int idEliminar = eliminar->pres.id;
		
		// determinarmos de que lado esta el nodo.
		idEliminar < idPadre ? eliminar->padre->izquierda = nullptr : eliminar->padre->derecha = nullptr;
	}
}
void ELIMnodo1hijo(NodoToga*& raiz, NodoToga*& eliminar) {

	if (eliminar->padre == nullptr) {		// si eliminamos la raiz
		// determinamos en lado tiene hijo y lo igualamos a la raiz
		eliminar->izquierda != nullptr ? raiz = eliminar->izquierda : raiz = eliminar->derecha;

		raiz->padre = nullptr;		// anulamos la relación que tiene con su padre
	}
	else if (eliminar->pres.id < eliminar->padre->pres.id) { // determinar de que lado esta el nodo a eliminar con respecto a su padre
		if (eliminar->izquierda != nullptr) {
			eliminar->padre->izquierda = eliminar->izquierda;
			eliminar->izquierda->padre = eliminar->padre;
		}
		else {
			eliminar->padre->izquierda = eliminar->derecha;
			eliminar->derecha->padre = eliminar->padre;
		}
	}
	else {
		if (eliminar->izquierda != nullptr) {
			eliminar->padre->derecha = eliminar->izquierda;
			eliminar->izquierda->padre = eliminar->padre;
		}
		else {
			eliminar->padre->derecha = eliminar->derecha;
			eliminar->derecha->padre = eliminar->padre;
		}
	}
}
void ELIMnodo2hijos(NodoToga*& raiz, NodoToga*& eliminar) {
	NodoToga* sucesor = HallarHeredero(eliminar->derecha);

	if (eliminar->padre == nullptr && (sucesor->izquierda == nullptr && sucesor->derecha == nullptr)) {		// si eliminamos la raiz y el sucesor es un nodo hoja
		
		raiz = sucesor;											// cambiamos la raiz del arbol
		sucesor->padre = nullptr;									// anulamos el puntero padre de la nueva raiz
		sucesor->izquierda = eliminar->izquierda;					//agregamos el nodo izquierdo
		eliminar->izquierda->padre = sucesor;						// el nodo izquierdo conoce a su padre
		if (eliminar->derecha != sucesor) {
			sucesor->derecha = eliminar->derecha;						
			eliminar->derecha->padre = sucesor;
		}
		else {
			sucesor->derecha = nullptr;
		}
		
	}
	else {
		// si el sucesor no es un nodo hoja no importa si eliminamos a la raiz o no.
		NodoToga* aux = eliminar;
		eliminar->pres = sucesor->pres;			// hacemos un cambio de datos
		sucesor->pres = aux->pres;				// hacemos un cambio de datos
		eliminar = nullptr;			// lo igualamos a null para no lo elimine en la función general
		eliminarT(raiz, sucesor);				// lamamos a la función eliminar
	}
	
}


NodoToga* HallarHeredero(NodoToga* arbol) {
	if (arbol == NULL) {		// si el árbol esta vacío
		return NULL;		// retornar nulo
	}
	else if (arbol->izquierda) {		//si el arbol tiene hijo izquierdo
		return HallarHeredero(arbol->izquierda);		// volver a llamar a la función aplicando recursividad
	}
	else {		// si ya no tiene hijo izquierdo
		return arbol;		// retornar valor actual
	}
}

void MostrarEnArbol(int nodo, int nivel, NodoToga* raiz) {
	if (raiz == nullptr) {

		return;
	}
	else {
		MostrarEnArbol(nodo, nivel++, raiz->izquierda);

		mostrar1PrestamoT(raiz);

		MostrarEnArbol(nodo++, nivel, raiz->derecha);		// recorrer lado derecho aplicando recursividad
	}
}



void mostrarPrestamos() {
	int x = 74;

	gotoxy(x, 2);cout << "************";
	gotoxy(x, 3);cout << "|    " << 100 << "   |";
	gotoxy(x, 4); cout << "|Guillermo |";
	gotoxy(x, 5);cout << "|Bixcul    |";
	gotoxy(x, 6);cout << "************";


	for (int i = 73; i > 40;i--) {

		gotoxy(i,4);cout << "_";
	}
	for (int i = 5; i < 10;i++) {

		gotoxy(41, i);cout << "|";
	}
	for (int i = 86; i < 117;i++) {

		gotoxy(i, 4);cout << "_";
	}
	for (int i = 5; i < 10;i++) {

		gotoxy(116, i);cout << "|";
	}
	//-----------------------------------------------------

	x = 35;
	for (int i = 0; i < 2; i++) {

		gotoxy(x, 10);cout << "************";
		gotoxy(x, 11);cout << "|    " << 100 << "   |";
		gotoxy(x, 12); cout << "|Guillermo |";
		gotoxy(x, 13);cout << "|Bixcul    |";
		gotoxy(x, 14);cout << "************";
		x += 75;
	}
	for (int i = 23; i < 34;i++) {

		gotoxy(i, 12);cout << "_";
	}
	for (int i = 13; i < 19;i++) {

		gotoxy(21, i);cout << "|";
	}
	for (int i = 47; i < 58;i++) {

		gotoxy(i, 12);cout << "_";
	}
	for (int i = 13; i < 19;i++) {

		gotoxy(57, i);cout << "|";
	}

	//-------------------------------------------------------------------
	x = 15;
	for (int i = 0; i < 4; i++) {

		gotoxy(x, 19);cout << "************";
		gotoxy(x, 20);cout << "|    " << 100 << "   |";
		gotoxy(x, 21); cout << "|Guillermo |";
		gotoxy(x, 22);cout << "|Bixcul    |";
		gotoxy(x, 23);cout << "************";
		x += 39;
	}

	for (int i = 9; i < 15;i++) {

		gotoxy(i, 21);cout << "_";
	}
	for (int i = 22; i < 26;i++) {

		gotoxy(9, i);cout << "|";
	}
	for (int i = 27; i < 33;i++) {

		gotoxy(i, 21);cout << "_";
	}
	for (int i = 22; i < 26;i++) {

		gotoxy(32, i);cout << "|";
	}
	//------------------------------------------------------------------------------

	x = 4;
	for (int i = 0; i < 8; i++) {
		gotoxy(x, 26);cout << "************";
		gotoxy(x, 27);cout << "|    " << 7 << "     |";
		gotoxy(x, 28); cout << "|Guillermo |";
		gotoxy(x, 29);cout << "|Bixcul    |";
		gotoxy(x, 30);cout << "************";
		x += 20;
	}

	for (int i = 31; i < 34;i++) {

		gotoxy(10, i);cout << "|";
	}

	for (int i = 31; i < 42;i++) {

		gotoxy(14, i);cout << "|";
	}


	x = 1;
	for (int i = 0; i < 8; i++) {

		gotoxy(x, 34);cout << "************";
		gotoxy(x, 35);cout << "|    " << 100 << "   |";
		gotoxy(x, 36); cout << "|Guillermo |";
		gotoxy(x, 37);cout << "|Bixcul    |";
		gotoxy(x, 38);cout << "************";
		x += 20;
	}
	

	x = 8;
	for (int i = 0; i < 8; i++) {

		gotoxy(x, 42);cout << "************";
		gotoxy(x, 43);cout << "|    " << 100 << "   |";
		gotoxy(x, 44); cout << "|Guillermo |";
		gotoxy(x, 45);cout << "|Bixcul    |";
		gotoxy(x, 46);cout << "************";
		x += 20;
	}
	

}




/*
void ayuda1(NodoToga*& raiz, int cantidad) {

	NodoToga* nuevo = crearNodoT();
	for (int i = 0; i < cantidad; i++) {
		guardarPrestamo(raiz, nuevo);
	}
}*/

