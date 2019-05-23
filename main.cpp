#include <iostream>
#include <time.h>
#include <string>


#include "Card.h"
#include "Casino.h"
#include "Player.h"
#include "functions.h"


int main()
{
	srand(time(NULL));
	Casino casino;
	int choose_1, choose_2, flag;
	menu(1);	
	while (1) 
	{
		std::cin >> choose_1;
		switch (choose_1)
		{
		case 1:
			menu(2);
			while (1)
			{
				flag = 0;
				std::cin >> choose_2;
				switch (choose_2)
				{
				case 1: case 2: // Bot
					casino.addPlayer(choose_2);
					break;
				case 3:
					game(&casino);
					casino.saveFile();
					menu(3);
					std::cin >> choose_1;
					if (choose_1 == 1) flag = 1;
					else if (choose_1 == 2) flag = 2;
					break;
				default:
					failure();
					break;
				}
				if (flag == 1) { casino.clear(); menu(2); }
				else if (flag == 2) break;
			}
			break;
		case 2:
			return 0;
		default:
			failure();
			break;
		}
		if (flag == 2) break;
	}
	return 0;
}