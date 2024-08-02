#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../src/game/game.h"
#include "../src/grid/Grid.h"
#include "../src/blocks/Blocks.h"

bool positions_changed(const std::vector<Coords>& original, const std::vector<Coords>& new_positions) {
    if (original.size() != new_positions.size()) return true;
    for (size_t i = 0; i < original.size(); ++i) {
        if (original[i].get_x() != new_positions[i].get_x() || original[i].get_y() != new_positions[i].get_y()) {
            return true;
        }
    }
    return false;
}

TEST(GameTest, Constructor) {
    Game game;
    EXPECT_FALSE(game.get_blocks().empty());
    EXPECT_NE(game.get_grid(), Grid());
    EXPECT_NE(game.get_blocks()[0], nullptr);
}

TEST(GameTest, GetSetGrid) {
    Game game;
    Grid new_grid;
    game.set_grid(new_grid);
    EXPECT_EQ(game.get_grid(), new_grid);
}

TEST(GameTest, GetSetBlocks) {
    Game game;
    Game::block_vector new_blocks;
    new_blocks.push_back(std::make_unique<IBlock>());
    new_blocks.push_back(std::make_unique<OBlock>());
    game.set_blocks(std::move(new_blocks));
    EXPECT_EQ(game.get_blocks().size(), 2);
    EXPECT_NE(game.get_blocks()[0], nullptr);
    EXPECT_NE(game.get_blocks()[1], nullptr);
}

TEST(GameTest, MoveBlockLeft) {
    Game game;
    auto original_position = game.get_blocks()[0]->get_occupied_cell_positions();
    game.move_block_left();
    auto new_position = game.get_blocks()[0]->get_occupied_cell_positions();
    EXPECT_TRUE(positions_changed(original_position, new_position));
    EXPECT_LT(new_position[0].get_x(), original_position[0].get_x());
}

TEST(GameTest, MoveBlockRight) {
    Game game;
    auto original_position = game.get_blocks()[0]->get_occupied_cell_positions();
    game.move_block_right();
    auto new_position = game.get_blocks()[0]->get_occupied_cell_positions();
    EXPECT_TRUE(positions_changed(original_position, new_position));
    EXPECT_GT(new_position[0].get_x(), original_position[0].get_x());
}

TEST(GameTest, MoveBlockDown) {
    Game game;
    auto original_position = game.get_blocks()[0]->get_occupied_cell_positions();
    game.move_block_down();
    auto new_position = game.get_blocks()[0]->get_occupied_cell_positions();
    EXPECT_TRUE(positions_changed(original_position, new_position));
    EXPECT_GT(new_position[0].get_y(), original_position[0].get_y());
}

TEST(GameTest, RotateBlock) {
    Game game;
    auto original_position = game.get_blocks()[0]->get_occupied_cell_positions();
    game.rotate_block();
    auto new_position = game.get_blocks()[0]->get_occupied_cell_positions();
    EXPECT_TRUE(positions_changed(original_position, new_position));
    EXPECT_NE(original_position, new_position);
}