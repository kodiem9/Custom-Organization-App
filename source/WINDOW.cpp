#include "../include/WINDOW.hpp"


WINDOW::WINDOW()
{
    font = LoadFontEx("assets/fonts/JetBrainsMono.ttf", 70, 0, 256);
    CURRENT_SCENE = NULL_WINDOW;
}


// * PUBLIC FUNCTIONS
void WINDOW::Draw()
{
    switch(CURRENT_SCENE)
    {
        case NEW_PROJECT_WINDOW:
        {
            border.Draw();
            DrawTextEx(font, "Project name", Vector2{GetScreenWidth() / 2 -
                MeasureTextEx(font, "Project name", 70, 1).x / 2, (float)GetScreenHeight() / 2 - 230}, 70, 1, WHITE);
            text_box.Draw();
            button.Draw();
            break;
        }


        default: break;
    }
}

void WINDOW::Update()
{
    switch(CURRENT_SCENE)
    {
        case NEW_PROJECT_WINDOW:
        {
            text_box.Update();
            button.Update();

            if(button.FireEvent() == FIRE_EXIT_NEW_PROJECT_WINDOW) {
                Fire(NULL_WINDOW);
            }
            break;
        }


        default: break;
    }
}

void WINDOW::Fire(char scene)
{
    Reset();
    CURRENT_SCENE = scene;

    switch(scene)
    {
        case NEW_PROJECT_WINDOW:
        {
            short mid_screen_x = GetScreenWidth() / 2;
            short mid_screen_y = GetScreenHeight() / 2;
            border.Init(mid_screen_x, mid_screen_y, mid_screen_x * 1.33, mid_screen_y * 1.33, Border_Properties{0.1f, 20});
            text_box.Init(mid_screen_x, mid_screen_y - 120, 600, 50, TextBox_Properties{0.3f, 50, 50});

            button.Init(mid_screen_x - 380, mid_screen_y - 200, 50, 50, Button_Properties{0.3f, 50}, FIRE_EXIT_NEW_PROJECT_WINDOW);
            button.Init(mid_screen_x, mid_screen_y + 190,  300, 50, Button_Properties{0.3f, 50}, FIRE_CREATE_PROJECT);
            break;
        }


        default: break;
    }
}

char WINDOW::Get() { return CURRENT_SCENE; }


// * PRIVATE FUNCTIONS
void WINDOW::Reset()
{
    border.Reset();
    text_box.Reset();
    button.Reset();
}