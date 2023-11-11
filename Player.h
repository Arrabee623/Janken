#pragma once

#include "Consts.h"
#include <iostream>

using namespace std;

// =========================
//	�v���C���[�N���X
// =========================

class Player
{
protected:
	// protected�����o
	int myhand = 0;		// �I�񂾎�
	int hands_log[MaxOfGames] = {0};	// ����܂ŏo������̋L�^

public:
	// ��̃Q�b�^(���l�f�[�^�ŕԂ�)
	int get_myhand();

	// �}���q�I�[�o�[���[�h(��̃O���t�B�J��?�ȕ\��)
	friend ostream& operator<< (ostream& stream, Player ob);

	// �o��������L�^����
	void write_log(int round);

	// ���O��W���o��(�f�o�b�O�p)
	void show_log();

	// ���O�̃Q�b�^
	int* get_hands_log();
};