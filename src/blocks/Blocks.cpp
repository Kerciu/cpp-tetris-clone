#include <SFML/Graphics.hpp>
#include "Block.h"
#include "../grid/Coords.h"

class LBlock : public Block {
    public:
    LBlock() {
        this->set_block_id(1); 
        this->initialize_position_states(BlockType::OTHER_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(0, 2), Coords(1, 0), Coords(1, 1), Coords(1, 2)},
        {Coords(0, 1), Coords(1, 1), Coords(2, 1), Coords(2, 2)},
        {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(2, 0)},
        {Coords(0, 0), Coords(0, 1), Coords(1, 1), Coords(2, 1)}
        };
    }
};

class JBlock : public Block {
    public:
    JBlock() {
        this->set_block_id(2);
        this->initialize_position_states(BlockType::OTHER_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(0, 0), Coords(1, 0), Coords(1, 1), Coords(1, 2)},
        {Coords(0, 1), Coords(0, 2), Coords(1, 1), Coords(2, 1)},
        {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(2, 2)},
        {Coords(0, 1), Coords(1, 1), Coords(2, 0), Coords(2, 1)}
        };
    }
};

class IBlock : public Block {
    public:
    IBlock() {
        this->set_block_id(3);
        this->initialize_position_states(BlockType::I_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(1, 3)},
        {Coords(0, 2), Coords(1, 2), Coords(2, 2), Coords(3, 2)},
        {Coords(2, 0), Coords(2, 1), Coords(2, 2), Coords(2, 3)},
        {Coords(0, 1), Coords(1, 1), Coords(2, 1), Coords(3, 1)}
        };
    }
};

class OBlock : public Block {
    public:
    OBlock() {
        this->set_block_id(4);
        this->initialize_position_states(BlockType::O_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)},
        {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)},
        {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)},
        {Coords(0, 0), Coords(0, 1), Coords(1, 0), Coords(1, 1)}
        };
    }
};

class SBlock : public Block {
    public:
    SBlock() {
        this->set_block_id(5);
        this->initialize_position_states(BlockType::OTHER_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(0, 1), Coords(0, 2), Coords(1, 0), Coords(1, 1)},
        {Coords(0, 1), Coords(1, 1), Coords(1, 2), Coords(2, 2)},
        {Coords(1, 0), Coords(1, 2), Coords(2, 0), Coords(2, 1)},
        {Coords(0, 0), Coords(1, 0), Coords(1, 1), Coords(2, 1)}
        };
    }
};

class TBlock : public Block {
    public:
    TBlock() {
        this->set_block_id(6);
        this->initialize_position_states(BlockType::OTHER_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(0, 1), Coords(1, 0), Coords(1, 1), Coords(1, 2)},
        {Coords(0, 1), Coords(1, 1), Coords(1, 2), Coords(2, 1)},
        {Coords(1, 0), Coords(1, 1), Coords(1, 2), Coords(2, 1)},
        {Coords(0, 1), Coords(1, 0), Coords(1, 1), Coords(2, 1)}
        };
    }
};

class ZBlock : public Block {
    public:
    ZBlock() {
        this->set_block_id(7);
        this->initialize_position_states(BlockType::OTHER_BLOCK);
    }

    private:
    std::vector<position_vector> create_position_vec() override {
        return {
        {Coords(0, 0), Coords(0, 1), Coords(1, 1), Coords(1, 2)},
        {Coords(0, 2), Coords(1, 1), Coords(1, 2), Coords(2, 1)},
        {Coords(1, 0), Coords(1, 1), Coords(2, 1), Coords(2, 2)},
        {Coords(0, 1), Coords(1, 0), Coords(1, 1), Coords(2, 0)}
        };
    }
};