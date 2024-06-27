#include "../include/Button.hpp"

Button::Button()
{
    data.width = data.height = 100;
    data.x = GetScreenWidth() / 2;
    data.y = GetScreenHeight() / 2;
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
    if(MouseOverlap()) {
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        color = GREEN; else color = YELLOW;
    } else color = RED;
}


// * PRIVATE FUNCTIONS
bool Button::MouseOverlap()
{
    return (GetMouseX() > data.x - data.width / 2 && GetMouseX() < data.x + data.width / 2 &&
            GetMouseY() > data.y - data.height / 2 && GetMouseY() < data.y + data.height / 2);
}