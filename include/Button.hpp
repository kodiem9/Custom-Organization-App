#pragma once
#include "../raylib/raylib.h"
#include "Utils.hpp"
#include <vector>

struct Button_Data
{
    int x, y, width, height;
    bool mouse_pressed;
    Color color;
};

class Button
{
    public:
        void Init(int x, int y, int width, int height);
        void Draw();
        void Update();
    
    private:
        std::vector<Button_Data> buttons;
};