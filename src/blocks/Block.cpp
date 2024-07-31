#pragma once
#include <vector>
#include <map>
#include "Coords.h"

class Block {
    public:
    typedef int rotation_state;
    typedef std::vector<Coords> position_vector;

    Block();

    int get_block_id();
    int get_cell_size();
    rotation_state get_rotation_state();
    void set_block_id(int block_id);

    private:
    int block_id;
    int cell_size;
    rotation_state rotation_state;
    std::map<rotation_state, position_vector> cells;
};