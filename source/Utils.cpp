#include "../include/Utils.hpp"

bool utils::MouseOverlap(int x, int y, int width, int height)
{
    return (GetMouseX() > x - width / 2 && GetMouseX() < x + width / 2 &&
            GetMouseY() > y - height / 2 && GetMouseY() < y + height / 2);
}