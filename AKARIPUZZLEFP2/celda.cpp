#pragma once
#include "celda.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int charToInt(char in)
{
    if (in == '0')
        return 0;
    else if (in == '1')
        return 1;
    else if (in == '2')
        return 2;
    else if (in == '3')
        return 3;
    else if (in == '4')
        return 4;
    else
        return -1;
}

char intToChar(int in)
{
    if (in == 0)
        return '0';
    else if (in == 1)
        return '1';
    else if (in == 2)
        return '2';
    else if (in == 3)
        return '3';
    else if (in == 4)
        return '4';
    else
        return -1;
}

char celdaToChar(const tCelda& celda)
{
    if (celda.tipo == BOMBILLA)
        return '*';
    else if (celda.tipo == PARED && celda.numBombillas > 0)
        return intToChar(celda.numBombillas);
    else
        return ' ';
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


tCelda charToCelda(char c)
{   
    tCelda celda;
    if (c == '.')
    {
        celda.tipo = SIN_BOMBILLA;
        celda.numBombillas = 0;
    }
    else if (c == 'X')
    {
        celda.tipo = PARED;
        celda.numBombillas = 0;
    }
    else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4')
    {
        celda.tipo = PARED;
        celda.numBombillas = charToInt(c);
    }
    return celda;
}

bool esParedRestringida(const tCelda& c)
{
    if (c.tipo == PARED && c.numBombillas > 0)
        return true;
    else 
        return false;
}

int numParedRestringida(const tCelda& c)
{
    return c.numBombillas;
}