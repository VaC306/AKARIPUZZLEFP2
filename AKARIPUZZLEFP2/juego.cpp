#include "juego.h"

int numBombillasVecinas(const tTablero& tablero, int fila, int columna)
{
    int num = 0;

    if (tablero.datos[fila--][columna].tipo == BOMBILLA) num++; //arriba centro
    else if (tablero.datos[fila][columna--].tipo == BOMBILLA) num++; //izquierda centro
    else if (tablero.datos[fila][columna++].tipo == BOMBILLA) num++; //derecha centro
    else if (tablero.datos[fila++][columna].tipo == BOMBILLA) num++; //abajo centro
    else if (tablero.datos[fila++][columna++].tipo == BOMBILLA) num++; //abajo derecha
    else if (tablero.datos[fila--][columna--].tipo == BOMBILLA) num++; //izquierda arriba
    else if (tablero.datos[fila++][columna--].tipo == BOMBILLA) num++; //izquierda abajo
    else if (tablero.datos[fila--][columna++].tipo == BOMBILLA) num++; //izquierda centro

    return num;
}

bool abandono(int fila, int columna)
{
    if (fila = -1 && columna == 0)
        return true;
    else
        return false;
}

void resetearTablero(tTablero& tablero)
{
    for (int i = 0; i < tablero.nFils; ++i)
    {
        for (int j = 0; j < tablero.nCols; ++j)
        {
            if (tablero.datos[i][j].tipo == BOMBILLA)
            {
                tablero.datos[i][j].tipo = SIN_BOMBILLA;
                tablero.datos[i][j].numBombillas = 0;
            }
        }
    }
}

void ejecutarPos(tTablero& tablero, int fila, int columna)
{
    int i = fila;
    int j = columna;
    if (tablero.datos[fila][columna].tipo == BOMBILLA)
    {
        tablero.datos[fila][columna].tipo = SIN_BOMBILLA;
    }

    else if (tablero.datos[fila][columna].tipo != BOMBILLA)
    {
        tablero.datos[fila][columna].tipo = BOMBILLA;
        while (tablero.datos[i][columna].tipo != PARED && i > 0)
        {
            --i;
            tablero.datos[i][columna].tipo = SIN_BOMBILLA;
            tablero.datos[i][columna].numBombillas++;
        }
        int i = fila;
        while (tablero.datos[i][columna].tipo != PARED && i < 4)
        {
            
            ++i;
            tablero.datos[i][columna].tipo = SIN_BOMBILLA;
            tablero.datos[i][columna].numBombillas++;
        }
        while (tablero.datos[fila][j].tipo != PARED && j < 4)
        {

            ++j;
            tablero.datos[fila][j].tipo = SIN_BOMBILLA;
            tablero.datos[fila][j].numBombillas++;
        }
        int j = columna;
        while (tablero.datos[fila][j].tipo != PARED && j > 0)
        {

            --j;
            tablero.datos[fila][j].tipo = SIN_BOMBILLA;
            tablero.datos[fila][j].numBombillas++;
        }
    }  
}