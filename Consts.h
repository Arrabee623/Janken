#pragma once

// ===========================
//	�Q�[���Ŏg���萔�܂Ƃ�
// ===========================

#define MaxOfGames 100	// 1��̃v���O�����ōs����ő�Q�[����

class Consts
{
public:
	// ���s��\���萔
	static const int Win = 1;	// ����
	static const int Lose = 2;	// ����
	static const int Draw = 3;	// ��������

	// �W�����P���ŏo�����\��
	static const int Rock = 1;	// �O�[
	static const int Scissors = 2;	// �`���L
	static const int Paper = 3;	// �p�[

	// �Q�[���p���Ɋւ���萔
	static const int Cont = 1;	// ������
	static const int Exit = 2;	// ��߂�
};