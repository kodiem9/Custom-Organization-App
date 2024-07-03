#include "../../include/UI/Button.hpp"


Button::Button()
{
    Reset();
    sound_hover = LoadSound("assets/sounds/sticky.ogg");
    sound_click = LoadSound("assets/sounds/click.ogg");
}


// * PUBLIC FUNCTIONS
void Button::Init(short x, short y, short width, short height, Button_Properties properties, char type)
{
    Button_Data temp_button;

    temp_button.width = width;
    temp_button.height = height;
    temp_button.x = x - width / 2;
    temp_button.y = y - height / 2;
    temp_button.properties.roundness = properties.roundness;
    temp_button.properties.smoothness = properties.smoothness;
    temp_button.type = type;

    buttons.push_back(temp_button);
}

void Button::Draw()
{
    for(Button_Data button: buttons) {
        DrawRectangleRounded(Rectangle{(float)button.x, (float)button.y, (float)button.width, (float)button.height}, button.properties.roundness, button.properties.smoothness, button.color);
    }
}

void Button::Update()
{
    for(Button_Data &button: buttons) {

        if(utils::MouseOverlap(button.x, button.y, button.width, button.height)) {
            if(button.mouse_hover == false) {
                button.mouse_hover = true;
                PlaySound(sound_hover);
            }

            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                button.color = GREEN;
                fire_event = button.type;
                PlaySound(sound_click);
            } else button.color = YELLOW;
        }
        else {
            button.mouse_hover = false;
            button.color = RED;
        }

    }
}

char Button::FireEvent()
{
    char temp_char = fire_event;
    fire_event = FIRE_NULL;
    return temp_char;
}

void Button::Reset()
{
    buttons.clear();
    fire_event = FIRE_NULL;
}