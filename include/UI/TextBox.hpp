#pragma once
#include "../Utils/Utils.hpp"
#include <vector>
#include <string>

#define HOLD_BUFFER_SIZE    30
#define WAIT_BUFFER_SIZE    1
#define CURSOR_LIFE_TIME    40
#define CURSOR_OFFSET_Y     5

struct TextBox_Properties
{
    float roundness;
    char smoothness;
    char font_size;
};

struct TextBox_Data
{
    short x, y, width, height;
    short offset_y, offset_x;
    std::vector<std::string> text;
    char id;
    bool selected;

    TextBox_Properties properties;
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
        void Init(short x, short y, short width, short height, TextBox_Properties properties);
        void Draw();
        void Update();
        void Reset();
    
    private:
        void Type(TextBox_Data &textbox);
        std::string NewLine(std::string *text);
        void Cursor(const TextBox_Data &textbox);
        void SetTextPointer(std::string *ptr);
        short TextWidthX(const char* text, char font_size);

        Font font;
        std::vector<TextBox_Data> text_boxes;
        Cursor_Data cursor;
        std::string *text_ptr;
        char key, event; 
        short hold_buffer, wait_buffer;
};