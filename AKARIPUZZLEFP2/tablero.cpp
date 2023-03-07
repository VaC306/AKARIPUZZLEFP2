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
        cout << setw(2) << "|" << setw(2) << i ;
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
        cout << i;
        for (int k = 0; k < tab.nCols; ++k)
        {
            cout << "|" << setw(4);
        }
        cout << "   |\n";
    }
    cout << "-" << "+";
    for (int j = 0; j < tab.nCols; ++j)
    {
        cout << "-" << "-" << "-" << "+";
    }
}

void leer(ifstream& archivo, tTablero& tab)
{
    archivo >> tab.nFils;
    archivo >> tab.nCols;
}

tCelda celdaEnPos(const tTablero& tablero, int fila, int columna)
{
    return tablero.datos[fila][columna];
}

void ponCeldaEnPos(tTablero& tablero, int fila, int columna, const tCelda& c)
{
    tablero.datos[fila][columna] = c;
}

tCelda celdaEnPos(const tTablero& tablero, int fila, int columna)
{
    return tablero.datos[fila][columna];
}