#include "Card.h"

char colors[] = { '<', '3', '%', '>'};
char figures[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'A', 'J', 'Q', 'K' };
int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 3, 4 };

Card::Card(int _color, int _value, bool _flag) {
	setColor(_color);
	setValue(_value);
	flag = _flag;
}

void Card::setColor(int _color) 
{
		color = colors[_color];
}

void Card::setValue(int _value) {
	if (_value < 13) {
		figure = figures[_value];
		value = values[_value];
	}
}

bool Card::checkFlag()
{
	return flag;
}

void Card::setFlag(bool _state)
{
	flag = _state;
}

void Card::displayCard()
{
	std::cout << figure << color << " ";
}

Card& Card::operator=(Card& card)
{
	color = card.color;
	figure = card.figure;
	value = card.value;
	flag = card.flag;
	return *this;
}