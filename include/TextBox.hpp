#pragma once
#include "../raylib/raylib.h"
#include "Utils.hpp"
#include <vector>
#include <string>
#include <iostream>

#define HOLD_BUFFER_SIZE    30
#define WAIT_BUFFER_SIZE    1
#define CURSOR_LIFE_TIME    40
#define TEXT_BOX_OFFSET_X   10
#define TEXT_BOX_OFFSET_Y   5

struct TextBox_Data
{
    short x, y, width, height;
    std::vector<std::string> text;
    char id;

    bool selected;

    float roundness;
    char smoothness;
    char font_size;

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
        void Init(short x, short y, short width, short height, float roundess, char smoothness, short font_size);
        void Draw();
        void Update();
        void Reset();
    
    private:
        void Type(TextBox_Data *textbox);
        std::string NewLine(std::string *text);
        void Cursor(TextBox_Data *textbox);
        void SetTextPointer(std::string *ptr);

        Font font;
        std::vector<TextBox_Data> text_boxes;
        Cursor_Data cursor;
        std::string *text_ptr;
        char key, event; 
        short hold_buffer, wait_buffer;
};