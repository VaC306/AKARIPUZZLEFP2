#pragma once
#include "celda.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


char celdaToChar(const tCelda& celda)
{
    if (celda.tipo == BOMBILLA)
        return '*';
    else if (celda.tipo == PARED)
        return celda.numBombillas;
}

bool esPared(const tCelda& c)
{
    return c.tipo == PARED;
}

bool esBombilla(const tCelda& c)
{
    return c.tipo == BOMBILLA;
}

bool estaApagada(const tCelda& c)
{
    return c.tipo == SIN_BOMBILLA && c.numBombillas == 0;
}

bool estaIluminada(const tCelda& c)
{
    return c.tipo == SIN_BOMBILLA && c.numBombillas > 0;
}

void aumentaIluminacion(tCelda& c)
{
    c.numBombillas++;
}

void ponBombilla(tCelda& c)
{
    c.tipo = BOMBILLA;
}

void reduceIluminacion(tCelda& c)
{
    c.numBombillas--;
    if (c.numBombillas == 0)
        c.tipo = SIN_BOMBILLA;
}


//tCelda charToCelda(char c)
//{
//    preguntar si hay que poner un atributo pricado llamado celda
//    if (c == 'X')
//        return ;
//}