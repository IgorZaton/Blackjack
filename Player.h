#pragma once
#include "Card.h"
#include <vector>
#include <iostream>

class Casino;

class Player
{
public:
	friend std::ostream& operator<<(std::ostream& os,Player &player);
	friend void swapPlayers(Player &fir, Player &sec);

	Player() {};
	Player(Casino* _casino);
	void statement(std::string inscription, int nextline = 0); // endl if nextline == 1
	void takeCard(Card* _card);
	virtual void decision();//if flag is 1 then pass
	void pass(bool _pass);
	void showCards();
	bool pass();
	void isWinner();
	bool winnerFlag();
	void giveName();
	void showName();
	int cardsQuantity();
	int cardsValue();
	Player operator=(Player &player);

protected:
	char name[20];
	std::vector<Card*> cards;
	bool passflag; // if 1  - pass 
	bool botflag;
	bool winnerflag;
	//Casino *casino; //casino where player is gambling

	
};
