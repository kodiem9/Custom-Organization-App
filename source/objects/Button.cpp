#include <objects/Button.hpp>

Button::Button(int16_t x, int16_t y, int16_t width, int16_t height)
: x(x), y(y), width(width), height(height)
{
    texture_stretch = true;
    texture_exists = false;
}


// GLOBAL
void Button::Draw()
{
    Rectangle rec = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height)};
    if(outline_rounded) {
        DrawRectangleRounded(rec, outline_roundness, outline_segments, bg_color);
        p_DrawTexture();
        DrawRectangleRoundedLines(rec, outline_roundness, outline_segments, outline_thick, outline_color);
    }
    else {
        DrawRectangleRec(rec, bg_color);
        p_DrawTexture();
        DrawRectangleLinesEx(rec, outline_thick, outline_color);
    }
}

void Button::InitColor(Color bg, Color outline)
{
    bg_color = bg;
    outline_color = outline;
}

void Button::InitOutline(uint8_t thick, bool rounded, float roundess, uint8_t segments)
{
    outline_thick = thick;
    outline_rounded = rounded;
    outline_roundness = roundess;
    outline_segments = segments;
}

void Button::InitTexture(const char* texture_path)
{
    texture = LoadTexture(texture_path);
    if(IsTextureReady(texture)) {
        texture_exists = true;
        source = {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)};

        float texture_width, texture_height, mult_w, mult_h;
        mult_w = source.width * (static_cast<float>(width) / texture.width);
        mult_h = source.height * (static_cast<float>(height) / texture.height);

        if(texture_stretch) {
            texture_width = mult_w;
            texture_height = mult_h;
        }
        else {
            if(width > height) {
                texture_width = mult_h;
                texture_height = mult_h;
                offset_x = (width - texture_width) / 2;
                offset_y = 0;
            }
            else {
                texture_width = mult_w;
                texture_height = mult_w;
                offset_x = 0;
                offset_y = (height - texture_height) / 2;
            }
        }

        dest = {static_cast<float>(x + offset_x), static_cast<float>(y + offset_y), texture_width, texture_height};
    }
}

void Button::InitTextureStretching(bool stretch)
{
    texture_stretch = stretch;
}


// PRIVATE
void Button::p_DrawTexture()
{
    if(texture_exists) {
        DrawTexturePro(texture, source, dest, {0,0}, 0.0f, WHITE);
    }
}