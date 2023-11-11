#pragma once

#include "User.h"
#include "Cpu.h"
#include "Consts.h"
#include "Gnuplot.h"

#include <iostream>
#include <fstream>

using namespace std;

// ===========================
//	ゲームのクラス
// ===========================

class Game
{
	User usr;	// プログラムのユーザ
	Cpu com;	// コンピュータ
	int round = 0;	// 何回戦かを表す(0スタート)

public:

	// ゲーム自体(main関数で呼び出す)
	void play_game();

	// プログラムの説明を行う関数
	void instruct();

	// 勝敗を判定する
	int judge();

	// 勝敗表示をする
	void show_judge(int r);

	// 手のログと勝敗ファイルにエクスポート
	void export_log();

	// グラフの作成
	void draw_graph();
};