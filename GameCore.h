#pragma once

#include "NetCore.h"
#include "GraphicCore.h"
#include "GameData.h"
#include "Ship.h"
#include<vector>
#include <memory>
#include <utility>
#include <tuple>


enum GameState {run, win, lose};

class GameCore
{

	NetCore * netCore;

	GraphicCore* graphicCore;
	GameData * gameData;


	GameState gameState;


	int maxDecks;

	void setShips();
	std::string updateGameData(std::pair<char, int>);
	void updateGameData(char x, int y, std::string ch);
	std::pair<char, int> shoot();
	std::pair <char, int> enterCoords();


	bool isServer;

public:
	GameCore();
	~GameCore();

	void runGame();
	
	friend class GraphicCore;
};

