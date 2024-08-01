#include "Blocks.h"

LBlock::LBlock() {
    this->set_block_id(1); 
    this->initialize_position_states(BlockType::OTHER_BLOCK);
}

std::unique_ptr<Block> LBlock::clone() const {
    return std::make_unique<LBlock>(*this);
}

std::vector<Block::position_vector> LBlock::create_position_vec() {
    return {
    {Coords(0, 2), Coords(1, 0), Coords(1, 1), Coords(1, 2)},
    {Coords(0, 1), Coords(1, 1), Coords(2, 1), Coords(2, 2)},
    {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(2, 0)},
    {Coords(0, 0), Coords(0, 1), Coords(1, 1), Coords(2, 1)}
    };
}

JBlock::JBlock() {
    this->set_block_id(2);
    this->initialize_position_states(BlockType::OTHER_BLOCK);
}

std::unique_ptr<Block> JBlock::clone() const {
    return std::make_unique<JBlock>(*this);
}

std::vector<Block::position_vector> JBlock::create_position_vec() {
    return {
    {Coords(0, 0), Coords(1, 0), Coords(1, 1), Coords(1, 2)},
    {Coords(0, 1), Coords(0, 2), Coords(1, 1), Coords(2, 1)},
    {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(2, 2)},
    {Coords(0, 1), Coords(1, 1), Coords(2, 0), Coords(2, 1)}
    };
}

IBlock::IBlock() {
    this->set_block_id(3);
    this->initialize_position_states(BlockType::I_BLOCK);
}

std::unique_ptr<Block> IBlock::clone() const {
    return std::make_unique<IBlock>(*this);
}

std::vector<Block::position_vector> IBlock::create_position_vec() {
    return {
    {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(1, 3)},
    {Coords(0, 2), Coords(1, 2), Coords(2, 2), Coords(3, 2)},
    {Coords(2, 0), Coords(2, 1), Coords(2, 2), Coords(2, 3)},
    {Coords(0, 1), Coords(1, 1), Coords(2, 1), Coords(3, 1)}
    };
}

OBlock::OBlock() {
    this->set_block_id(4);
    this->initialize_position_states(BlockType::O_BLOCK);
}

std::unique_ptr<Block> OBlock::clone() const {
    return std::make_unique<OBlock>(*this);
}

std::vector<Block::position_vector> OBlock::create_position_vec() {
    return {
    {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)},
    {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)},
    {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)},
    {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)}
    };
}

SBlock::SBlock() {
    this->set_block_id(5);
    this->initialize_position_states(BlockType::OTHER_BLOCK);
}

std::unique_ptr<Block> SBlock::clone() const {
    return std::make_unique<SBlock>(*this);
}

std::vector<Block::position_vector> SBlock::create_position_vec() {
    return {
    {Coords(0, 1), Coords(0, 2), Coords(1, 0), Coords(1, 1)},
    {Coords(0, 1), Coords(1, 1), Coords(1, 2), Coords(2, 2)},
    {Coords(1, 0), Coords(1, 2), Coords(2, 0), Coords(2, 1)},
    {Coords(0, 0), Coords(1, 0), Coords(1, 1), Coords(2, 1)}
    };
}

TBlock::TBlock() {
    this->set_block_id(6);
    this->initialize_position_states(BlockType::OTHER_BLOCK);
}

std::unique_ptr<Block> TBlock::clone() const {
    return std::make_unique<TBlock>(*this);
}

std::vector<Block::position_vector> TBlock::create_position_vec() {
    return {
    {Coords(0, 1), Coords(1, 0), Coords(1, 1), Coords(1, 2)},
    {Coords(0, 1), Coords(1, 1), Coords(1, 2), Coords(2, 1)},
    {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(2, 1)},
    {Coords(0, 1), Coords(1, 0), Coords(1, 1), Coords(2, 1)}
    };
}

ZBlock::ZBlock() {
    this->set_block_id(7);
    this->initialize_position_states(BlockType::OTHER_BLOCK);
}

std::unique_ptr<Block> ZBlock::clone() const {
    return std::make_unique<ZBlock>(*this);
}

std::vector<Block::position_vector> ZBlock::create_position_vec() {
    return {
    {Coords(0, 0), Coords(0, 1), Coords(1, 1), Coords(1, 2)},
    {Coords(0, 2), Coords(1, 1), Coords(1, 2), Coords(2, 1)},
    {Coords(1, 0), Coords(1, 1), Coords(2, 1), Coords(2, 2)},
    {Coords(0, 1), Coords(1, 0), Coords(1, 1), Coords(2, 0)}
    };
}
