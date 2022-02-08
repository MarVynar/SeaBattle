#pragma once
#include <vector>
#include <tuple>
#include <memory>
#include "Ship.h"

enum blockStatus { empty, missed, shot, killed };

class GameData
{
	unsigned int alive_ships;
public:
	GameData();
	~GameData();

	void setShipsNumber();
	unsigned int getShipsNumber();
	void destroyShip();

	void clearData();

	std::vector<std::shared_ptr<Ship> >ships;
	std::vector< std::tuple <char, int, char >  > shots;
};

