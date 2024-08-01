#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <chrono>
#include <random>
#include <memory>
#include "../grid/Grid.h"
#include "../blocks/Blocks.h"

class Game
{
    public:
    typedef std::vector<std::unique_ptr<Block>> block_vector;
    typedef std::unique_ptr<Block> block_ptr;
    Game();

    Grid get_grid();
    block_vector get_blocks();
    void set_grid(Grid new_grid);
    void set_blocks(block_vector new_blocks);

    void move_block_left();
    void move_block_right();
    void move_block_down();
    void rotate_block();
    void handle_input();

    void display(sf::RenderWindow* window);

    private:
    std::unordered_map<sf::Keyboard::Key, std::chrono::steady_clock::time_point> last_key_press_time;
    std::chrono::milliseconds debounce_time{100};
    Grid grid;
    block_vector blocks;
    block_ptr current_block;
    block_ptr next_block;

    bool is_block_outside();
    sf::Keyboard::Key get_key_pressed();
    bool can_execute(sf::Keyboard::Key key, std::chrono::steady_clock::time_point now);
    block_vector generate_blocks();
    block_ptr get_random_block();
    void fill_empty_vector();
    int get_random_index() const;
};