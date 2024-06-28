#include "../include/TextBox.hpp"


TextBox::TextBox()
{
    font = LoadFontEx("fonts/JetBrainsMono.ttf", 200, 0, 256);
    hold_buffer = HOLD_BUFFER_SIZE;
    wait_buffer = 0;
}

TextBox::~TextBox()
{
    UnloadFont(font);
}


// * PUBLIC FUNCTIONS
void TextBox::Init(short x, short y, short width, short height, float roundness, char smoothness)
{
    TextBox_Data temp_text_box;

    temp_text_box.width = width;
    temp_text_box.height = height;
    temp_text_box.x = x - width / 2;
    temp_text_box.y = y - height / 2;
    temp_text_box.text = "";
    temp_text_box.selected = false;
    temp_text_box.roundness = roundness;
    temp_text_box.smoothness = smoothness;
    temp_text_box.color = GRAY;

    text_boxes.push_back(temp_text_box);
}

void TextBox::Draw()
{
    for(TextBox_Data text_box: text_boxes) {
        DrawRectangleRounded(Rectangle{(float)text_box.x, (float)text_box.y, (float)text_box.width, (float)text_box.height}, text_box.roundness, text_box.smoothness, text_box.color);
        DrawTextEx(font, text_box.text.c_str(), Vector2{ (float)text_box.x, (float)text_box.y }, 50, 1, BLACK);
    }
}

void TextBox::Update()
{
    for(TextBox_Data &text_box: text_boxes) {

        if(utils::MouseOverlap(text_box.x, text_box.y, text_box.width, text_box.height)) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                text_box.selected = true;
            }
        }
        else {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                text_box.selected = false;
            }
        }

        if(text_box.selected) {
            text_box.color = GREEN;
            Type(&text_box.text, text_box.width, text_box.height);
        }
        else text_box.color = GRAY;

    }
}

void TextBox::Type(std::string *text, const short width, const short height)
{
    // DISCLAIMER, THE HOLD EVENT FOR NORMAL KEYS IS AUTOMATIC!
    key = GetCharPressed();
    
    if(key != 0)
        //checks if the text length is higher than the width of the text box, or not
        if((MeasureTextEx(font, text->c_str()-1, height, 1).x) < width)
            (*text) += key;


    event = GetKeyPressed();
    //whenever a special key is pressed (ex. backspace)  -  when you hold it, it does the event faster
    //the wait buffer slows down the event time, so its not so fast
    if(utils::BufferKeyPressed(KEY_BACKSPACE, hold_buffer)) {

        if(wait_buffer == 0) {
            wait_buffer = WAIT_BUFFER_SIZE;
            (*text) = text->substr(0, text->length() - 1);
        } else wait_buffer--;

    }
    
    if(IsKeyDown(KEY_BACKSPACE)) {
        if(hold_buffer > 0) hold_buffer--;
    }

    if(IsKeyReleased(KEY_BACKSPACE)) {
        hold_buffer = HOLD_BUFFER_SIZE;
        wait_buffer = 0;
    }
}