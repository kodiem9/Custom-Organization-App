#pragma once
#include "include/Button.hpp"
#include <iostream>

class APP
{
    public:
        APP();
        void Draw();
        void Update();
    
    private:
        Button button;
};