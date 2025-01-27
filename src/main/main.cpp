#include <SFML/Window.hpp>
#include <memory>
#include "../process/Process.h"

int main(int argc, char** argv) {

    Process process = Process();
    
    process.play_start_sound();
    process.play_music();
    process.game_loop();

    return 0;
}