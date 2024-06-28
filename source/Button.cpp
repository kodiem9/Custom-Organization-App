#include "../include/Button.hpp"

Button::Button()
{
    data.width = data.height = 100;
    data.x = GetScreenWidth() / 2;
    data.y = GetScreenHeight() / 2;
    mouse_pressed = false;
}


// * PUBLIC FUNCTIONS
void Button::Init(Vector2 pos, int width, int height)
{
    data.x = pos.x; data.y = pos.y;
    data.width = width; data.height = height;
}

void Button::Draw()
{
    DrawRectangle(data.x - data.width / 2, data.y - data.height / 2, data.width, data.height, color);
}

void Button::Update()
{
    if(utils::MouseOverlap(data.x, data.y, data.width, data.height)) {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) mouse_pressed = true;

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && mouse_pressed)
            color = GREEN;
        else
            color = YELLOW;
    }
    else {
        mouse_pressed = false;
        color = RED;
    }
}