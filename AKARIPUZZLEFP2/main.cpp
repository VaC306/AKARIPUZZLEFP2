#include <iostream>
#include <fstream>
#include "tablero.h"
using namespace std;

const string nombreArchivo = "tablero.txt";

int main()
{
    tTablero tab;
    ifstream archivo;
    archivo.open("tablero.txt");

    if (!archivo.is_open())
        cout << "el archivo no se pudo abrir\n";
    else
    {
        leer(archivo, tab);
        mostrar(tab);
    }
    archivo.close();
    return 0;
}