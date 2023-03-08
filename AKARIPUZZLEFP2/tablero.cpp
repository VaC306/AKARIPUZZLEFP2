#include "tablero.h"
#include "colors.h"
#include <iostream>
#include <iomanip>
using namespace std;

int numFilas(const tTablero& tab)
{
    return tab.nFils;
}

int numCols(const tTablero& tab)
{
    return tab.nCols;
}

void mostrarSeparador(const tTablero& tab) {
    cout << "\t -+";
    for (int col = 0; col < numCols(tab); col++)
        cout << setw(HUECOS + 2) << setfill('-') << '+' << setfill(' ');
    cout << endl;
}

void mostrarCeldas(const tTablero& tab) {
    for (int fila = 0; fila < numFilas(tab); fila++) {
        // mostrar n de fila
        cout << "\t" << LBLUE << setw(HUECOS) << fila << RESET << '|';
        // mostrar contenido de la fila del tablero
        for (int col = 0; col < numCols(tab); col++) {
            if (esBombilla(tab.datos[fila][col])) cout << BG_YELLOW << BLACK;
            else
                if (esParedRestringida(tab.datos[fila][col])) cout << BG_BLACK << WHITE;
                else
                    if (estaApagada(tab.datos[fila][col])) cout << BG_WHITE << WHITE;
                    else
                        if (estaIluminada(tab.datos[fila][col])) cout << BG_YELLOW << WHITE;
            cout << setw(HUECOS) << setfill(' ') << celdaToChar(tab.datos[fila][col]) << " " << RESET;
            cout << '|';
        }
        cout << endl;
        mostrarSeparador(tab);
    }
}

void mostrarValoresColumnas(const tTablero& tab) {
    cout << "\t  |";
    for (int col = 0; col < numCols(tab); col++)
        cout << LBLUE << setw(HUECOS) << col << " " << RESET << '|';
    cout << endl;
    mostrarSeparador(tab);
}



void mostrar(const tTablero& tab) {
    mostrarValoresColumnas(tab);
    mostrarCeldas(tab);
    cout << endl;
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
            tab.datos[i][j] = charToCelda(in);
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