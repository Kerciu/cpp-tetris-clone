#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "../grid/Grid.h"
#include "../blocks/Blocks.cpp"

class Process
{
    public:
    typedef std::vector<std::unique_ptr<Block>> block_vector;
    typedef std::unique_ptr<Block> block_ptr;
    Process();

    Grid get_grid();
    block_vector get_blocks();
    void set_grid(Grid new_grid);
    void set_blocks(block_vector new_blocks);

    void move_block_left();
    void move_block_right();
    void move_block_down();
    void handle_input();

    void display(sf::RenderWindow* window);

    private:
    Grid grid;
    block_vector blocks;
    block_ptr current_block;
    block_ptr next_block;

    sf::Keyboard::Key get_key_pressed();
    block_vector generate_blocks();
    block_ptr get_random_block();
    void fill_empty_vector();
    int get_random_index() const;
};