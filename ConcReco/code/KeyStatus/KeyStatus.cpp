#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::keyStatus = nullptr;

void KeyStatus::InitKeyStatus()
{
    //自身の中身が空だったらインスタンス生成
    if (!keyStatus) {
        keyStatus.reset(new KeyStatus);
    }
}

bool KeyStatus::KeyStateDecision(int key, int flag)
{
    //キーが格納されていなかったら保存、されていたらステータス切り替え
    auto findData = keyStatus->keyData.find(key);
    if (findData == keyStatus->keyData.end()) {
        keyStatus->keyData.emplace(key, UNINPUT);
    }
    else {
        ChangeKeyState(key);
    }

    //判定結果を返す
    if (keyStatus->keyData[key] & flag) {
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key)
{
    int& state = keyStatus->keyData[key];

    //ステータスの切り替えをする
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
    //データの中身があるなら削除
    if (keyData.size() > 0) {
        keyData.clear();
    }
}