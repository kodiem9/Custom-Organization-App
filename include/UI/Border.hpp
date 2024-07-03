#pragma once
#include "../../raylib/raylib.h"
#include <vector>

struct Border_Properties
{
    float roundness;
    char smoothness;
};

struct Border_Data
{
    short x, y, width, height;
    Border_Properties properties;
    Color color;
};

class Border
{
    public:
        void Init(short x, short y, short width, short height, Border_Properties properties);
        void Draw();
        void Reset();
    
    private:
        std::vector<Border_Data> borders;
};