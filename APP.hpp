#pragma once
#include "include/Button.hpp"
#include "include/TextBox.hpp"
#include <iostream>

class APP
{
    public:
        APP();
        void Draw();
        void Update();
    
    private:
        Button button;
        TextBox text_box;
        Font font;
};