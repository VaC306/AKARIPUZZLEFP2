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
    if (esBombilla(tablero.datos[fila][columna]))
    {
        tablero.datos[fila][columna].tipo = SIN_BOMBILLA;
        cambiarIluminacion(tablero, fila, columna, false);
    }
    else if (tablero.datos[fila][columna].tipo != BOMBILLA && estaApagada(tablero.datos[fila][columna]) && seCumpleRestriccion(tablero, fila, columna))
    {
        ponBombilla(tablero.datos[fila][columna]);
        cambiarIluminacion(tablero, fila, columna, true);
    }  
}

void cambiarIluminacion(tTablero& tablero, int fila, int columna, bool iluminar)
{
    cambiarIluminacionDir(tablero, fila, columna, NORTE, iluminar);
    cambiarIluminacionDir(tablero, fila, columna, SUR, iluminar);
    cambiarIluminacionDir(tablero, fila, columna, ESTE, iluminar);
    cambiarIluminacionDir(tablero, fila, columna, OESTE, iluminar);
}

void cambiarIluminacionDir(tTablero& tablero, int fila, int columna, tDir dir, bool iluminar)
{
    int i = fila;
    int j = columna;
    if (dir == NORTE)
    {
        while (tablero.datos[i][columna].tipo != PARED && i > 0)
        {
            --i;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[i][columna]))
                {
                    tablero.datos[i][columna].tipo = SIN_BOMBILLA;
                    aumentaIluminacion(tablero.datos[i][columna]);
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[i][columna]))
                {
                    while (!estaApagada(tablero.datos[i][columna]))
                    {
                        reduceIluminacion(tablero.datos[i][columna]);
                    }
                }
            }
        }
    }
    else if (dir == ESTE)
    {
        while (tablero.datos[fila][j].tipo != PARED && j < 4)
        {
            ++j;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[fila][j]))
                {

                    tablero.datos[fila][j].tipo = SIN_BOMBILLA;
                    tablero.datos[fila][j].numBombillas++;
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[fila][j]))
                {
                    while (!estaApagada(tablero.datos[fila][j]))
                    {
                        reduceIluminacion(tablero.datos[fila][j]);
                    }
                }
            }
        }
    }

    else if (dir == OESTE)
    {
        while (tablero.datos[fila][j].tipo != PARED && j > 0)
        {
            --j;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[fila][j]))
                {

                    tablero.datos[fila][j].tipo = SIN_BOMBILLA;
                    tablero.datos[fila][j].numBombillas++;
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[fila][j]))
                {
                    while (!estaApagada(tablero.datos[fila][j]))
                    {
                        reduceIluminacion(tablero.datos[fila][j]);
                    }
                }
            }
        }
    }

    else if (dir == SUR)
    {
        while (tablero.datos[i][columna].tipo != PARED && i < 4)
        {
            ++i;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[i][columna]))
                {
                    tablero.datos[i][columna].tipo = SIN_BOMBILLA;
                    aumentaIluminacion(tablero.datos[i][columna]);
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[i][columna]))
                {
                    while (!estaApagada(tablero.datos[i][columna]))
                    {
                        reduceIluminacion(tablero.datos[i][columna]);
                    }
                }
            }
        }
    }
}

bool seCumpleRestriccion(const tTablero& tablero, int fila, int columna)
{
    if (esPared(tablero.datos[fila][columna]) && numBombillasVecinas(tablero, fila, columna) == tablero.datos[fila][columna].numBombillas)
        return false;
    else
        return true;
}

bool estaTerminado(const tTablero& tablero)
{
    //revisar en todas las paredes si seCumpleRestriccion();
    return false;
}