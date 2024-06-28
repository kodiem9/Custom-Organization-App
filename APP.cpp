#include "APP.hpp"

APP::APP()
{
    button.Init(((float)GetScreenWidth() / 2) - 100, (float)GetScreenHeight() / 2, 100, 100);
    button.Init(((float)GetScreenWidth() / 2) + 100, (float)GetScreenHeight() / 2, 100, 100);
}


// * PUBLIC FUNCTIONS
void APP::Draw()
{
    button.Draw();
}

void APP::Update()
{
    button.Update();
}