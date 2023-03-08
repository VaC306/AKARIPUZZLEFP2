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
    int fila, columna;
    archivo.open(nombreArchivo);

    if (!archivo.is_open())
        cout << "el archivo no se pudo abrir\n";
    else
    {
        leer(archivo, tab);
        mostrar(tab);
        cout << "introduzca la fila y columna donde quiere realizar un cambio \n";
        cin >> fila >> columna;
        while(!abandono(fila, columna))
        { 
            ejecutarPos(tab, fila, columna);
            mostrar(tab);
            cin >> fila >> columna;
        }
    }
    archivo.close();
    return 0;
}