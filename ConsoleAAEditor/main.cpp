#include <iostream>
#include <cstdio>
#include <vector>
#include <Windows.h>
#include "conio.h"

#include "Main_Screen.hpp"

// 計算
void Update()
{

}

// 描画
void GenerateOutput()
{

}

int main() {

    setlocale(LC_ALL, " "); //スケールを指定

    //メインループ
    // -----------------------------------------------------------
    class Main_Screen* mc = new Main_Screen();

    mc->Loop();
    // -----------------------------------------------------------







    delete mc;
    mc = nullptr;
  
    return 0;
}