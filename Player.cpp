#include "Player.h"
#include "Casino.h"
#include "functions.h"
#include <string>

void Player::statement(std::string inscription, int nextline)
{
	std::cout << inscription;
	if (nextline == 1) std::cout << std::endl;
}

void Player::giveName()
{
	statement("Name: ");
	std::cin >> name;
}


Player::Player(Casino* _casino)
{
	takeCard(_casino->giveCard());
	takeCard(_casino->giveCard());
	passflag = 0;
	botflag = 0;
	winnerflag = 0;
}

void Player::takeCard(Card* _card)
{
	if (passflag == 1) return;
	cards.push_back(_card);
}

void Player::decision()
{
	bool _flag;
	statement("Pass? (1/0)");
	std::cin >> _flag;
	if(std::cin.fail())
	{
		failure();
		decision();
	}
	if (_flag == 1) passflag = true;
}

void Player::pass(bool _ifpass)
{
	passflag = _ifpass;
}

bool Player::pass()
{
	return passflag;
}

int Player::cardsQuantity()
{
	return cards.size();
}

int Player::cardsValue()
{
	int sum = 0;
	for (int i = 0; i < cards.size(); i++)
		sum += cards[i]->showValue();
	return sum;
}

void Player::showCards()
{
	for (int i = 0; i < cards.size(); i++)
		cards[i]->displayCard();
}

void Player::showName()
{
	std::cout << name << "\t";
}

Player Player::operator=(Player &player)
{
	swapPlayers(*this, player);
	return *this;
}

void Player::isWinner()
{
	winnerflag = true;
}

bool Player::winnerFlag()
{
	return winnerflag;
}


