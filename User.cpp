#include "User.h"
using namespace std;


// �����͂���֐�
void User::input_hand()
{
	while (1)
	{
		// ���͂���ϐ��̐���
		cout << "�����I��ł�������" << endl;
		cout << "" << endl;
		cout << "[1] �O�[" << endl;
		cout << "[2] �`���L" << endl;
		cout << "[3] �p�[" << endl;
		cout << "" << endl;

		// �ϐ��̓���
		cout << ">> ";
		cin >> myhand;
		cout << "" << endl;

		// �K�؂Ȓl�����͂���Ă��邩�`�F�b�N����
		if ((myhand == Consts::Rock)
			|| (myhand == Consts::Scissors)
			|| (myhand == Consts::Paper))
		{
			break;	// �K�؂Ȓl�Ȃ疳�����[�v�𔲂���
		}
		else
		{
			// �K�؂łȂ��l�����͂���Ă���ꍇ�̓G���[��\����������x���͂�����
			cout << "!! �K�؂Ȓl����͂��ĉ����� !!" << endl;
			cout << "" << endl;
		}
	}

	return;
}


// �p�����邩�ǂ��������
int User::input_cont()
{
	int option = 0;

	while (1)
	{
		// ���͂���ϐ��̐���
		cout << "��������x�ΐ킵�܂���?" << "\n";
		cout << "\n";
		cout << "[1] �͂�\n";
		cout << "[2] ������\n";
		cout << "\n";

		// �ϐ��̓���
		cout << ">> ";
		cin >> option;
		cout << "\n";

		// �K�؂Ȓl�����͂���Ă��邩���`�F�b�N
		if ((option == Consts::Cont)
			|| (option == Consts::Exit))
		{
			break;	// �K�؂Ȓl�����͂���Ă���Ȃ�΃��[�v�𔲂���
		}
		else
		{
			// �K�؂łȂ��l�����͂���Ă���ꍇ�̓G���[��\����������x���͂�����
			cout << "!! �K�؂Ȓl����͂��ĉ����� !!" << endl;
			cout << "" << endl;
		}
	}

	return option;
}


// ���ʂ̋L�^
void User::write_result(int r)
{
	// ����r��Consts�N���X�Œ�`���ꂽ���s��\���萔�ɂ̂��Ƃ�
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


// �L�^�̕W���o��(�f�o�b�O�p)
void User::show_result()
{
	cout << "win : " << num_win << "\n";
	cout << "lose: " << num_lose << "\n";
	cout << "draw: " << num_draw << "\n";
}


// �L�^�̃Q�b�^(Consts��`��WinLoseDraw�Ŏw�肵�����m��Ԃ�)
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