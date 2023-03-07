#include "tablero.h"
#include <iostream>
#include <fstream>
#ifndef juego_h
#define juego_h

typedef enum tDir { NORTE, SUR, ESTE, OESTE };


void cargaTableroFichero(ifstream& archivo, tTablero& tab);

void ejecutarPos(tTablero& tablero, int fila, int columna);

void cambiarIluminacion(tTablero& tablero, int fila, int columna, bool iluminar);

void cambiarIluminacionDir(tTablero& tablero, int fila, int columna, tDir dir, bool iluminar);

bool estaTerminado(const tTablero& tablero);

bool seCumpleRestriccion(const tTablero& tablero, int fila, int columna);

int numBombillasVecinas(const tTablero& tablero, int fila, int columna);

void resetearTablero(tTablero& tablero);

bool abandono(int fila, int columna);

#endif