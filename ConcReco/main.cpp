#include<Dxlib.h>

/// <summary>
/// メイン
/// </summary>
/// <returns></returns>
int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ PSTR cmdline, _In_ int cmdshow)
{
    ChangeWindowMode(true);
    SetGraphMode(1920, 1080, 16);
    
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("ConcReco");

    SetOutApplicationLogValidFlag(false);

    if (DxLib_Init())
    {
        DebugBreak();
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    while (!ProcessMessage() && CheckHitKey(KEY_INPUT_ESCAPE))
    {

    }

    DxLib_End();

    //ソフトの終了
    return 0;
}