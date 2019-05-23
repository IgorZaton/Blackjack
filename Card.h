#pragma once
#include <iostream>

class Card {
private:
	char color;
	char figure;
	int value;
	bool flag;
public:
	Card(int _color = 0, int _value = 0, bool _flag = 0);
	void setColor(int _color);
	void setValue(int _value);
	int showValue() { return value; }
	bool checkFlag();
	void setFlag(bool _state);
	Card& operator=(Card& card);
	friend std::ostream& operator<<(std::ostream& os, Card &card);
	void displayCard();
};