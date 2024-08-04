#include <SFML/Window.hpp>
#include <memory>
#include "../process/process.h"

int main(int argc, char** argv) {

    Process process = Process();
    
    process.play_music();
    process.game_loop();

    return 0;
}