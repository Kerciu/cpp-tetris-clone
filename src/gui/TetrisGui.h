#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class TetrisGui {
    public:
    TetrisGui(std::string window_name, int width, int height);
    ~TetrisGui() = default;

    bool is_running();
    void handle_events();
    void update();
    void render();

    private:
    sf::RenderWindow window;
};