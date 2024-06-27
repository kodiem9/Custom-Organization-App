#pragma once
#include "include/Button.hpp"
#include <vector>

class APP
{
    public:
        APP();
        void Draw();
        void Update();
    
    private:
        Button button;
};