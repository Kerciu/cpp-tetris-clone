#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "TetrisGui.h"

class TetrisGuiTest : public ::testing::Test {
protected:
    void SetUp() override {
        tetris_gui = std::make_unique<TetrisGui>("Test Window", 800, 600);
    }

    std::unique_ptr<TetrisGui> tetris_gui;
};

TEST_F(TetrisGuiTest, WindowCreation) {
    EXPECT_TRUE(tetris_gui->is_running());
}

TEST_F(TetrisGuiTest, WindowClose) {
    tetris_gui->handle_events();
    EXPECT_FALSE(tetris_gui->is_running());
}
