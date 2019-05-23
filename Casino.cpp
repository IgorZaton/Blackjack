#include "Casino.h"
#include "Card.h"
#include "Player.h"
#include "CPU.h"

#include <fstream>

Casino::Casino()
{
	int col_num = 0;
	int val = 0;
	taken_cards = 0;
	for (int i = 0; i < 52; i++)
	{
		deck[i] = new Card(col_num, val);
		if (val == 12) {
			col_num++;
			val = 0;
		}
		else val++;
	}
	this->shuffle();
}

Casino::~Casino()
{
	for (int i = 0; i < 52; i++)
		delete deck[i];
	for (auto &p : players)
		delete p;
}

void Casino::clear()
{
	this->~Casino();
	int col_num = 0;
	int val = 0;
	taken_cards = 0;
	for (int i = 0; i < 52; i++)
	{
		deck[i] = new Card(col_num, val);
		if (val == 12) {
			col_num++;
			val = 0;
		}
		else val++;
	}
	this->shuffle();
		
	players.clear();
	bot_num = 0;
}

void Casino::addPlayer(int player_or_bot)
{
	if (player_or_bot == 2) {
		Player *temp;
		temp = new CPU(this, setSomeInt("Set level of courage: "));
		bot_num++;
		players.push_back(temp);
	}
	else {
		Player *temp;
		temp = new Player(this);
		temp->giveName();
		players.push_back(temp);
	}	
}

void Casino::playerInfo(int player_num)
{
	std::cout << std::endl;
	players[player_num]->showName();
	std::cout << "cards: ";
	showCardsOfPlayer(player_num);
	std::cout << "\tpoints: ";
	playerPoints(player_num);
}

void Casino::showCardsOfPlayer(int player_num)
{
	players[player_num]->showCards();
}

int Casino::howManyPlayers()
{
	return players.size();
}

int Casino::howManyBots()
{
	return bot_num;
}

void Casino::playerPoints(int player_num)
{
	std::cout << players[player_num]->cardsValue() << " ";
}

void Casino::displayPlayersList()
{
	for (int i = 0; i < howManyPlayers(); i++)
		this->playerInfo(i);
}

void Casino::shuffle()
{
	Card *temp;
	int randomone, randomtwo;
	for (int i = 0; i < 100; i++)
	{
		randomone = rand() % 52;
		randomtwo = rand() % 52;
		temp = deck[randomone];
		deck[randomone] = deck[randomtwo];
		deck[randomtwo] = temp;
	}
}

Card* Casino::giveCard()
{
	/*if (deck[taken_cards]->checkflag() == 0)
	{
		deck[taken_cards]->setflag(1);
		return deck[taken_cards];
	}
	else
	{
		taken_cards++;
		return givecard();
	}*/
	taken_cards++;
	return deck[taken_cards - 1];
}

bool Casino::endGame()
{
	for (int i = 0; i < howManyPlayers(); i++)
	{
		if (players[i]->pass() == 0) return false;
	}
	return true;
}

Player* Casino::player(int player_num)
{
	return players[player_num];
}

bool Casino::winner()
{
	int a = -1; bool flag = 0;	
	for (int i = 0; i < howManyPlayers(); i++)
	{
		if (players[i]->cardsValue() <= 21)
		{
			if (a == -1) a = i;
			flag = true;
			if (players[i]->cardsValue() >= players[a]->cardsValue())	a = i;
		}
	}

	if (flag == 0) return false;
		
	for (int i = 0; i < howManyPlayers(); i++)
		if (players[i]->cardsValue() == players[a]->cardsValue()) players[i]->isWinner();

	return true;
}

void Casino::displayWinner()
{
	for (int i = 0; i < howManyPlayers(); i++)
	{
		if (players[i]->winnerFlag()) { std::cout << "\nwinner: "; playerInfo(i); }
	}
}

void Casino::saveFile()
{
	std::ofstream file;
	file.open("game.txt", std::ifstream::out);
	for (int i = 0; i < howManyPlayers(); i++)
		file << *players[i] << std::endl;
	file.close();
}