#pragma once
#include <pch/PCH.hpp>

class Button
{
    public:
        Button(int16_t x, int16_t y, int16_t width, int16_t height);
        void Draw();

        void InitColor(Color bg, Color outline);
        void InitOutline(uint8_t thick, bool rounded = false, float roundess = 0.0f, uint8_t segments = 0);
        void InitTexture(const char* texture_path);
        void InitTextureStretching(bool stretch);


    private:
        void p_DrawTexture();

        // Outline attributes
        Color outline_color;
        float outline_roundness;
        int8_t outline_thick, outline_segments;
        bool outline_rounded;

        // Texture attributes
        bool texture_stretch, texture_exists;
        Rectangle source;
        Rectangle dest;
        int16_t offset_x, offset_y;

        // Other attributes
        Color bg_color;
        Texture2D texture;
        int16_t x, y, width, height;
};