#include <SFML/Graphics.hpp>
#include "Block.h"
#include "../utils/Coords.h"

class LBlock : public Block {
    public:
    LBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};

class JBlock : public Block {
    public:
    JBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};

class IBlock : public Block {
    public:
    IBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};

class OBlock : public Block {
    public:
    OBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};

class SBlock : public Block {
    public:
    SBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};

class TBlock : public Block {
    public:
    TBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};

class ZBlock : public Block {
    public:
    ZBlock();
    std::unique_ptr<Block> clone() const override;

    private:
    std::vector<position_vector> create_position_vec() override;
};
