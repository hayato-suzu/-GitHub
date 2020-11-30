#include "DxLib.h"

typedef enum {
    eScene_Title,   //タイトル画面
    eScene_Menu,    //メニュー画面
    eScene_Game,    //ゲーム画面
    eScene_Config,  //設定画面
} eScene;

static int Scene = eScene_Menu;    //現在の画面(シーン)

//シーンを更新する
void UpdateScene() {
    DrawString(0, 20, "Aキーでタイトル画面、Gキーでゲーム画面、Cキーで設定、Mキーでメニュー画面になります。", GetColor(255, 255, 255));
    if (CheckHitKey(KEY_INPUT_A) != 0) {
        Scene = eScene_Title;
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) {
        Scene = eScene_Game;
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {
        Scene = eScene_Config;
    }
    if (CheckHitKey(KEY_INPUT_M) != 0) {
        Scene = eScene_Menu;
    }
}

//タイトル画面
void Title() {
    DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
}

//メニュー画面
void Menu() {
    DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
}

//ゲーム画面
void Game() {
    DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
}

//設定画面
void Config() {
    DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        switch (Scene) {//現在のシーンにあった処理をする

        case eScene_Title://現在のシーンがタイトルなら
            Title();//タイトル画面
            break;
        case eScene_Menu://現在のシーンがメニューなら
            Menu();//メニュー画面
            break;
        case eScene_Game://現在のシーンがゲームなら
            Game();//ゲーム画面
            break;
        case eScene_Config://現在のシーンが設定なら
            Config();//設定画面
            break;
        }

        UpdateScene();//シーンを更新する

    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}

//void fps() {
//    int i;
//    static int t = 0, ave = 0, f[60];
//
//    f[count % 60] = GetNowCount() - t;
//    t = GetNowCount();
//    if (count % 60 == 59) {
//        ave = 0;
//        for (i = 0; i < 60; i++)
//            ave += f[i];
//        ave /= 60;
//    }
//    if (ave != 0) {
//        DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1fFPS", 1000.0 / (double)ave);
//        DrawFormatString(0, 20, GetColor(255, 255, 255), "%dms", ave);
//    }
//    return;
//}