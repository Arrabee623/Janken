#pragma once

// ===========================
//	ゲームで使う定数まとめ
// ===========================

#define MaxOfGames 100	// 1回のプログラムで行える最大ゲーム数

class Consts
{
public:
	// 勝敗を表す定数
	static const int Win = 1;	// 勝ち
	static const int Lose = 2;	// 負け
	static const int Draw = 3;	// 引き分け

	// ジャンケンで出す手を表す
	static const int Rock = 1;	// グー
	static const int Scissors = 2;	// チョキ
	static const int Paper = 3;	// パー

	// ゲーム継続に関する定数
	static const int Cont = 1;	// 続ける
	static const int Exit = 2;	// やめる
};