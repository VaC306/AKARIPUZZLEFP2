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
    for (int i = 0; i < tablero.nFils; ++i)
    {
        for (int j = 0; j < tablero.nCols; ++j)
        {
            if (!esPared(tablero.datos[i][j]))
            {
                tablero.datos[i][j].tipo = SIN_BOMBILLA;
                tablero.datos[i][j].numBombillas = 0;
            }
        }
    }
    cout << "se ha reseteado el tablero \n";
}

void ejecutarPos(tTablero& tablero, int fila, int columna)
{
    int i = fila;
    int j = columna;
    if (i <= tablero.nFils && j <= tablero.nCols)
    {
        if (esBombilla(tablero.datos[fila][columna]))
        {
            tablero.datos[fila][columna].tipo = SIN_BOMBILLA;
            cambiarIluminacion(tablero, fila, columna, false);
        }
        else if (tablero.datos[fila][columna].tipo != BOMBILLA && estaApagada(tablero.datos[fila][columna]))
        {
            ponBombilla(tablero.datos[fila][columna]);
            cambiarIluminacion(tablero, fila, columna, true);
        }
    }
    else
        cout << "se ha introducido una posicion incorrecta vuelva a intentarlo" << "\n"; //seria mejor evisar las posiciones validas en el main
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
                else if (estaIluminada(tablero.datos[i][columna]))
                {
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
                else if (estaIluminada(tablero.datos[i][columna]))
                {
                    aumentaIluminacion(tablero.datos[i][columna]);
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
                else if (estaIluminada(tablero.datos[i][columna]))
                {
                    aumentaIluminacion(tablero.datos[i][columna]);
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
                else if (estaIluminada(tablero.datos[i][columna]))
                {
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
    if (esParedRestringida(tablero.datos[fila][columna]) && (numBombillasVecinas(tablero, fila, columna) == numParedRestringida(tablero.datos[fila][columna])))
        return true;
    else
        return false;
}

bool estaTerminado(const tTablero& tablero)
{
    bool terminado = true;
    //revisar en todas las paredes si seCumpleRestriccion();
    int i = 0; 
    int j = 0;

    //bucle while para ser mas eficientes y cuando se vea que no termina salir
    while (i < tablero.nFils && terminado)
    {
        while (j < tablero.nCols && terminado)
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
            else if (esBombilla(tablero.datos[i][j]))
            {

            }
            else
            {
                if (estaApagada(tablero.datos[i][j]))
                    terminado = false;
            }
            if (terminado)
                j++;
        }
        if(terminado) //condicion para que no a�ada una vez se salga del bucle
            ++i;
    }


    /*for (int i = 0; i < tablero.nFils; ++i)
    {
        for (int j = 0; j < tablero.nCols; ++j)
        {
            if (esPared(tablero.datos[i][j]))
            {
                if(esParedRestringida(tablero.datos[i][j]))
                {
                    if (!seCumpleRestriccion(tablero, i, j))
                    {
                        terminado = false;
                    }
                }
            }
            else if (esBombilla(tablero.datos[i][j]))
            {

            }
            else
            {
                if (estaApagada(tablero.datos[i][j]))
                    terminado = false;
            }
        }
    }*/
    return terminado;
}

void cargaTableroFichero(ifstream& archivo, tTablero& tab)
{
    char in;
    archivo >> tab.nFils;
    archivo >> tab.nCols;
    for (int i = 0; i < tab.nFils; ++i)
    {
        for (int j = 0; j < tab.nCols; ++j)
        {
            archivo >> in;
            tab.datos[i][j] = charToCelda(in);
        }
    }
}