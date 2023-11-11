#pragma once

#include "Player.h"
using namespace std;

// =========================================
//	���[�U�N���X(�v���C���[�N���X���p��)
// =========================================

class User : public Player
{
	int num_win = 0;	// ������
	int num_lose = 0;	// ������
	int num_draw = 0;	// ����������

public:

	// �����͂���֐�
	void input_hand();

	// �p�����邩�ǂ��������
	int input_cont();

	// ���ʂ̋L�^
	void write_result(int r);

	// �L�^�̕W���o��(�f�o�b�O�p)
	void show_result();
	
	// �L�^�̃Q�b�^(Consts��`��WinLoseDraw�Ŏw�肵�����m��Ԃ�)
	int get_result(int category);
};