#include <App.hpp>

App::App()
{
#pragma region BUTTONS
    Button btn1(100, 100, 200, 100);
    btn1.i_Color(WHITE, BLACK);
    btn1.i_Outline(3);
    btn1.i_TextureStretching(true);
    btn1.i_Texture("assets/images/supametboi.png");
    buttons.push_back(btn1);

    Button btn2(300, 300, 200, 100);
    btn2.i_Color(WHITE, BLACK);
    btn2.i_Outline(3);
    btn2.i_TextureStretching(false);
    btn2.i_Texture("assets/images/supametboi.png");
    buttons.push_back(btn2);

    Button btn3(500, 500, 100, 200);
    btn3.i_Color(WHITE, BLACK);
    btn3.i_Outline(3);
    btn3.i_TextureStretching(false);
    btn3.i_Texture("assets/images/supametboi.png");
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

    for(Button &btn: buttons) {
        btn.Update();
        if(btn.f_IsClicked()) {
            switch(btn.f_GetID())
            {
                case 0: {
                    printf("Yay 0!\n");
                    btn.f_Break();
                    break;
                }
                case 1: {
                    printf("Yay 1!\n");
                    btn.f_Break();
                    break;
                }
                case 2: {
                    printf("Yay 2!\n");
                    btn.f_Break();
                    break;
                }
                default: break;
            }
        }
    }
}