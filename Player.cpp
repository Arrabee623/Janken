#include "Player.h"

using namespace std;


// 手のゲッタ(数値データを返す)
int Player::get_myhand()
{
	return myhand;
}


// 挿入子オーバーロード
ostream& operator<<(ostream& stream, Player ob)
{
	// 手を取得
	int hand = ob.get_myhand();

	// 手によって出力する文字列を変える
	switch (hand)
	{
	case Consts::Rock:
		stream << "   ＿_" << "\n";
		stream << "  /｣｣｣｣" << "\n";
		stream << " ｜っ丿" << "\n";
		stream << "  グー" << "\n";
		break;

	case Consts::Scissors:
		stream << "" << "\n";
		stream << "　(Ｖ)" << "\n";
		stream << "  /ｱE)" << "\n";
		stream << " チョキ" << "\n";
		break;

	case Consts::Paper:
		stream << "" << "\n";
		stream << "　｢｢｢h" << "\n";
		stream << " Ｃ　ﾉ" << "\n";
		stream << "  パー" << "\n";
		break;

	}
	stream << "" << "\n";

	return stream;
}


// 出した手を記録する
void Player::write_log(int round)
{
	// 引数roundは0始まりの現在のラウンド数とする
	hands_log[round] = myhand;
	return;
}

// ログを標準出力(デバッグ用)
void Player::show_log()
{
	int i;
	
	for (i = 0; i < MaxOfGames; i++)
	{
		if (hands_log[i] == 0)
		{
			break;
		}

		cout << i << ": " << hands_log[i] << "\n";
	}

	return;
}


// ログのゲッタ
int* Player::get_hands_log()
{
	return hands_log;
}
