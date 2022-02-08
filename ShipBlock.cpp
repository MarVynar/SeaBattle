#include "ShipBlock.h"

ShipBlock::ShipBlock(char x, int y)
{
	symbol = 'X';
	this->x = x;
	this->y = y;

}

void ShipBlock::damage()
{

	symbol = 'X';
}

void ShipBlock::kill()
{

	symbol = 'O';
}

char ShipBlock::getSymbol()
{
	return symbol;
}

std::pair<char, int> ShipBlock::getCoords()
{
	return std::make_pair(x,y);
}
