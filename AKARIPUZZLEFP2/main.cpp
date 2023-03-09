#include <iostream>
#include <fstream>
#include "tablero.h"
#include "juego.h"
using namespace std;

const string nombreArchivo = "tablero.txt";

int main()
{
    tTablero tab;
    ifstream archivo;
    int fila, columna, acciones = 0;
    archivo.open(nombreArchivo);

    if (!archivo.is_open())
        cout << "el archivo no se pudo abrir\n";
    else
    {
        leer(archivo, tab);
        mostrar(tab);
        cout << "introduzca la fila y columna donde quiere realizar un cambio: \n";
        cin >> fila >> columna;
        acciones++;
        while (!abandono(fila, columna) || !estaTerminado(tab))
        {
            ejecutarPos(tab, fila, columna);
            mostrar(tab);
            cout << "introduzca la fila y columna donde quiere realizar un cambio: \n";
            cin >> fila >> columna;
            acciones++;
        }

        cout << "\n" << RED << "el numero total de acciones que se han realizado es de : " << acciones<< RESET <<"\n";
    }

    archivo.close();
    return 0;
}