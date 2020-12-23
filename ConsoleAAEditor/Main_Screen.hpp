#ifndef ___MAIN_SCREEN_HPP_
#define ___MAIN_SCREEN_HPP_

#include <iostream>

#include "KeyCode.hpp"
#include "KeyInput.hpp"

#include "Debug_Log.hpp"
#include "ScreenBuffer.hpp"


/*############################################
# メイン画面
##############################################*/

class Main_Screen
{
public:

    Main_Screen();    		//コンストラクタ
    ~Main_Screen();    		//デストラクタ
    void Loop();            //ループ
    void Update();		    //計算
    void GenerateOutput();  //描画
    
private:

    struct vec
    {
        int x;
        int y;
    };

    typedef struct vec Vector;


    /* メンバ関数 */
    void Input();           //キー入力


    /* コンポーネント 関係 */
    KeyInput *mInput;       //キー入力  
    Debug_Log *mText;       //デバッグ用　テキストファイルに書き込む
    ScreenBuffer *mWindow;  //画面描画

    /* 文字入力 関係 */
    Vector Position;    //カーソル座標
    char Buffer[MAX_HEIGHT][MAX_WIDTH] = { 0 };
    char mCharactor = '@';    //描画文字







    /* キー入力　関係 */
    bool EnterKey = false;
    bool InsertKey = true;


};



#endif
