#pragma once
#include "UI/Border.hpp"
#include "UI/Button.hpp"
#include "UI/TextBox.hpp"

enum WINDOW_SCENES
{
    NULL_WINDOW,
    NEW_PROJECT_WINDOW
};

class WINDOW
{
    public:
        WINDOW();
        void Draw();
        void Update();
        void Fire(char scene);
        char Get();
    
    private:
        void Reset();

        Font font;
        Border border;
        Button button;
        TextBox text_box;
        char CURRENT_SCENE;
};