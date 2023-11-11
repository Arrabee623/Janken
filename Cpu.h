#pragma once

#include "Consts.h"
#include "Player.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// =====================================
//	CPUクラス(プレイヤークラスを継承)
// =====================================

class Cpu : public Player
{
public:
	
	// 手の生成をする
	void generate_hand();
};