#include "APP.hpp"

APP::APP()
{
    button.Init(GetScreenWidth() / 2 - 150, GetScreenHeight() - 150, 150, 150,
                0.3f, 50, FIRE_TEST_1);
    button.Init(GetScreenWidth() / 2 + 150, GetScreenHeight() - 150, 150, 150,
                0.3f, 50, FIRE_TEST_2);

    text_box.Init(GetScreenWidth() / 2, 200, 800, 50, 0.3f, 50, 50);
    text_box.Init(GetScreenWidth() / 2, 350, 800, 200, 0.3f, 50, 50);

    border.Init(GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth() / 1.5, GetScreenHeight() / 1.5, 0.3f, 50);
    
    font = LoadFontEx("fonts/JetBrainsMono.ttf", 100, 0, 256);

    CURRENT_SCENE = MAIN_MENU_SCENE;
}

APP::~APP()
{
    UnloadFont(font);
}


// * PUBLIC FUNCTIONS
void APP::Draw()
{
    switch(CURRENT_SCENE)
    {
        case MAIN_MENU_SCENE:
        {
            button.Draw();
            text_box.Draw();

            //Middle of the text is determined by the text width and screen width
            DrawTextEx(font, "Organization App", Vector2{GetScreenWidth() / 2 -
                        (MeasureTextEx(font, "Organization App", 100, 1).x) / 2, 30}, 100, 1, BLACK);
            break;
        }

        case DEBUG_SCENE:
        {
            border.Draw();
            break;
        }

        default: break;
    }
}

void APP::Update()
{
    if(IsKeyPressed(KEY_ZERO)) {
        if(CURRENT_SCENE == MAIN_MENU_SCENE)
            CURRENT_SCENE = DEBUG_SCENE;
        else
            CURRENT_SCENE = MAIN_MENU_SCENE;
    }
    
    switch(CURRENT_SCENE)
    {
        case MAIN_MENU_SCENE:
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
            break;
        }

        case DEBUG_SCENE:
        {
            break;
        }

        default: break;
    }
}