#pragma once
#include <SFML/Graphics.hpp>

class Arrow
{
    public:
    static void draw_guiding_arrows();

    private:
    static void combine_arrow_w_text();
    static void draw_arrow();
    static void draw_guiding_text();
};