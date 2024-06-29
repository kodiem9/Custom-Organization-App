#pragma once
#include "include/Button.hpp"
#include "include/TextBox.hpp"
#include "include/Border.hpp"
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
        Button button;
        TextBox text_box;
        Border border;
        Font font;
        char CURRENT_SCENE;
};