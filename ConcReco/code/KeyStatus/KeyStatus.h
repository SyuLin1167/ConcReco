#pragma once
#include<unordered_map>
#include<memory>

constexpr int UNINPUT = 0x0001;     //�����͎�
constexpr int NOWUNINPUT = 0x0002;  //�����͒�
constexpr int ONINPUT = 0x0004;     //���͎�
constexpr int NOWONINPUT = 0x0008;  //���͒�

/// <summary>
/// ���͏��̊Ǘ�
/// </summary>
class KeyStatus final
{
public:
    /// <summary>
    /// �L�[���͏�����
    /// </summary>
    static void InitKeyStatus();

    /// <summary>
    /// �L�[���͔���
    /// </summary>
    /// <param name="key">:�ΏۃL�[</param>
    /// <param name="flag">:�Ώۃt���O</param>
    /// <returns>��v:true|�s��v:false</returns>
    static bool KeyStateDecision(int key, int flag);


    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~KeyStatus();

private:
    /// <summary>
    /// �X�e�[�^�X�؂�ւ�
    /// </summary>
    /// <param name="key">:�ΏۃL�[</param>
    static void ChangeKeyState(int key);

    static std::unique_ptr<KeyStatus> keyStatus;        //���g�̎���
    int inputState;                                     //���̓X�e�[�^�X
    std::unordered_map<int, int> keyData;               //�L�[�f�[�^
};