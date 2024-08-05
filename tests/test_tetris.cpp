#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../src/gui/TetrisGui.h"
#include "../src/grid/Grid.h"
#include "../src/utils/Coords.h"
#include "../src/utils/colors.h"
#include "../src/game/game.h"
#include "../src/blocks/Blocks.h"
#include "../src/blocks/Block.h"

class TetrisGuiTest : public ::testing::Test {
protected:
    void SetUp() override {
        tetris_gui = std::make_unique<TetrisGui>("Test Window", 800, 600);
    }

    std::unique_ptr<TetrisGui> tetris_gui;
    Grid grid;
    Coords coords{10, 20};
};

class MockBlock : public Block {
public:
    MockBlock() : Block() {}
    std::unique_ptr<Block> clone() const override {
        return std::make_unique<MockBlock>(*this);
    }
    std::vector<position_vector> create_position_vec() override {
        return {};
    }
};

bool positions_changed(const std::vector<Coords>& original, const std::vector<Coords>& new_positions) {
    if (original.size() != new_positions.size()) return true;
    for (size_t i = 0; i < original.size(); ++i) {
        if (original[i].get_x() != new_positions[i].get_x() || original[i].get_y() != new_positions[i].get_y()) {
            return true;
        }
    }
    return false;
}

TEST_F(TetrisGuiTest, WindowCreation) {
    EXPECT_TRUE(tetris_gui->is_running());
}

TEST_F(TetrisGuiTest, WindowClose) {
    EXPECT_FALSE(tetris_gui->is_running());
}

TEST_F(TetrisGuiTest, CoordsCreation) {
    EXPECT_NO_THROW(Coords(10, 20));
}

TEST_F(TetrisGuiTest, CoordsGetters) {
    Coords coords(10, 20);
    EXPECT_EQ(coords.get_x(), 10);
    EXPECT_EQ(coords.get_y(), 20);
}

TEST_F(TetrisGuiTest, CoordsSetters) {
    Coords coords(10, 20);
    coords.set_x(30);
    coords.set_y(40);
    EXPECT_EQ(coords.get_x(), 30);
    EXPECT_EQ(coords.get_y(), 40);
}

TEST_F(TetrisGuiTest, CoordsInvalidArgumentsInSetter) {
    Coords coords(10, 20);
    EXPECT_THROW(coords.set_x(-5), std::out_of_range);
    EXPECT_THROW(coords.set_y(-10), std::out_of_range);
}

TEST_F(TetrisGuiTest, CoordsCreationInvalidArgumentsInConstuctor) {
    EXPECT_THROW(Coords(-10, 20), std::out_of_range);
    EXPECT_THROW(Coords(10, -20), std::out_of_range);
}

// distribution get_grid_distribution();
// color_vector get_colors();
// void set_grid_distribution(distribution new_distribution);
// void set_colors(color_vector new_grid_colors);

TEST_F(TetrisGuiTest, GridCreation) {
    Grid grid;
    auto distribution = grid.get_grid_distribution();
    for (const auto& row : *distribution) {
        for (const auto& cell : row) {
            EXPECT_EQ(cell, 0);
        }
    }
}

TEST_F(TetrisGuiTest, GridCreationDistributionGetter) {
    Grid grid;
    auto distribution = grid.get_grid_distribution();
    EXPECT_EQ(distribution->size(), grid.get_num_rows());
    EXPECT_EQ((*distribution)[0].size(), grid.get_num_cols());
}


TEST_F(TetrisGuiTest, GridCreationDistributionSetter) {
    Grid grid;
    Grid::distribution new_distribution = {{1, 2}}; //std::array<std::array<int, 10>, 20>
    grid.set_grid_distribution(new_distribution);
    auto distribution = grid.get_grid_distribution();
    EXPECT_EQ(*distribution, new_distribution);
}

TEST_F(TetrisGuiTest, GridCreationColorGetter) {
    Grid grid;
    auto colors = grid.get_colors();
    EXPECT_EQ(colors.size(), 8);
}

TEST_F(TetrisGuiTest, GridCreationColorSetter) {
    Grid grid;
    Grid::color_vector new_colors = {sf::Color::White, sf::Color::Black};
    grid.set_colors(new_colors);
    auto colors = grid.get_colors();
    EXPECT_EQ(colors, new_colors);
}

TEST_F(TetrisGuiTest, ColorCreationVector) {
    Grid::color_vector vec = get_cell_colors();
    sf::Color dark_grey = {26, 31, 40};
    sf::Color orange = {226, 116, 17};

    EXPECT_EQ(vec[0], dark_grey);
    EXPECT_EQ(vec[1], sf::Color::Green);
    EXPECT_EQ(vec[2], sf::Color::Red);
    EXPECT_EQ(vec[3], orange);
    EXPECT_EQ(vec[4], sf::Color::Yellow);
    EXPECT_EQ(vec[5], sf::Color::Magenta);
    EXPECT_EQ(vec[6], sf::Color::Cyan);
    EXPECT_EQ(vec[7], sf::Color::Blue);
}

TEST(BlockTest, InitialValues) {
    MockBlock block;
    EXPECT_EQ(block.get_block_id(), 0);
    EXPECT_EQ(block.get_cell_size(), 30);
    EXPECT_EQ(block.get_rotation_state(), 0);
    EXPECT_EQ(block.get_color_vector().size(), 0);
}

TEST(BlockTest, SetAndGetBlockId) {
    MockBlock block;
    block.set_block_id(5);
    EXPECT_EQ(block.get_block_id(), 5);
}

TEST(BlockTest, MoveBlock) {
    MockBlock block;
    block.move_block(2, 3);
    auto positions = block.get_occupied_cell_positions();
    for (const auto& pos : positions) {
        EXPECT_EQ(pos.get_x(), pos.get_x() + 3);
        EXPECT_EQ(pos.get_y(), pos.get_y() + 2);
    }
}

TEST(BlockTest, Rotation) {
    MockBlock block;
    block.rotate();
    EXPECT_EQ(block.get_rotation_state(), 1);
    block.rotate();
    EXPECT_EQ(block.get_rotation_state(), 2);
    block.undo_rotation();
    EXPECT_EQ(block.get_rotation_state(), 1);
    block.undo_rotation();
    EXPECT_EQ(block.get_rotation_state(), 0);
}

TEST(LBlockTest, PositionVectors) {
    LBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(JBlockTest, PositionVectors) {
    JBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(IBlockTest, PositionVectors) {
    IBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(OBlockTest, PositionVectors) {
    OBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(SBlockTest, PositionVectors) {
    SBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(TBlockTest, PositionVectors) {
    TBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(ZBlockTest, PositionVectors) {
    ZBlock block;
    auto positions = block.get_cells_ptr();
    EXPECT_EQ(positions->size(), 4);
}

TEST(BlockCloneTest, CloneIsUnique) {
    LBlock original;
    auto clone = original.clone();
    EXPECT_NE(clone.get(), &original);
    EXPECT_EQ(clone->get_block_id(), original.get_block_id());
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}