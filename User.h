#pragma once

#include "Player.h"
using namespace std;

// =========================================
//	ユーザクラス(プレイヤークラスを継承)
// =========================================

class User : public Player
{
	int num_win = 0;	// 勝ち数
	int num_lose = 0;	// 負け数
	int num_draw = 0;	// 引き分け数

public:

	// 手を入力する関数
	void input_hand();

	// 継続するかどうかを入力
	int input_cont();

	// 結果の記録
	void write_result(int r);

	// 記録の標準出力(デバッグ用)
	void show_result();
	
	// 記録のゲッタ(Consts定義のWinLoseDrawで指定したモノを返す)
	int get_result(int category);
};