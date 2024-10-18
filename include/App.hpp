#pragma once
#include <objects/Button.hpp>

class App
{
    public:
        App();
        void Draw();
        void Update();
    
    private:
        std::vector<Button> buttons;
};