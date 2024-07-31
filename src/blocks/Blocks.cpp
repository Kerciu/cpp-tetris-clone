#include "Block.h"
#include "../grid/Coords.h"

class LBlock : public Block {
    public:
    LBlock() {
        this->set_block_id(1);
        this->initialize_posiiton_states();
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

    void initialize_posiiton_states() {
        for (int i = 0; i < 4; ++i)
            (*this->get_cells_ptr())[i] = create_position_vec()[i];
    }
};