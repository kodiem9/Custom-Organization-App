#pragma once
#include "../raylib/raylib.h"

struct Button_Data
{
    int x, y, width, height;
};

class Button
{
    public:
        Button();
        void Init(Vector2 pos, int width, int height);
        void Draw();
        void Update();
    
    private:
        bool MouseOverlap();

        Button_Data data;
        Color color;
};