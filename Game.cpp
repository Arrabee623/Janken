#include "Game.h"

using namespace std;


// ゲーム自体(main関数で呼び出す)
void Game::play_game()
{
	// プログラムの説明を行う
	instruct();

	// ゲームループ
	int i = 0;
	// 念のためゲームの最大数で歯止めをかけておく
	for (i = 0; i < MaxOfGames; i++)
	{
		// ラウンド数の表示
		cout << "◎第" << (round + 1) << "ゲーム" << "\n";
		cout << "\n";

		// ユーザに手を選ばせる
		usr.input_hand();
		usr.write_log(round);	// 記録

		// コンピュータの手を生成
		com.generate_hand();
		com.write_log(round);	// 記録

		// 勝敗を判定する
		int result = judge();
		usr.write_result(result);	// 記録

		// お互いの手を表示
		cout << "-------------------------------------------------\n\n";
		cout << "あなた:" << "\n";
		cout << usr;
		cout << "COM: " << "\n";
		cout << com;

		// 勝敗表示
		show_judge(result);

		// 継続するかドウかを入力してもらう
		cout << "-------------------------------------------------\n\n";
		int option = usr.input_cont();
		
		// 継続処理
		if (option == Consts::Exit)
		{
			cout << "-------------------------------------------------\n\n";
			cout << "ゲームを終了します。" << "\n";
			cout << "\n";
			break;	// 無限ループを終了する
		}
		else
		{
			round++;	// 次のラウンドへ
			cout << "-------------------------------------------------\n\n";
		}
	}

	// 最終結果の表示
	cout << "あなたの結果:\n";
	usr.show_result();

	// ファイル出力
	export_log();

	// グラフ表示
	draw_graph();
}


// プログラムの説明を行う関数
void Game::instruct()
{
	cout << "==========================" << "\n";
	cout << "=== じゃんけんゲーム!! ===" << "\n";
	cout << "==========================" << "\n";
	cout << "\n";
	cout << "◎コンピュータとじゃんけんをしよう!!" << "\n";
	cout << "◎説明にしたがって入力してね。" << "\n";
	cout << "(入力はすべて半角数字で行ってください。)" << "\n";
	cout << "\n";
}


// 勝敗を判定する
int Game::judge()
{
	// お互いの手を取得
	int usr_hand = usr.get_myhand();
	int com_hand = com.get_myhand();

	// 判定
	int j = (usr_hand - com_hand + 3) % 3;

	switch (j)
	{
	case 0:
		return Consts::Draw;
		break;
	case 1:
		return Consts::Lose;
		break;
	case 2:
		return Consts::Win;
		break;
	}

	return -1;
}


// 勝敗表示をする
void Game::show_judge(int r)
{
	switch (r)
	{
	case Consts::Win:
		cout << "あなたの勝ちです!!!" << "\n";
		cout << "\n";
		break;
	case Consts::Lose:
		cout << "あなたの負けです..."<< "\n";
		cout << "\n";
		break;
	case Consts::Draw:
		cout << "引き分けです。" << "\n";
		cout << "\n";
		break;
	default:
		cout << "!! 予期せぬエラーが発生しました。 !!" << "\n";
		cout << "\n";
		break;
	}
}


// // 手のログをファイルにエクスポート
void Game::export_log()
{
	// ファイルをオープン
	ofstream fhands("hands.txt");
	ofstream fresults("results.txt");

	// 手のログの取得
	int* usr_hands = usr.get_hands_log();	// ユーザ
	int* com_hands = com.get_hands_log();	// コンピュータ

	// 手のログの書き込み処理
	// データの形↓
	// (ラウンド数) (ユーザの手) (コンピュータの手)
	for (int i = 0; i <= round; i++)
	{
		fhands << (i + 1) << "\t";	// ラウンド数
		fhands << *(usr_hands + i) << "\t";	// ユーザの手
		fhands << *(com_hands + i) << "\n";	// コンピュータの手
	}

	// 勝敗の書き込み処理
	// データの形
	// (Win/Lose/Draw) (その数)
	fresults << "Win" << "\t" << usr.get_result(Consts::Win) << "\n";
	fresults << "Lose" << "\t" << usr.get_result(Consts::Lose) << "\n";
	fresults << "Draw" << "\t" << usr.get_result(Consts::Draw) << "\n";

	// ファイルをクローズ
	fhands.close();
	fresults.close();
}


// グラフの作成
void Game::draw_graph()
{
	Gnuplot gp_hands;	// 手のグラフ推移
	Gnuplot gp_result;	// 勝敗ヒストグラム

	// 手のグラフ推移をグラフ表示
	gp_hands.SetXLabel("Round");
	gp_hands.SetYLabel("1:Rock / 2:Scissers / 3:Paper");
	// ユーザのグラフ表示
	gp_hands.Plot("hands.txt", "using 1:2 w lp ls 1 title \"You\"");
	// コンピュータの手のグラフ表示
	gp_hands.AddPlot("hands.txt", "using 1:3 w lp ls 20 title \"COM\"");

	// 勝敗ヒストグラム
	int max = usr.get_result(Consts::Win);
	if (max < usr.get_result(Consts::Lose))
	{
		max = usr.get_result(Consts::Lose);
	}
	
	if (max < usr.get_result(Consts::Draw))
	{
		max = usr.get_result(Consts::Draw);
	}

	gp_result.PlotBar("results.txt", max);
}