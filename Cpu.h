#pragma once

#include "Consts.h"
#include "Player.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// =====================================
//	CPU�N���X(�v���C���[�N���X���p��)
// =====================================

class Cpu : public Player
{
public:
	
	// ��̐���������
	void generate_hand();
};