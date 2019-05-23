#pragma once
#include "Card.h"
#include <vector>


class Player;
class CPU;

class Casino
{
public:
	friend int setSomeInt(std::string sth);

	Casino();
	~Casino();
	void shuffle();
	void clear();
	Card* giveCard();
	void addPlayer(int player_or_bot);
	int howManyPlayers();
	int howManyBots();
	void playerInfo(int player_num);
	void displayPlayersList();
	void showCardsOfPlayer(int player_num);
	void playerPoints(int player_num);
	bool endGame();
	void displayWinner();
	bool winner();
	void saveFile();
	Player* player(int player_num);
private:
	Card *deck[52];
	int taken_cards;
	std::vector<Player*> players;
	int bot_num;
};