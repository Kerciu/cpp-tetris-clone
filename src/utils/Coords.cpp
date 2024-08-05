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

void Coords::set_x(int new_x)
{
    col = new_x;
}

void Coords::set_y(int new_y)
{
    row = new_y;
}

bool Coords::operator==(const Coords &other) const
{
    return (this->row == other.row && this->col == other.col);
}

bool Coords::operator!=(const Coords &other) const
{
    return !(*this == other);
}
