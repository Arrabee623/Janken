#include "Cpu.h"
using namespace std;

// ��̐���������
void Cpu::generate_hand()
{
	// �����̎��ݒ�
	srand(time(0));

	// �W�����P���̎�𐶐�
	myhand = rand() % 3 + 1;
}