#pragma once
#include <iostream>
using namespace std;


#ifndef celda_h
#define celda_h

enum tTipo { PARED, BOMBILLA, SIN_BOMBILLA };

struct tCelda {
	tTipo tipo;
	int numBombillas;
};

char celdaToChar(const tCelda& celda);

tCelda charToCelda(char c);

bool esPared(const tCelda& c);

bool esParedRestringida(const tCelda& c);

int numParedRestringida(const tCelda& c);

bool esBombilla(const tCelda& c);

bool estaApagada(const tCelda& c);

bool estaIluminada(const tCelda& c);

void reduceIluminacion(tCelda& c);

void aumentaIluminacion(tCelda& c);

void ponBombilla(tCelda& c);

#endif