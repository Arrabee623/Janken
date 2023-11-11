#include "User.h"
using namespace std;


// 手を入力する関数
void User::input_hand()
{
	while (1)
	{
		// 入力する変数の説明
		cout << "◎手を選んでください" << endl;
		cout << "" << endl;
		cout << "[1] グー" << endl;
		cout << "[2] チョキ" << endl;
		cout << "[3] パー" << endl;
		cout << "" << endl;

		// 変数の入力
		cout << ">> ";
		cin >> myhand;
		cout << "" << endl;

		// 適切な値が入力されているかチェックする
		if ((myhand == Consts::Rock)
			|| (myhand == Consts::Scissors)
			|| (myhand == Consts::Paper))
		{
			break;	// 適切な値なら無限ループを抜ける
		}
		else
		{
			// 適切でない値が入力されている場合はエラーを表示しもう一度入力させる
			cout << "!! 適切な値を入力して下さい !!" << endl;
			cout << "" << endl;
		}
	}

	return;
}


// 継続するかどうかを入力
int User::input_cont()
{
	int option = 0;

	while (1)
	{
		// 入力する変数の説明
		cout << "◎もう一度対戦しますか?" << "\n";
		cout << "\n";
		cout << "[1] はい\n";
		cout << "[2] いいえ\n";
		cout << "\n";

		// 変数の入力
		cout << ">> ";
		cin >> option;
		cout << "\n";

		// 適切な値が入力されているかをチェック
		if ((option == Consts::Cont)
			|| (option == Consts::Exit))
		{
			break;	// 適切な値が入力されているならばループを抜ける
		}
		else
		{
			// 適切でない値が入力されている場合はエラーを表示しもう一度入力させる
			cout << "!! 適切な値を入力して下さい !!" << endl;
			cout << "" << endl;
		}
	}

	return option;
}


// 結果の記録
void User::write_result(int r)
{
	// 引数rはConstsクラスで定義された勝敗を表す定数にのっとる
	switch (r)
	{
	case Consts::Win:
		num_win++;
		break;
	case Consts::Lose:
		num_lose++;
		break;
	case Consts::Draw:
		num_draw++;
		break;
	}
}


// 記録の標準出力(デバッグ用)
void User::show_result()
{
	cout << "win : " << num_win << "\n";
	cout << "lose: " << num_lose << "\n";
	cout << "draw: " << num_draw << "\n";
}


// 記録のゲッタ(Consts定義のWinLoseDrawで指定したモノを返す)
int User::get_result(int category)
{
	switch (category)
	{
	case Consts::Win:
		return num_win;
	case Consts::Lose:
		return num_lose;
	case Consts::Draw:
		return num_draw;
	}
	
	return 0;
}