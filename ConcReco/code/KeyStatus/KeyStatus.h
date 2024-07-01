#pragma once
#include<unordered_map>
#include<memory>

constexpr int UNINPUT = 0x0001;     //未入力時
constexpr int NOWUNINPUT = 0x0002;  //未入力中
constexpr int ONINPUT = 0x0004;     //入力時
constexpr int NOWONINPUT = 0x0008;  //入力中

/// <summary>
/// 入力情報の管理
/// </summary>
class KeyStatus final
{
public:
    /// <summary>
    /// キー入力初期化
    /// </summary>
    static void InitKeyStatus();

    /// <summary>
    /// キー入力判定
    /// </summary>
    /// <param name="key">:対象キー</param>
    /// <param name="flag">:対象フラグ</param>
    /// <returns>一致:true|不一致:false</returns>
    static bool KeyStateDecision(int key, int flag);


    /// <summary>
    /// デストラクタ
    /// </summary>
    ~KeyStatus();

private:
    /// <summary>
    /// ステータス切り替え
    /// </summary>
    /// <param name="key">:対象キー</param>
    static void ChangeKeyState(int key);

    static std::unique_ptr<KeyStatus> keyStatus;        //自身の実体
    int inputState;                                     //入力ステータス
    std::unordered_map<int, int> keyData;               //キーデータ
};