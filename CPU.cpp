#include "CPU.h"

CPU::CPU(Casino *_casino, int _courage)//Casino *_casino)
{
	name[0] = 'B';
	name[1] = 'O';
	name[2] = 'T';
	name[3] = (char)_casino->howManyBots() + 49; //ascii
	takeCard(_casino->giveCard());
	takeCard(_casino->giveCard());
	passflag = 0;
	botflag = 1;
	winnerflag = 0;
	if (_courage < 0) courage = -1;
	else if (_courage == 0) courage = 0;
	else if (_courage > 0) courage = 1;
}


void CPU::decision()
{
	switch (courage)
	{
	case -1:
		if (cardsValue() > 10) passflag = 1;
		break;
	case 0:
		if (cardsValue() > 14) passflag = 1;
		break;
	case 1:
		if (cardsValue() > 17) passflag = 1;
		break;
	}
}

