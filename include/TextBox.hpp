#pragma once
#include "../raylib/raylib.h"
#include "Utils.hpp"
#include <vector>
#include <string>
#include <iostream>

#define HOLD_BUFFER_SIZE 30
#define WAIT_BUFFER_SIZE 1
#define CURSOR_LIFE_TIME 40

struct TextBox_Data
{
    short x, y, width, height;
    std::string text;

    bool selected;

    float roundness;
    char smoothness;

    Color color;
};

struct Cursor_Data
{
    short x, y;
    short width, height;
    short life_time;
    bool visible;
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
        void Type(TextBox_Data *textbox);
        void Cursor(TextBox_Data *textbox);

        Font font;
        std::vector<TextBox_Data> text_boxes;
        Cursor_Data cursor;
        char key, event; 
        short hold_buffer, wait_buffer;
};