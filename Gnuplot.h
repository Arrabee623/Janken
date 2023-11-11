#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

class Gnuplot {
	FILE* gnuplot;
	float deltTime = 0.0;
	int playTime = 0;
public:
	Gnuplot();	// Gnuplotの起動
	~Gnuplot();	// Gnuplotのファイルディスクリプタの破棄

	void SetXRange(int lower, int higher);	// xの範囲を決定
	void SetYRange(int lower, int higher);	// yの範囲を決定
	void Plot(const char* str);		// 自由な指定でのプロット

	void PlotBegin();	// 座標データを送る準備
	void PlotBegin(const char* str);	// 座標データを送る準備
	void AddPlotData(float x, float y);	// 座標データを送る
	void PlotEnd();	// 座標プロットの終了

	void SetTitle(const char* title);	// タイトルの設定
	void SetXLabel(const char* label);	// x軸のラベルの設定
	void SetYLabel(const char* label);	// y軸のラベルの設定

	void SetTerm(const char* term, int number);	// ???

	void Plot(const char* fileName, const char* str);	// ファイルからのデータをプロット
	void AddPlot(const char* fileName, const char* str);	// ファイルからのデータを追加プロット

	void SetAnimation(float dTime, float sec);	// アニメーションの準備
	void PlotAnimation(const char* fileName, const char* str);	// プロット
	void AddAnimation(const char* fileName, const char* str);	// 追加プロット
	void Pause();	// ???
	void Pause(float dTime);	// 多分一時停止
	void EndAnimation();	// アニメーション機能の終了

	void PlotBar(const char* fileName, int max);	// 棒グラフの表示
};