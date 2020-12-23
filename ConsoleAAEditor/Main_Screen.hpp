#ifndef ___MAIN_SCREEN_HPP_
#define ___MAIN_SCREEN_HPP_

#include <iostream>

#include "KeyCode.hpp"
#include "KeyInput.hpp"

#include "Debug_Log.hpp"
#include "ScreenBuffer.hpp"


/*############################################
# ���C�����
##############################################*/

class Main_Screen
{
public:

    Main_Screen();    		//�R���X�g���N�^
    ~Main_Screen();    		//�f�X�g���N�^
    void Loop();            //���[�v
    void Update();		    //�v�Z
    void GenerateOutput();  //�`��
    
private:

    struct vec
    {
        int x;
        int y;
    };

    typedef struct vec Vector;


    /* �����o�֐� */
    void Input();           //�L�[����


    /* �R���|�[�l���g �֌W */
    KeyInput *mInput;       //�L�[����  
    Debug_Log *mText;       //�f�o�b�O�p�@�e�L�X�g�t�@�C���ɏ�������
    ScreenBuffer *mWindow;  //��ʕ`��

    /* �������� �֌W */
    Vector Position;    //�J�[�\�����W
    char Buffer[MAX_HEIGHT][MAX_WIDTH] = { 0 };
    char mCharactor = '@';    //�`�敶��







    /* �L�[���́@�֌W */
    bool EnterKey = false;
    bool InsertKey = true;


};



#endif
