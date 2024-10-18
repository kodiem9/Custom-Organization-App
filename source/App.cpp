#include <App.hpp>

App::App()
{
    #pragma region BUTTONS

        Button btn1(100, 100, 200, 100);
        btn1.InitColor(WHITE, BLACK);
        btn1.InitOutline(3);
        btn1.InitTextureStretching(true);
        btn1.InitTexture("assets/images/supametboi.png");
        buttons.push_back(btn1);

        Button btn2(300, 300, 200, 100);
        btn2.InitColor(WHITE, BLACK);
        btn2.InitOutline(3);
        btn2.InitTextureStretching(false);
        btn2.InitTexture("assets/images/supametboi.png");
        buttons.push_back(btn2);

        Button btn3(500, 500, 100, 200);
        btn3.InitColor(WHITE, BLACK);
        btn3.InitOutline(3);
        btn3.InitTextureStretching(false);
        btn3.InitTexture("assets/images/supametboi.png");
        buttons.push_back(btn3);

    #pragma endregion
}

void App::Draw()
{
    for(Button &btn: buttons) {
        btn.Draw();
    }
}

void App::Update()
{
    if(IsKeyPressed(KeyboardKey::KEY_F)) {
        ToggleBorderlessWindowed();
    }
}