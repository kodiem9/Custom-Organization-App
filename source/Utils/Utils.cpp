#include "../../include/Utils/Utils.hpp"

bool utils::MouseOverlap(short x, short y, short width, short height)
{
    return (GetMouseX() > x && GetMouseX() < x + width &&
            GetMouseY() > y && GetMouseY() < y + height);
}

bool utils::BufferKeyPressed(short key, char buffer)
{
    return (IsKeyPressed(key) || (IsKeyDown(key) && buffer == 0));
}