#include "Player.h"

using namespace std;


// ��̃Q�b�^(���l�f�[�^��Ԃ�)
int Player::get_myhand()
{
	return myhand;
}


// �}���q�I�[�o�[���[�h
ostream& operator<<(ostream& stream, Player ob)
{
	// ����擾
	int hand = ob.get_myhand();

	// ��ɂ���ďo�͂��镶�����ς���
	switch (hand)
	{
	case Consts::Rock:
		stream << "   �Q_" << "\n";
		stream << "  /����" << "\n";
		stream << " �b����" << "\n";
		stream << "  �O�[" << "\n";
		break;

	case Consts::Scissors:
		stream << "" << "\n";
		stream << "�@(�u)" << "\n";
		stream << "  /�E)" << "\n";
		stream << " �`���L" << "\n";
		break;

	case Consts::Paper:
		stream << "" << "\n";
		stream << "�@���h" << "\n";
		stream << " �b�@�" << "\n";
		stream << "  �p�[" << "\n";
		break;

	}
	stream << "" << "\n";

	return stream;
}


// �o��������L�^����
void Player::write_log(int round)
{
	// ����round��0�n�܂�̌��݂̃��E���h���Ƃ���
	hands_log[round] = myhand;
	return;
}

// ���O��W���o��(�f�o�b�O�p)
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


// ���O�̃Q�b�^
int* Player::get_hands_log()
{
	return hands_log;
}
