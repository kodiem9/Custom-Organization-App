#include "../include/Utils.hpp"

bool utils::MouseOverlap(int x, int y, int width, int height)
{
    return (GetMouseX() > x && GetMouseX() < x + width &&
            GetMouseY() > y && GetMouseY() < y + height);
}