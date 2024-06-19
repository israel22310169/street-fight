#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Controlador.hpp>
#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Ventana v;
    Dibujo d1 (60,1,"fang");
    Dibujo d2 (5,3,"necalli");
    Dibujo d3 (40,10,"poison");
    Dibujo d4 (200,1,"death");
    bool ejecutar = true;
    while (ejecutar)
    {
        // ciclo de actualización
        v.Actualizar();
        if (getch() == 'q')
        {
            ejecutar = false;
        }
        if (getch() == 'd')
        {
            d3.AvanzarX(4);
        }
        if (getch() == 'a')
        {
            d3.RetrocederX(35);
            d4.RetrocederX(199);


        }
        if (getch() == 's')
        {
            d1.BajarY(1);
        }
        if (getch() == 'w')
        {
            d1.SubirY(10);

    }

        // ciclo de dibujo
        clear();

        // v.Dibujar();
        d1.Dibujar();
        d2.Dibujar();
        d3.Dibujar();
        d4.Dibujar();

        refresh();
        usleep(4100);
    }

    return 0;
}
