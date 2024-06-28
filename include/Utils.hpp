#pragma once
#include "../raylib/raylib.h"

namespace utils
{
    bool MouseOverlap(short x, short y, short width, short height);
    bool BufferKeyPressed(short key, char buffer);
};