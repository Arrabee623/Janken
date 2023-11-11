#include "Game.h"

using namespace std;


// �Q�[������(main�֐��ŌĂяo��)
void Game::play_game()
{
	// �v���O�����̐������s��
	instruct();

	// �Q�[�����[�v
	int i = 0;
	// �O�̂��߃Q�[���̍ő吔�Ŏ��~�߂������Ă���
	for (i = 0; i < MaxOfGames; i++)
	{
		// ���E���h���̕\��
		cout << "����" << (round + 1) << "�Q�[��" << "\n";
		cout << "\n";

		// ���[�U�Ɏ��I�΂���
		usr.input_hand();
		usr.write_log(round);	// �L�^

		// �R���s���[�^�̎�𐶐�
		com.generate_hand();
		com.write_log(round);	// �L�^

		// ���s�𔻒肷��
		int result = judge();
		usr.write_result(result);	// �L�^

		// ���݂��̎��\��
		cout << "-------------------------------------------------\n\n";
		cout << "���Ȃ�:" << "\n";
		cout << usr;
		cout << "COM: " << "\n";
		cout << com;

		// ���s�\��
		show_judge(result);

		// �p�����邩�h�E������͂��Ă��炤
		cout << "-------------------------------------------------\n\n";
		int option = usr.input_cont();
		
		// �p������
		if (option == Consts::Exit)
		{
			cout << "-------------------------------------------------\n\n";
			cout << "�Q�[�����I�����܂��B" << "\n";
			cout << "\n";
			break;	// �������[�v���I������
		}
		else
		{
			round++;	// ���̃��E���h��
			cout << "-------------------------------------------------\n\n";
		}
	}

	// �ŏI���ʂ̕\��
	cout << "���Ȃ��̌���:\n";
	usr.show_result();

	// �t�@�C���o��
	export_log();

	// �O���t�\��
	draw_graph();
}


// �v���O�����̐������s���֐�
void Game::instruct()
{
	cout << "==========================" << "\n";
	cout << "=== ����񂯂�Q�[��!! ===" << "\n";
	cout << "==========================" << "\n";
	cout << "\n";
	cout << "���R���s���[�^�Ƃ���񂯂�����悤!!" << "\n";
	cout << "�������ɂ��������ē��͂��ĂˁB" << "\n";
	cout << "(���͂͂��ׂĔ��p�����ōs���Ă��������B)" << "\n";
	cout << "\n";
}


// ���s�𔻒肷��
int Game::judge()
{
	// ���݂��̎���擾
	int usr_hand = usr.get_myhand();
	int com_hand = com.get_myhand();

	// ����
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


// ���s�\��������
void Game::show_judge(int r)
{
	switch (r)
	{
	case Consts::Win:
		cout << "���Ȃ��̏����ł�!!!" << "\n";
		cout << "\n";
		break;
	case Consts::Lose:
		cout << "���Ȃ��̕����ł�..."<< "\n";
		cout << "\n";
		break;
	case Consts::Draw:
		cout << "���������ł��B" << "\n";
		cout << "\n";
		break;
	default:
		cout << "!! �\�����ʃG���[���������܂����B !!" << "\n";
		cout << "\n";
		break;
	}
}


// // ��̃��O���t�@�C���ɃG�N�X�|�[�g
void Game::export_log()
{
	// �t�@�C�����I�[�v��
	ofstream fhands("hands.txt");
	ofstream fresults("results.txt");

	// ��̃��O�̎擾
	int* usr_hands = usr.get_hands_log();	// ���[�U
	int* com_hands = com.get_hands_log();	// �R���s���[�^

	// ��̃��O�̏������ݏ���
	// �f�[�^�̌`��
	// (���E���h��) (���[�U�̎�) (�R���s���[�^�̎�)
	for (int i = 0; i <= round; i++)
	{
		fhands << (i + 1) << "\t";	// ���E���h��
		fhands << *(usr_hands + i) << "\t";	// ���[�U�̎�
		fhands << *(com_hands + i) << "\n";	// �R���s���[�^�̎�
	}

	// ���s�̏������ݏ���
	// �f�[�^�̌`
	// (Win/Lose/Draw) (���̐�)
	fresults << "Win" << "\t" << usr.get_result(Consts::Win) << "\n";
	fresults << "Lose" << "\t" << usr.get_result(Consts::Lose) << "\n";
	fresults << "Draw" << "\t" << usr.get_result(Consts::Draw) << "\n";

	// �t�@�C�����N���[�Y
	fhands.close();
	fresults.close();
}


// �O���t�̍쐬
void Game::draw_graph()
{
	Gnuplot gp_hands;	// ��̃O���t����
	Gnuplot gp_result;	// ���s�q�X�g�O����

	// ��̃O���t���ڂ��O���t�\��
	gp_hands.SetXLabel("Round");
	gp_hands.SetYLabel("1:Rock / 2:Scissers / 3:Paper");
	// ���[�U�̃O���t�\��
	gp_hands.Plot("hands.txt", "using 1:2 w lp ls 1 title \"You\"");
	// �R���s���[�^�̎�̃O���t�\��
	gp_hands.AddPlot("hands.txt", "using 1:3 w lp ls 20 title \"COM\"");

	// ���s�q�X�g�O����
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