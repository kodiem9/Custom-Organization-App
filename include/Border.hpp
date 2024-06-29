#pragma once
#include "../raylib/raylib.h"
#include <vector>

struct Border_Data
{
    short x, y, width, height;

    float roundness;
    char smoothness;

    Color color;
};

class Border
{
    public:
        void Init(short x, short y, short width, short height, float roundess, char smoothness);
        void Draw();
    
    private:
        std::vector<Border_Data> borders;
};