#pragma once
#include <pch/PCH.hpp>

class Button
{
    public:
        Button(int16_t x, int16_t y, int16_t width, int16_t height);
        void Draw();
        void Update();

        void i_Color(Color bg, Color outline);
        void i_Outline(uint8_t thick, bool rounded = false, float roundess = 0.0f, uint8_t segments = 0);
        void i_Texture(const char* texture_path);
        void i_TextureStretching(bool stretch);
        void i_ID(uint8_t id);
        uint8_t f_GetID();
        bool f_IsClicked();
        void f_Break();

    private:
        void p_DrawTexture();

        // Outline attributes
        struct Outline
        {
            Color color;
            float roundess;
            int8_t thick, segments;
            bool rounded;
        };

        // Texture attributes
        struct Texture
        {
            bool stretch, valid;
            Texture2D texture;
            Rectangle source;
            Rectangle dest;
            int16_t offset_x, offset_y;
        };

        Outline outline;
        Texture texture;

        Color bg_color, color;
        int16_t x, y, width, height;
        uint8_t brightness, id;
        inline static uint8_t amount;
        int8_t state;
        bool clicked, stop;
};