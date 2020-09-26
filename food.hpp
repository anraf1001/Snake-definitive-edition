#pragma once

#include <SFML/Graphics.hpp>

#include "drawable.hpp"

class Food : public Drawable {
public:
    Food(float x, float y);

    void generateNewPos();
};
