#include "../include/APP.hpp"

APP::APP()
{    
    font = LoadFontEx("assets/fonts/JetBrainsMono.ttf", 100, 0, 256);

    CURRENT_SCENE = DEBUG_SCENE;

    Init(CURRENT_SCENE);
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
            text_box.Draw();
            break;
        }
    }

    window.Draw();
}

void APP::Update()
{
    if(window.Get() != NEW_PROJECT_WINDOW) {
        if(IsKeyPressed(KEY_ZERO)) {
            if(CURRENT_SCENE == MAIN_MENU_SCENE)
                CURRENT_SCENE = DEBUG_SCENE;
            else
                CURRENT_SCENE = MAIN_MENU_SCENE;
            
            Reset();
            Init(CURRENT_SCENE);
        }
    }

    
    switch(CURRENT_SCENE)
    {
        case MAIN_MENU_SCENE:
        {
            if(window.Get() != NEW_PROJECT_WINDOW) {
                button.Update();
                text_box.Update();
            }

            switch(button.FireEvent())
            {
                case FIRE_NEW_PROJECT_WINDOW:
                    window.Fire(NEW_PROJECT_WINDOW);
                    break;
                
                default: break;
            }
            break;
        }


        case DEBUG_SCENE:
        {
            text_box.Update();
            break;
        }
    }
    
    window.Update();
}


// * PRIVATE FUNCTIONS
void APP::Init(char scene)
{
    switch(scene)
    {
        case MAIN_MENU_SCENE:
        {
            button.Init(GetScreenWidth() / 2 - 150, GetScreenHeight() - 150, 150, 150,
                        Button_Properties{0.3f, 50}, FIRE_NEW_PROJECT_WINDOW);
            button.Init(GetScreenWidth() / 2 + 150, GetScreenHeight() - 150, 150, 150,
                        Button_Properties{0.3f, 50}, FIRE_NULL);

            text_box.Init(GetScreenWidth() / 2, 200, 800, 50, TextBox_Properties{0.3f, 50, 50});
            text_box.Init(GetScreenWidth() / 2, 350, 800, 200, TextBox_Properties{0.3f, 50, 50});
            break;
        }


        case DEBUG_SCENE:
        {
            text_box.Init(GetScreenWidth() / 2, 100, 800, 50, TextBox_Properties{0.3f, 50, 50});
            text_box.Init(GetScreenWidth() / 2, 300, 800, 200, TextBox_Properties{0.3f, 50, 50});
            break;
        }
    }
}

void APP::Reset()
{
    button.Reset();
    text_box.Reset();
    border.Reset();
}