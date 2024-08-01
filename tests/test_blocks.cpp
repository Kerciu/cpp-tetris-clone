#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../src/utils/Coords.h"
#include "../src/blocks/Block.h"
#include "../src/blocks/Blocks.h"

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
