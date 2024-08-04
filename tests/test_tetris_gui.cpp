#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../src/gui/TetrisGui.h"
#include "../src/grid/Grid.h"
#include "../src/utils/Coords.h"
#include "../src/utils/colors.h"

class TetrisGuiTest : public ::testing::Test {
protected:
    void SetUp() override {
        tetris_gui = std::make_unique<TetrisGui>("Test Window", 800, 600);
    }

    std::unique_ptr<TetrisGui> tetris_gui;
    Grid grid;
    Coords coords{10, 20};
};

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
    for (const auto& row : distribution) {
        for (const auto& cell : row) {
            EXPECT_EQ(cell, 0);
        }
    }
}

TEST_F(TetrisGuiTest, GridCreationDistributionGetter) {
    Grid grid;
    auto distribution = grid.get_grid_distribution();
    EXPECT_EQ(distribution.size(), grid.get_num_rows());
    EXPECT_EQ(distribution[0].size(), grid.get_num_cols());
}


TEST_F(TetrisGuiTest, GridCreationDistributionSetter) {
    Grid grid;
    Grid::distribution new_distribution = {{1, 2}}; //std::array<std::array<int, 10>, 20>
    grid.set_grid_distribution(new_distribution);
    auto distribution = grid.get_grid_distribution();
    EXPECT_EQ(distribution, new_distribution);
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
