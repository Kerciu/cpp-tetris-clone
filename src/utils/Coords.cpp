#include "Coords.h"

Coords::Coords(int row, int col) : row(row), col(col) { }

int Coords::get_row() const
{
    return row;
}

int Coords::get_col() const
{
    return col;
}

int Coords::get_x() const
{
    return col;
}

int Coords::get_y() const
{
    return row;
}

void Coords::set_row(int new_row)
{
    row = new_row;
}

void Coords::set_col(int new_col)
{
    col = new_col;
}
