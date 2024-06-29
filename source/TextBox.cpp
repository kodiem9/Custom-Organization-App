#include "../include/TextBox.hpp"


TextBox::TextBox()
{
    font = LoadFontEx("fonts/JetBrainsMono.ttf", 50, 0, 256);
    hold_buffer = HOLD_BUFFER_SIZE;
    wait_buffer = 0;

    cursor.x = cursor.y = 0;
    cursor.width = 3;
    cursor.height = 40;
    cursor.life_time = CURSOR_LIFE_TIME;
    cursor.visible = true;
}

TextBox::~TextBox()
{
    UnloadFont(font);
}


// * PUBLIC FUNCTIONS
void TextBox::Init(short x, short y, short width, short height, float roundness, char smoothness, short font_size)
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
    temp_text_box.font_size = font_size;
    temp_text_box.color = GRAY;

    text_boxes.push_back(temp_text_box);
}

void TextBox::Draw()
{
    for(TextBox_Data text_box: text_boxes) {
        DrawRectangleRounded(Rectangle{(float)text_box.x, (float)text_box.y, (float)text_box.width, (float)text_box.height}, text_box.roundness, text_box.smoothness, text_box.color);
        DrawTextEx(font, text_box.text.c_str(), Vector2{ (float)text_box.x + TEXT_BOX_OFFSET_X, (float)text_box.y }, text_box.font_size, 1, BLACK);
        if(text_box.selected && cursor.visible) DrawRectangle(cursor.x, cursor.y, cursor.width, cursor.height, WHITE);
    }
}

void TextBox::Update()
{
    for(TextBox_Data &text_box: text_boxes) {

        if(utils::MouseOverlap(text_box.x, text_box.y, text_box.width, text_box.height)) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                text_box.selected = true;
                Cursor(&text_box);
            }
        }
        else {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                text_box.selected = false;
                cursor.life_time = CURSOR_LIFE_TIME;
                cursor.visible = true;
            }
        }

        if(text_box.selected) {
            text_box.color = GREEN;
            Type(&text_box);
        }
        else text_box.color = GRAY;

    }
}


// * PRIVATE FUNCTIONS
void TextBox::Type(TextBox_Data *textbox)
{
    // DISCLAIMER, THE HOLD EVENT FOR NORMAL KEYS IS AUTOMATIC!
    key = GetCharPressed();
    
    if(key != 0) {
        //checks if the text length is higher than the width of the text box, or not
        if(MeasureTextEx(font, textbox->text.c_str(), textbox->font_size, 1).x + (textbox->font_size / 2) < textbox->width) {
            textbox->text += key;
            Cursor(textbox);
        }
    }


    event = GetKeyPressed();
    //whenever a special key is pressed (ex. backspace)  -  when you hold it, it does the event faster
    //the wait buffer slows down the event time, so its not so fast
    if(utils::BufferKeyPressed(KEY_BACKSPACE, hold_buffer)) {

        if(wait_buffer == 0) {
            wait_buffer = WAIT_BUFFER_SIZE;
            textbox->text = textbox->text.substr(0, textbox->text.length() - 1);
            Cursor(textbox);
        } else wait_buffer--;

    }
    
    if(IsKeyDown(KEY_BACKSPACE)) {
        if(hold_buffer > 0) hold_buffer--;
    }

    if(IsKeyReleased(KEY_BACKSPACE)) {
        hold_buffer = HOLD_BUFFER_SIZE;
        wait_buffer = 0;
    }

    //cursor "animation"/flickering when not typing
    cursor.life_time--;
    if(cursor.life_time < 1) {
        cursor.life_time = CURSOR_LIFE_TIME;
        cursor.visible = !cursor.visible;
    }
}

void TextBox::Cursor(TextBox_Data *textbox)
{
    cursor.x = textbox->x + MeasureTextEx(font, textbox->text.c_str(), textbox->font_size, 1).x + TEXT_BOX_OFFSET_X + 5;
    cursor.y = textbox->y + 5;
    cursor.life_time = CURSOR_LIFE_TIME;
    cursor.visible = true;
}