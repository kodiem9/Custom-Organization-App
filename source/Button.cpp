#include "../include/Button.hpp"


// * PUBLIC FUNCTIONS
void Button::Init(int x, int y, int width, int height)
{
    Button_Data temp_button;

    temp_button.x = x;
    temp_button.y = y;
    temp_button.width = width;
    temp_button.height = height;

    buttons.push_back(temp_button);
}

void Button::Draw()
{
    for(Button_Data button: buttons) {
        DrawRectangle(button.x - button.width / 2, button.y - button.height / 2, button.width, button.height, button.color);
    }
}

void Button::Update()
{
    for(Button_Data &button: buttons) {
        if(utils::MouseOverlap(button.x, button.y, button.width, button.height)) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) button.mouse_pressed = true;

            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && button.mouse_pressed)
                button.color = GREEN;
            else
                button.color = YELLOW;
        }
        else {
            button.mouse_pressed = false;
            button.color = RED;
        }
    }
}