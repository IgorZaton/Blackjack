#pragma once
#include <string>
#include <iostream>

class Player;
class Card;
class Casino;

std::ostream& operator<<(std::ostream& os, Player& player); // overloading for Player
std::ostream& operator<<(std::ostream& os, Card& card); //overloading for Card
void swapPlayers(Player &fir, Player &sec);
int setSomeInt(std::string &sth);
void game(Casino *casino);
void menu(int option);
void failure();