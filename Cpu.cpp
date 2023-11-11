#include "Cpu.h"
using namespace std;

// è‚Ì¶¬‚ğ‚·‚é
void Cpu::generate_hand()
{
	// —”‚Ìí‚ğİ’è
	srand(time(0));

	// ƒWƒƒƒ“ƒPƒ“‚Ìè‚ğ¶¬
	myhand = rand() % 3 + 1;
}