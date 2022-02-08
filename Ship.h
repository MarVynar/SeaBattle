#pragma once
#include "ShipBlock.h"
#include <string>

class Ship
{
	unsigned int num;
	unsigned int aliveNum;
	ShipBlock * blocks;
	bool alive;

public:

	Ship(unsigned int num, char x, int y);
	Ship(unsigned int num, char x1, int y1, char x2, int y2);
	~Ship();


	 ShipBlock* checkCoords(char letter, int number);


	 void showCoords();
	 std::string getCoords();
	 std::string damage(char x, int y);
};

