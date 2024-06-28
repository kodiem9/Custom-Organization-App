#include "APP.hpp"

APP::APP()
{
    button.Init(GetScreenWidth() / 2 - 200, GetScreenHeight() / 2, 200, 50,
                0.3f, 50, FIRE_TEST_1);
    button.Init(GetScreenWidth() / 2 + 200, GetScreenHeight() / 2, 200, 50,
                0.3f, 50, FIRE_TEST_2);
}


// * PUBLIC FUNCTIONS
void APP::Draw()
{
    button.Draw();
}

void APP::Update()
{
    button.Update();
    
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