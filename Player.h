#pragma once

#include "Consts.h"
#include <iostream>

using namespace std;

// =========================
//	プレイヤークラス
// =========================

class Player
{
protected:
	// protectedメンバ
	int myhand = 0;		// 選んだ手
	int hands_log[MaxOfGames] = {0};	// これまで出した手の記録

public:
	// 手のゲッタ(数値データで返す)
	int get_myhand();

	// 挿入子オーバーロード(手のグラフィカル?な表示)
	friend ostream& operator<< (ostream& stream, Player ob);

	// 出した手を記録する
	void write_log(int round);

	// ログを標準出力(デバッグ用)
	void show_log();

	// ログのゲッタ
	int* get_hands_log();
};