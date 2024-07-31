#pragma once
#include <vector>
#include <map>
#include "../grid/Coords.h"
#include "../colors/colors.h"

class Block {
    public:
    typedef int rotation_state;
    typedef std::vector<Coords> position_vector;
    typedef std::vector<sf::Color> color_vector;

    Block();

    virtual void draw_block() = 0;
    virtual std::vector<position_vector> create_position_vec() = 0;

    int get_block_id();
    int get_cell_size();
    rotation_state get_rotation_state();
    void set_block_id(int block_id);
    std::map<rotation_state, position_vector>* get_cells_ptr();

    private:
    int block_id;
    int cell_size;
    rotation_state rotation;
    color_vector colors;
    std::map<rotation_state, position_vector> cells;
};