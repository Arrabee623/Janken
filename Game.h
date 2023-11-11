#pragma once

#include "User.h"
#include "Cpu.h"
#include "Consts.h"
#include "Gnuplot.h"

#include <iostream>
#include <fstream>

using namespace std;

// ===========================
//	�Q�[���̃N���X
// ===========================

class Game
{
	User usr;	// �v���O�����̃��[�U
	Cpu com;	// �R���s���[�^
	int round = 0;	// ����킩��\��(0�X�^�[�g)

public:

	// �Q�[������(main�֐��ŌĂяo��)
	void play_game();

	// �v���O�����̐������s���֐�
	void instruct();

	// ���s�𔻒肷��
	int judge();

	// ���s�\��������
	void show_judge(int r);

	// ��̃��O�Ə��s�t�@�C���ɃG�N�X�|�[�g
	void export_log();

	// �O���t�̍쐬
	void draw_graph();
};