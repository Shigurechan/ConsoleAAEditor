#include <iostream>
#include <Windows.h>


#include "Main_Screen.hpp"

#include "KeyInput.hpp"
#include "ScreenBuffer.hpp"

//コンストラクタ
Main_Screen::Main_Screen()
{
    /* コンポーネント　関係 */
    mText = new Debug_Log("Main_Screen.txt");   //デバッグ用　テキスト出力
    mWindow = new ScreenBuffer();               //画面描画
    mInput = new KeyInput();                    //キー入力


    Position.x = 0;
    Position.y = 3;

}



// キー入力
void Main_Screen::Input()
{
    mInput->getKeyUpdate();
    if (InsertKey == true) {
        // カーソルの操作
        if (mInput->getKeyDown(KeyCode::DOWN_KEY) && true)
        {
            Position.y++;
        }
        else if (mInput->getKeyDown(KeyCode::UP_KEY) && true)
        {
            Position.y--;

        }
        else if (mInput->getKeyDown(KeyCode::LEFT_KEY) && true)
        {
            Position.x--;

        }
        else if (mInput->getKeyDown(KeyCode::RIGHT_KEY) && true)
        {
            Position.x++;

        }
        //決定ボタン
        else if ((mInput->getKeyDown(KeyCode::SPACE_KEY) == true) && (EnterKey == false))
        {
            EnterKey = true;
        }

    }

    // Insertキーを押した場合
    else if (InsertKey == false)
    {
        if (mInput->getKeyDown(KeyCode::F1_KEY) == true)
        {
            mText->Write("Insert key　false \n");

            InsertKey = true;
        }

        mWindow->CursorPosition(17,0);
        mCharactor = getchar();
        InsertKey = true;

    }



    // 入力切り替え
    if ((mInput->getKeyDown(KeyCode::F1_KEY) == true))
    {
        mText->Write("Insert key\n");
        
        if(InsertKey == true)
        {
            mText->Write("Insert key　true \n");

            InsertKey = false;
        }
    }









    // ########################################################## 終了
    if (mInput->getKeyDown(KeyCode::ESC_KEY) && true)
    { 
        exit(0);
    }
    // ##########################################################
    mInput->ResetKey();
}



//更新
void Main_Screen::Update()
{
    Input();


    




}


// -------------------------- ループ ----------------------------------
void Main_Screen::Loop()
{
    while (true) 
    {
        Update();           //計算
        GenerateOutput();   //描画



        Sleep((DWORD)16.66);
    }
}
// --------------------------     ------------------------------------



//描画更新
void Main_Screen::GenerateOutput()
{
    if (EnterKey == true)
    {
        Buffer[Position.y][Position.x] = mCharactor;
        EnterKey = false;
    }

    if (InsertKey == false)
    {
        mWindow->Draw(0,0,"Input Charactor: ");

    }
    else
    {
        mWindow->Draw(0, 0, "Insert Mode ");

    }


    





    for (int i = 0; i <30; i++)
    {
        for (int j = 0; j < 30; j++)
        {    
            mWindow->DrawAA(j, i, "%c",Buffer[j][i]);
        }
    }
    
    if (InsertKey == true) {
        mWindow->CursorPosition(Position.x, Position.y);
    }
    mWindow->GenerateOutput();
}







//デストラクタ
Main_Screen::~Main_Screen()
{    
    delete mText;
    mText = nullptr;

    delete mWindow;
    mWindow = nullptr;


}


