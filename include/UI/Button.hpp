#pragma once
#include "../Utils/Utils.hpp"
#include <vector>

enum Button_Events
{
    FIRE_NULL,
    FIRE_NEW_PROJECT_WINDOW,
    FIRE_EXIT_NEW_PROJECT_WINDOW,
    FIRE_CREATE_PROJECT
};

struct Button_Data
{
    short x, y, width, height;
    bool mouse_pressed, mouse_hover;

    float roundness;
    char smoothness;

    char type;

    Color color;
};

class Button
{
    public:
        Button();
        void Init(short x, short y, short width, short height,
                    float roundness, char smoothness, char type);
        void Draw();
        void Update();
        char FireEvent();
        void Reset();
    
    private:
        Sound sound_hover, sound_click;
        std::vector<Button_Data> buttons;
        char fire_event;
};