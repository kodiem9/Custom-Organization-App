#include "../include/Button.hpp"


Button::Button()
{
    fire_event = FIRE_NULL;
}


// * PUBLIC FUNCTIONS
void Button::Init(short x, short y, short width, short height,
                    float roundness, char smoothness, char type)
{
    Button_Data temp_button;

    temp_button.width = width;
    temp_button.height = height;
    temp_button.x = x - width / 2;
    temp_button.y = y - height / 2;
    temp_button.roundness = roundness;
    temp_button.smoothness = smoothness;
    temp_button.type = type;

    buttons.push_back(temp_button);
}

void Button::Draw()
{
    for(Button_Data button: buttons) {
        DrawRectangleRounded(Rectangle{(float)button.x, (float)button.y, (float)button.width, (float)button.height}, button.roundness, button.smoothness, button.color);
    }
}

void Button::Update()
{
    for(Button_Data &button: buttons) {
        if(utils::MouseOverlap(button.x, button.y, button.width, button.height)) {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                button.color = GREEN;
                fire_event = button.type;
            } else button.color = YELLOW;
        } else button.color = RED;
    }
}

char Button::FireEvent()
{
    char temp_char = fire_event;
    fire_event = FIRE_NULL;
    return temp_char;
}