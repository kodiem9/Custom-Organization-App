#include "../include/Border.hpp"


// * PUBLIC FUNCTIONS
void Border::Init(short x, short y, short width, short height, float roundness, char smoothness)
{
    Border_Data temp_border;

    temp_border.width = width;
    temp_border.height = height;
    temp_border.x = x - width / 2;
    temp_border.y = y - height / 2;
    temp_border.roundness = roundness;
    temp_border.smoothness = smoothness;
    temp_border.color = BLACK;

    borders.push_back(temp_border);
}

void Border::Draw()
{
    for(Border_Data border: borders) {
        DrawRectangleRounded(Rectangle{(float)border.x, (float)border.y, (float)border.width, (float)border.height}, border.roundness, border.smoothness, border.color);
    }
}

void Border::Reset()
{
    borders.clear();
}