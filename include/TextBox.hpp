#pragma once
#include "../raylib/raylib.h"
#include "Utils.hpp"
#include <vector>
#include <string>
#include <iostream>

#define HOLD_BUFFER_SIZE 30
#define WAIT_BUFFER_SIZE 1

struct TextBox_Data
{
    short x, y, width, height;
    std::string text;

    bool selected;

    float roundness;
    char smoothness;

    Color color;
};

class TextBox
{
    public:
        TextBox();
        ~TextBox();
        void Init(short x, short y, short width, short height, float roundess, char smoothness);
        void Draw();
        void Update();
    
    private:
        void Type(std::string *text, const short width, const short height);

        Font font;
        std::vector<TextBox_Data> text_boxes;
        char key, event; 
        short hold_buffer, wait_buffer;
};