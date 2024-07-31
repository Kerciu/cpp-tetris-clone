#pragma once
#include <vector>
#include <map>
#include "../utils/Coords.h"
#include "../utils/colors.h"

class Block {
    public:
    typedef int rotation_state;
    typedef int offset;
    typedef std::vector<Coords> position_vector;
    typedef std::vector<sf::Color> color_vector;

    enum class BlockType {
        I_BLOCK, O_BLOCK, OTHER_BLOCK
    };

    Block();
    virtual ~Block() = default;

    virtual std::vector<position_vector> create_position_vec() = 0;
    void draw_block(sf::RenderWindow* window);

    void move_block(offset rows, offset cols);
    void spawn_in_the_middle(BlockType type);

    Block::position_vector get_occupied_cell_positions();

    int get_block_id();
    int get_cell_size();
    rotation_state get_rotation_state();
    color_vector get_color_vector();
    void set_block_id(int block_id);
    std::map<rotation_state, position_vector>* get_cells_ptr();
    void initialize_position_states(BlockType type);

    private:
    int block_id;
    int cell_size;
    offset row_offset;
    offset col_offset;
    rotation_state rotation;
    color_vector colors;
    std::map<rotation_state, position_vector> cells;
};