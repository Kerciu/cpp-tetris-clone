#include "Coords.h"

Coords::Coords(int x, int y) : x(x), y(y)
{
    if (!(validate(x) && validate(y))) {
        throw std::out_of_range("invalid coordinates");
    }
}

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
    if (validate(new_x)) x = new_x;
}

void Coords::set_y(int new_y)
{
    if (validate(new_y)) y = new_y;
}

bool Coords::validate(int new_coord)
{
    return (new_coord > 0);
}
