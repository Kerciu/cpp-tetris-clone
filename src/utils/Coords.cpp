#include "Coords.h"

Coords::Coords(int x, int y) : x(x), y(y) { }

int Coords::get_x()
{
    return x;
}

int Coords::get_y()
{
    return y;
}

void Coords::set_x(int new_x)
{
    x = new_x;
}

void Coords::set_y(int new_y)
{
    y = new_y;
}
