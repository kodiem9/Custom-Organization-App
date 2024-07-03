#include "../../include/UI/Border.hpp"


// * PUBLIC FUNCTIONS
void Border::Init(short x, short y, short width, short height, Border_Properties properties)
{
    Border_Data temp_border;

    temp_border.width = width;
    temp_border.height = height;
    temp_border.x = x - width / 2;
    temp_border.y = y - height / 2;
    temp_border.properties.roundness = properties.roundness;
    temp_border.properties.smoothness = properties.smoothness;
    temp_border.color = BLACK;

    borders.push_back(temp_border);
}

void Border::Draw()
{
    for(Border_Data border: borders) {
        DrawRectangleRounded(Rectangle{(float)border.x, (float)border.y, (float)border.width, (float)border.height}, border.properties.roundness, border.properties.smoothness, border.color);
    }
}

void Border::Reset()
{
    borders.clear();
}