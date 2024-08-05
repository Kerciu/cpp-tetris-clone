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
    void set_x(int new_x);
    void set_y(int new_y);

    bool operator==(const Coords& other) const;
    bool operator!=(const Coords& other) const;

    private:
    int row;
    int col;
};