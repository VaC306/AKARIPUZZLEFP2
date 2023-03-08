#include "celda.h"
#include "colors.h"
#include <fstream>

#ifndef tablero_h
#define tablero_h

const int HUECOS = 2;

const int MAX_FILS = 10;
const int MAX_COLS = 10;

typedef tCelda tTableroDatos[MAX_FILS][MAX_COLS];

struct tTablero {
	int nFils, nCols;
	tTableroDatos datos;
};

int numFilas(const tTablero& tab);

int numCols(const tTablero& tab);

tCelda celdaEnPos(const tTablero& tablero, int fila, int columna);

void ponCeldaEnPos(tTablero& tablero, int fila, int columna, const tCelda& c);

void mostrar(const tTablero& tab);

void leer(ifstream& archivo, tTablero& tab);

#endif