#include "juego.h"

int numBombillasVecinas(const tTablero& tablero, int fila, int columna)
{
    int num = 0;

    for (int i = fila - 1; i <= fila + 1; i++) {
        for (int j = columna - 1; j <= columna + 1; j++) {
            if (i >= 0 && i < 5 && j >= 0 && j < 5) { // asegurarse de no salirse de la matriz
                if (i == fila && j == columna) {
                    continue; // saltar el elemento de inter�s
                }
                if (esBombilla(tablero.datos[i][j]))
                    num++;
            }
        }
    }

    return num;
}

bool abandono(int fila, int columna)
{
    if (fila == -1 && columna == 0)
        return true;
    else
        return false;
}

void resetearTablero(tTablero& tablero)
{
    for (int i = 0; i < numFilas(tablero); ++i)
    {
        for (int j = 0; j < numCols(tablero); ++j)
        {
            if (!esPared(tablero.datos[i][j]))
            {
                tablero.datos[i][j].tipo = SIN_BOMBILLA;
                tablero.datos[i][j].numBombillas = 0;
            }
        }
    }
    cout << "\n" << RED << "se ha reseteado el tablero \n" << RESET;
}

void ejecutarPos(tTablero& tablero, int fila, int columna)
{
    int i = fila;
    int j = columna;

    if (fila == -1 && columna == -1)
        resetearTablero(tablero);
    else
        if (i <= tablero.nFils && j <= tablero.nCols)
        {
            if (esBombilla(celdaEnPos(tablero, fila, columna)))
            {
                tablero.datos[fila][columna].tipo = SIN_BOMBILLA;
                cambiarIluminacion(tablero, fila, columna, false);
            }
            else if (!esBombilla(celdaEnPos(tablero, fila, columna)) && estaApagada(celdaEnPos(tablero, fila, columna)))
            {
                ponBombilla(tablero.datos[fila][columna]);
                cambiarIluminacion(tablero, fila, columna, true);
            }
        }
        else
            cout << "\n" << RED << "se ha introducido una posicion incorrecta vuelva a intentarlo" << RESET <<"\n"; //seria mejor evisar las posiciones validas en el main
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
        while (!esPared(celdaEnPos(tablero, i, columna)) && i > 0)
        {
            --i;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[i][columna]))
                {
                    tablero.datos[i][columna].tipo = SIN_BOMBILLA;
                    aumentaIluminacion(tablero.datos[i][columna]);
                }
                else if (estaIluminada(tablero.datos[i][columna]))
                {
                    aumentaIluminacion(tablero.datos[i][columna]);
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[i][columna]))
                {
                    reduceIluminacion(tablero.datos[i][columna]);
                }
            }
        }
    }

    else if (dir == ESTE)
    {
        while (!esPared(celdaEnPos(tablero, fila, j)) && j < numFilas(tablero) - 1)
        {
            ++j;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[fila][j]))
                {

                    tablero.datos[fila][j].tipo = SIN_BOMBILLA;
                    aumentaIluminacion(tablero.datos[fila][j]);
                }
                else if (estaIluminada(tablero.datos[fila][j]))
                {
                    aumentaIluminacion(tablero.datos[fila][j]);
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[fila][j]))
                {
                    reduceIluminacion(tablero.datos[fila][j]);
                }
            }
        }
    }

    else if (dir == OESTE)
    {
        while (!esPared(celdaEnPos(tablero, fila, j)) && j > 0)
        {
            --j;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[fila][j]))
                {

                    tablero.datos[fila][j].tipo = SIN_BOMBILLA;
                    aumentaIluminacion(tablero.datos[fila][j]);
                }
                else if (estaIluminada(tablero.datos[fila][j]))
                {
                    aumentaIluminacion(tablero.datos[fila][j]);
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[fila][j]))
                {
                    reduceIluminacion(tablero.datos[fila][j]);
                }
            }
        }
    }


    else if (dir == SUR)
    {
        while (!esPared(celdaEnPos(tablero, i, columna)) && i < numFilas(tablero) - 1)
        {
            ++i;
            if (iluminar)
            {
                if (estaApagada(tablero.datos[i][columna]))
                {
                    tablero.datos[i][columna].tipo = SIN_BOMBILLA;
                    aumentaIluminacion(tablero.datos[i][columna]);
                }
                else if (estaIluminada(tablero.datos[i][columna]))
                {
                    aumentaIluminacion(tablero.datos[i][columna]);
                }
            }
            else
            {
                if (estaIluminada(tablero.datos[i][columna]))
                {
                    reduceIluminacion(tablero.datos[i][columna]);
                }
            }
        }
    }
}

bool seCumpleRestriccion(const tTablero& tablero, int fila, int columna)
{
    if (esParedRestringida(tablero.datos[fila][columna]) && (numBombillasVecinas(tablero, fila, columna) == numParedRestringida(tablero.datos[fila][columna])))
        return true;
    else
        return false;
}

bool estaTerminado(const tTablero& tablero)
{
    bool terminado = true;

    for (int i = 0; i < numFilas(tablero); ++i)
    {
        for (int j = 0; j < numCols(tablero); ++j)
        {
            if (esPared(tablero.datos[i][j]))
            {
                if (esParedRestringida(tablero.datos[i][j]))
                {
                    if (!seCumpleRestriccion(tablero, i, j))
                    {
                        terminado = false;
                    }
                }
            }
            else
            {
                if (estaApagada(tablero.datos[i][j]))
                    terminado = false;
            }
        }
    }
    return terminado;
}

void cargaTableroFichero(ifstream& archivo, tTablero& tab)
{
    char in;
    archivo >> tab.nFils;
    archivo >> tab.nCols;

    for (int i = 0; i < numFilas(tab); ++i)
    {
        for (int j = 0; j < numCols(tab); ++j)
        {
            archivo >> in;
            tab.datos[i][j] = charToCelda(in);
        }
    }
}