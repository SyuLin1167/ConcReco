#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::keyStatus = nullptr;

void KeyStatus::InitKeyStatus()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!keyStatus) {
        keyStatus.reset(new KeyStatus);
    }
}

bool KeyStatus::KeyStateDecision(int key, int flag)
{
    //�L�[���i�[����Ă��Ȃ�������ۑ��A����Ă�����X�e�[�^�X�؂�ւ�
    auto findData = keyStatus->keyData.find(key);
    if (findData == keyStatus->keyData.end()) {
        keyStatus->keyData.emplace(key, UNINPUT);
    }
    else {
        ChangeKeyState(key);
    }

    //���茋�ʂ�Ԃ�
    if (keyStatus->keyData[key] & flag) {
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key)
{
    int& state = keyStatus->keyData[key];

    //�X�e�[�^�X�̐؂�ւ�������
    if (CheckHitKey(key)) {
        if (state & (UNINPUT | NOWUNINPUT)) {
            state = ONINPUT;
            return;
        }
        state = NOWONINPUT;
    }
    else {
        if (state & (ONINPUT | NOWONINPUT)) {
            state = UNINPUT;
            return;
        }
        state = NOWUNINPUT;
    }
}

KeyStatus::~KeyStatus()
{
    //�f�[�^�̒��g������Ȃ�폜
    if (keyData.size() > 0) {
        keyData.clear();
    }
}