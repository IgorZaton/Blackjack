#include "functions.h"
#include "Card.h"
#include "Player.h"
#include "Casino.h"

#include <string>
#include <iostream>




std::ostream& operator<<(std::ostream& os, Player& player) // overloading for Player
{
	os << player.name << "\t";
	for (int i = 0; i < player.cardsQuantity(); i++)
		os << *(player.cards[i]) << " ";
	os << "\t" << player.cardsValue();
	return os;
}

std::ostream& operator<<(std::ostream& os, Card& card) //overloading for Card
{
	os << card.figure << card.color;
	return os;
}

void swapPlayers(Player &fir, Player &sec)
{
	std::swap(fir.name, sec.name);
	std::swap(fir.cards, sec.cards);
	//std::swap(fir.casino, sec.casino);
	std::swap(fir.passflag, sec.passflag);
}

int setSomeInt(std::string &sth)
{
	int toreturn;
	std::cout << sth;
	std::cin >> toreturn;
	return toreturn;
}

void game(Casino *casino)
{
	//casino->shuffle();
	while (!casino->endGame())
	{
		for (int i = 0; i < casino->howManyPlayers(); i++)
		{
			if (casino->player(i)->cardsValue() > 21) casino->player(i)->pass(true);
			casino->playerInfo(i);
			if (casino->player(i)->pass() != 1)
			{
				casino->player(i)->decision();
				casino->player(i)->takeCard(casino->giveCard());
			}
		}
	}
	std::cout << "\n";
	for (int i = 0; i < casino->howManyPlayers(); i++)
	{
		casino->playerInfo(i);
	}

	if (casino->winner())	casino->displayWinner();


	
	system("pause");
}

void menu(int option)
{
	switch (option)
	{
	case 1:
		system("cls");
		std::cout << "1. Start new game\n";
		std::cout << "2. Exit\n";
		break;
	case 2:
		system("cls");
		std::cout << "1.Add player\n";
		std::cout << "2.Add bot\n";
		std::cout << "3.Start game\n";
		break;
	case 3:
		system("cls");
		std::cout << "1.Start new game\n";
		std::cout << "2.Exit\n";
		break;
	}
}

void failure()
{
	std::cout << "Failure, try again:\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}