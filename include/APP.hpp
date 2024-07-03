#pragma once
#include "WINDOW.hpp"
#include "UI/Button.hpp"
#include "UI/TextBox.hpp"
#include "UI/Border.hpp"
#include <iostream>

#define TRANSPARENT Color{0, 0, 0, 100}

enum APP_SCENES
{
    MAIN_MENU_SCENE,
    DEBUG_SCENE
};

class APP
{
    public:
        APP();
        ~APP();
        void Draw();
        void Update();
    
    private:
        void Init(char scene);
        void Reset();

        WINDOW window;
        Button button;
        TextBox text_box;
        Border border;
        Font font;
        char CURRENT_SCENE;
};