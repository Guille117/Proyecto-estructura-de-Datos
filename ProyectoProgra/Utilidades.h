#pragma once
#ifndef UTILIDADES_H
#define UTILIDADES_H

void gotoxy(int x, int y);
void borrarLineas(int xInicio, int yInicio, int xFinal, int yFinal);
bool esPar(int num);
int navegador(int a, int b, int tamaño);
void MostrarCursor();
void OcultarCursor();

#endif

