#include "Cpu.h"
using namespace std;

// 手の生成をする
void Cpu::generate_hand()
{
	// 乱数の種を設定
	srand(time(0));

	// ジャンケンの手を生成
	myhand = rand() % 3 + 1;
}