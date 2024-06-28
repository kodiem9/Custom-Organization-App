#include "APP.hpp"

APP::APP()
{
    button.Init(GetScreenWidth() / 2 - 150, GetScreenHeight() - 150, 150, 150,
                0.3f, 50, FIRE_TEST_1);
    button.Init(GetScreenWidth() / 2 + 150, GetScreenHeight() - 150, 150, 150,
                0.3f, 50, FIRE_TEST_2);
    text_box.Init(GetScreenWidth() / 2, 200, 800, 50, 0.3f, 50);
    text_box.Init(GetScreenWidth() / 2, 300, 800, 50, 0.3f, 50);
    
    font = LoadFontEx("fonts/JetBrainsMono.ttf", 200, 0, 256);
}

APP::~APP()
{
    UnloadFont(font);
}


// * PUBLIC FUNCTIONS
void APP::Draw()
{
    button.Draw();
    text_box.Draw();

    //Middle of the text is determined by the text width and screen width
    DrawTextEx(font, "Organization App", Vector2{GetScreenWidth() / 2 -
                (MeasureTextEx(font, "Organization App", 100, 1).x) / 2, 30}, 100, 1, BLACK);
    
    /*
    DrawTextEx(font, TextFormat("%f", MeasureTextEx(font, "a", 100, 1).x), Vector2{100, 100}, 100, 1, BLACK);
    DrawTextEx(font, TextFormat("%f", MeasureTextEx(font, "ab", 100, 1).x), Vector2{100, 200}, 100, 1, BLACK);
    DrawTextEx(font, TextFormat("%f", MeasureTextEx(font, "abc", 100, 1).x), Vector2{100, 300}, 100, 1, BLACK);
    45 91 137
    */
}

void APP::Update()
{
    button.Update();
    text_box.Update();

    switch(button.FireEvent())
    {
        case FIRE_TEST_1:
            std::cout << "Test #1" << std::endl;
            break;
        case FIRE_TEST_2:
            std::cout << "Test #2" << std::endl;
            break;
        default:
            break;
    }
}