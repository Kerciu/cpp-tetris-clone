#pragma once
#include <stdexcept>

class Coords {
    public:
    Coords(int x, int y);

    int get_x();
    int get_y();

    void set_x(int new_x);
    void set_y(int new_y);

    private:
    int x;
    int y;
};