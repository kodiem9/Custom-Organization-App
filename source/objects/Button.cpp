#include <objects/Button.hpp>

Button::Button(int16_t x, int16_t y, int16_t width, int16_t height)
: x(x), y(y), width(width), height(height)
{
    texture.stretch = true;
    texture.valid = false;
    stop = false;
    clicked = false;
    state = 0;
    brightness = 30;
    id = amount;
    amount++;
}


// GLOBAL
void Button::Draw()
{
    Rectangle rec = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height)};
    if(outline.rounded) {
        DrawRectangleRounded(rec, outline.roundess, outline.segments, color);
        p_DrawTexture();
        DrawRectangleRoundedLines(rec, outline.roundess, outline.segments, outline.thick, outline.color);
    }
    else {
        DrawRectangleRec(rec, color);
        p_DrawTexture();
        DrawRectangleLinesEx(rec, outline.thick, outline.color);
    }
    // if the state of the button is being hovered or clicked
    if(state > 0) {
        DrawRectangleRec(rec, (state == 1) ? Color{255, 255, 255, brightness} : Color{0, 0, 0, brightness});
    }
}

void Button::Update()
{
#pragma region MOUSE
    if(GetMouseX() > x && GetMouseX() < x + width && GetMouseY() > y && GetMouseY() < y + height) {
        if(IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT)) {
            if(!stop) {
                clicked = true;
                state = 2;
            }
        }
        else {
            clicked = false;
            stop = false;
            state = 1;
        }
    }
    else {
        state = 0;
    }
#pragma endregion
}

void Button::i_Color(Color bg, Color outline)
{
    bg_color = bg;
    color = bg;
    this->outline.color = outline;
}

void Button::i_Outline(uint8_t thick, bool rounded, float roundess, uint8_t segments)
{
    outline.thick = thick;
    outline.rounded = rounded;
    outline.roundess = roundess;
    outline.segments = segments;
}

void Button::i_Texture(const char* texture_path)
{
    texture.texture = LoadTexture(texture_path);

    if(IsTextureReady(texture.texture)) {
        texture.valid = true;
        texture.source = {0, 0, static_cast<float>(texture.texture.width), static_cast<float>(texture.texture.height)};

        float texture_width, texture_height, mult_w, mult_h;
        mult_w = texture.source.width * (static_cast<float>(width) / texture.texture.width);
        mult_h = texture.source.height * (static_cast<float>(height) / texture.texture.height);

        if(texture.stretch) {
            texture_width = mult_w;
            texture_height = mult_h;
            texture.offset_y = 0;
            texture.offset_x = 0;
        }
        else {
            if(width > height) {
                texture_width = mult_h;
                texture_height = mult_h;
                texture.offset_x = (width - texture_width) / 2;
                texture.offset_y = 0;
            }
            else {
                texture_width = mult_w;
                texture_height = mult_w;
                texture.offset_x = 0;
                texture.offset_y = (height - texture_height) / 2;
            }
        }

        texture.dest = {static_cast<float>(x + texture.offset_x), static_cast<float>(y + texture.offset_y), texture_width, texture_height};
    }
}

void Button::i_TextureStretching(bool stretch)
{
    texture.stretch = stretch;
}

void Button::i_ID(uint8_t id)
{
    this->id = id;
}

uint8_t Button::f_GetID()
{
    return id;
}

bool Button::f_IsClicked()
{
    return clicked;
}

void Button::f_Break()
{
    clicked = false;
    stop = true;
}


// PRIVATE
void Button::p_DrawTexture()
{
    if(texture.valid) {
        DrawTexturePro(texture.texture, texture.source, texture.dest, {0,0}, 0.0f, WHITE);
    }
}