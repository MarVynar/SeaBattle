#pragma once
#include <utility>



class ShipBlock
{
	char symbol;

	char x;
	int y;

	


public:
	ShipBlock()= default;
	ShipBlock(char x, int y);

	void damage();
	void kill();
	char getSymbol();

	std::pair <char, int> getCoords();
};

