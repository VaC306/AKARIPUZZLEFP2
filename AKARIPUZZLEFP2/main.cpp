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
    int fila = 0, columna = 0, acciones = 0;
    archivo.open(nombreArchivo);

    if (!archivo.is_open())
        cout << "el archivo no se pudo abrir\n";
    else
    {
        leer(archivo, tab);
        mostrar(tab);

        while (!estaTerminado(tab) && !abandono(fila, columna))
        {
            cout << "introduzca la fila y columna donde quiere realizar un cambio: \n";
            cin >> fila >> columna;

            ejecutarPos(tab, fila, columna);
            mostrar(tab);

            acciones++;
        }

        if (abandono(fila, columna))
        {
            cout << "se ha abandonado el juego! \n";
        }
        else if (estaTerminado(tab))
        {
            cout << "has acabado el juego! \n";
        }
        else
            acciones++;

        cout << "\n" << RED << "el numero total de acciones que se han realizado es de : " << acciones<< RESET <<"\n";
    }

    archivo.close();
    return 0;
}