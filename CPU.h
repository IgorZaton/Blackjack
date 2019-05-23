#pragma once
#include "Player.h"
#include "Casino.h"
#include <string>

class CPU : public Player
{
public:
	CPU(Casino *_casino, int _courage);
	void decision() ;
private:
	int courage;
};