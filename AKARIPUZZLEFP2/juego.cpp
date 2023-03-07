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
