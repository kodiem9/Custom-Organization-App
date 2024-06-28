#include "../include/TextBox.hpp"


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

        if(text_box.selected)
            text_box.color = GREEN;
        else
            text_box.color = GRAY;

    }
}