#include "GameData.h"

GameData::GameData()
{
	
}

GameData::~GameData()
{
	clearData();
}

void GameData::setShipsNumber()
{
	alive_ships = ships.size();
}

unsigned int GameData::getShipsNumber()
{
	return alive_ships;
}

void GameData::destroyShip()
{
	alive_ships--;
}

void GameData::clearData()
{
	ships.clear();
	shots.clear();
}
