#pragma once

class Coords {
    public:
    Coords(int row, int col);

    int get_row() const;
    int get_col() const;

    int get_x() const;
    int get_y() const;

    void set_row(int new_row);
    void set_col(int new_col);

    private:
    int row;
    int col;
};