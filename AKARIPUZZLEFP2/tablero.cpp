#include "tablero.h"

int numFilas(const tTablero& tab)
{
    return tab.nFils;
}

int numCols(const tTablero& tab)
{
    return tab.nCols;
}

void mostrar(const tTablero& tab)
{
    for (int i = 0; i < tab.nCols; ++i) //imprime la cabecera donde estan los indices de columnas
    {
        cout << setw(2) << "|" << BLUE << setw(2) << i << RESET;
    }
    cout << " |\n";

    for(int i = 0; i < tab.nFils; ++i)
    {
        cout << "-" << "+";
        for (int j = 0; j < tab.nCols; ++j)
        {
            cout << "-" << "-" << "-" << "+";
        }
        cout << "\n";
        cout << BLUE << i << RESET;
        for (int k = 0; k < tab.nCols; ++k)
        {   
            if (k == 0)
            {
                cout << "|";
            }
            if (tab.datos[i][k].tipo == PARED && tab.datos[i][k].numBombillas == 0) //celdas consideradas pared
            {
                cout << setw(4) <<"|";
            }
            else if (tab.datos[i][k].tipo == PARED && tab.datos[i][k].numBombillas  != 0) //celdas con una restriccion en cuanto al numero de bombillas
            {
                cout << setw(2) << tab.datos[i][k].numBombillas << setw(2) << "|";
            }
            else if (tab.datos[i][k].tipo == SIN_BOMBILLA) //celdas de color blanco WHITE de alguna manera
            {
                cout << BG_WHITE << "xxx" << RESET << "|";
            }

        }
        cout << "\n";
    }
    cout << "-" << "+";
    for (int j = 0; j < tab.nCols; ++j)
    {
        cout << "-" << "-" << "-" << "+";
    }
}

void leer(ifstream& archivo, tTablero& tab)
{
    char in;
    archivo >> tab.nFils;
    archivo >> tab.nCols;
    for (int i = 0; i < tab.nFils; ++i)
    {
        for (int j = 0; j < tab.nCols; ++j)
        {
            archivo >> in;
            if (in == '.')
            {
                tab.datos[i][j].tipo = SIN_BOMBILLA;
                tab.datos[i][j].numBombillas = 0;
            }
            else if (in == 'X')
            {
                tab.datos[i][j].tipo = PARED;
                tab.datos[i][j].numBombillas = 0;
            }
            else if (in == '0' || in == '1' || in == '2' || in == '3' || in == '4')
            {
                tab.datos[i][j].tipo = PARED;
                tab.datos[i][j].numBombillas = inToInt(in);
            }
        }
    }
}

tCelda celdaEnPos(const tTablero& tablero, int fila, int columna)
{
    return tablero.datos[fila][columna];
}

void ponCeldaEnPos(tTablero& tablero, int fila, int columna, const tCelda& c)
{
    tablero.datos[fila][columna] = c;
}