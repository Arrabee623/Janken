#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

class Gnuplot {
	FILE* gnuplot;
	float deltTime = 0.0;
	int playTime = 0;
public:
	Gnuplot();	// Gnuplot�̋N��
	~Gnuplot();	// Gnuplot�̃t�@�C���f�B�X�N���v�^�̔j��

	void SetXRange(int lower, int higher);	// x�͈̔͂�����
	void SetYRange(int lower, int higher);	// y�͈̔͂�����
	void Plot(const char* str);		// ���R�Ȏw��ł̃v���b�g

	void PlotBegin();	// ���W�f�[�^�𑗂鏀��
	void PlotBegin(const char* str);	// ���W�f�[�^�𑗂鏀��
	void AddPlotData(float x, float y);	// ���W�f�[�^�𑗂�
	void PlotEnd();	// ���W�v���b�g�̏I��

	void SetTitle(const char* title);	// �^�C�g���̐ݒ�
	void SetXLabel(const char* label);	// x���̃��x���̐ݒ�
	void SetYLabel(const char* label);	// y���̃��x���̐ݒ�

	void SetTerm(const char* term, int number);	// ???

	void Plot(const char* fileName, const char* str);	// �t�@�C������̃f�[�^���v���b�g
	void AddPlot(const char* fileName, const char* str);	// �t�@�C������̃f�[�^��ǉ��v���b�g

	void SetAnimation(float dTime, float sec);	// �A�j���[�V�����̏���
	void PlotAnimation(const char* fileName, const char* str);	// �v���b�g
	void AddAnimation(const char* fileName, const char* str);	// �ǉ��v���b�g
	void Pause();	// ???
	void Pause(float dTime);	// �����ꎞ��~
	void EndAnimation();	// �A�j���[�V�����@�\�̏I��

	void PlotBar(const char* fileName, int max);	// �_�O���t�̕\��
};