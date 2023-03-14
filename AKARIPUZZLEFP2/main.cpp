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
    bool terminado, abandonado;
    archivo.open(nombreArchivo);

    if (!archivo.is_open())
        cout << "el archivo no se pudo abrir\n";
    else
    {
        leer(archivo, tab);
        mostrar(tab);
        cout << "introduzca la fila y columna donde quiere realizar un cambio: \n";
        cin >> fila >> columna;
        do
        {
            ejecutarPos(tab, fila, columna);
            mostrar(tab);
            cout << "introduzca la fila y columna donde quiere realizar un cambio: \n";
            cin >> fila >> columna;
            acciones++;

            if (fila == -1 && columna == -1)
                resetearTablero(tab);

            terminado = estaTerminado(tab);
            abandonado = abandono(fila, columna);

        } while (!terminado || !abandono);

        if (abandonado)
        {
            cout << "se ha abandonado el juego! \n";
        }
        else if (terminado)
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