#include "../include/TextBox.hpp"


TextBox::TextBox()
{
    Reset();
    font = LoadFontEx("fonts/JetBrainsMono.ttf", 50, 0, 256);
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
    temp_text_box.text.clear();
    temp_text_box.text.shrink_to_fit();
    temp_text_box.text.push_back("");
    temp_text_box.id = 0;
    temp_text_box.selected = false;
    temp_text_box.roundness = roundness;
    temp_text_box.smoothness = smoothness;
    temp_text_box.font_size = font_size;
    temp_text_box.color = GRAY;

    for(int i = 0; font_size * i <= height; i++) {
        temp_text_box.offset_y = (height - (font_size * i)) / 2;
    }

    text_boxes.push_back(temp_text_box);
}

void TextBox::Draw()
{
    for(TextBox_Data text_box: text_boxes) {
        DrawRectangleRounded(Rectangle{(float)text_box.x, (float)text_box.y, (float)text_box.width, (float)text_box.height}, text_box.roundness, text_box.smoothness, text_box.color);
        for(int i = 0; i < (int)text_box.text.size(); i++) {
            DrawTextEx(font, text_box.text[i].c_str(), Vector2{ (float)text_box.x + TEXT_BOX_OFFSET_X, (float)text_box.y + (text_box.font_size * i) + text_box.offset_y }, text_box.font_size, 1, BLACK);
        }
        if(text_box.selected && cursor.visible) DrawRectangle(cursor.x, cursor.y + text_box.offset_y, cursor.width, cursor.height, WHITE);
    }
}

void TextBox::Update()
{
    for(TextBox_Data &text_box: text_boxes) {

        if(utils::MouseOverlap(text_box.x, text_box.y, text_box.width, text_box.height)) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                text_box.selected = true;
                Cursor(text_box);
            }
        }
        else {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                text_box.selected = false;
                cursor.life_time = CURSOR_LIFE_TIME;
                cursor.visible = true;
                text_ptr = NULL;
            }
        }

        if(text_box.selected) {
            text_box.color = GREEN;
            Type(text_box);
        }
        else text_box.color = GRAY;

    }
}

void TextBox::Reset()
{
    text_boxes.clear();
    text_boxes.shrink_to_fit();
    
    hold_buffer = HOLD_BUFFER_SIZE;
    wait_buffer = 0;

    cursor.x = cursor.y = 0;
    cursor.width = 3;
    cursor.height = 40;
    cursor.life_time = CURSOR_LIFE_TIME;
    cursor.visible = true;

    text_ptr = NULL;
}


// * PRIVATE FUNCTIONS
void TextBox::Type(TextBox_Data &textbox)
{
    // DISCLAIMER, THE HOLD EVENT FOR NORMAL KEYS IS AUTOMATIC!
    key = GetCharPressed();
    if(text_ptr == NULL) text_ptr = &textbox.text[textbox.id];

    if(key != 0) {
        //checks if the text length is higher than the width of the text box, or not
        bool can_write = (MeasureTextEx(font, text_ptr->c_str(), textbox.font_size, 1).x + (textbox.font_size / 2) < textbox.width);
        bool can_new_line = (textbox.font_size * (textbox.id + 2) <= textbox.height);

        //adds a new line if the text box is high enough
        if(can_write == false) {

            if(can_new_line) {
                textbox.text.push_back(NewLine(text_ptr));
                textbox.id++;
                text_ptr = &textbox.text[textbox.id];
            }
        }

        if(can_new_line || (can_new_line == false && can_write)) {
            //this makes it so we cant write space when we write a new line
            if((key == ' ' && text_ptr->length() == 0) == false) {
                text_ptr->push_back(key);
                Cursor(textbox);
            }
        }
    }


    event = GetKeyPressed();
    //whenever a special key is pressed (ex. backspace)  -  when you hold it, it does the event faster
    //the wait buffer slows down the event time, so its not so fast
    //we are also checking if we are pressing backspace when the textbox is empty so the program doesn't break
    if(utils::BufferKeyPressed(KEY_BACKSPACE, hold_buffer) && (textbox.id == 0 && text_ptr->length() == 0) == false) {

        if(text_ptr->length() == 0 && textbox.id != 0) {
            textbox.text.pop_back();
            textbox.id--;
            textbox.text.shrink_to_fit();
            text_ptr = &textbox.text[textbox.id];
        }
        else {
            if(wait_buffer == 0) {
                wait_buffer = WAIT_BUFFER_SIZE;
                text_ptr->pop_back();
            } else wait_buffer--;
        }

        Cursor(textbox);
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

std::string TextBox::NewLine(std::string *text)
{
   std::string result;

   for(int i = text->length(); i > 0; i--) {
        if((*text)[i] == ' ') {
            result = text->substr(i+1, text->length()-i-1);
            (*text) = text->substr(0, i);
            break;
        }
   }

    if(result.length() == 0)
        return "";
    else
        return result;
}

void TextBox::Cursor(const TextBox_Data &textbox)
{
    cursor.x = textbox.x + MeasureTextEx(font, textbox.text[textbox.id].c_str(), textbox.font_size, 1).x + TEXT_BOX_OFFSET_X + 5;
    cursor.y = textbox.y + TEXT_BOX_OFFSET_Y + (textbox.font_size * textbox.id);
    cursor.life_time = CURSOR_LIFE_TIME;
    cursor.visible = true;
}