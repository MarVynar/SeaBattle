#include "GameCore.h"





GameCore::GameCore()
{
	maxDecks = 4;

	
	
	gameData = new GameData();
	graphicCore = new GraphicCore(gameData);


	std::cout << "Do you want to run as a (S)erver or (C)lient?" << std::endl;
	char ch;
	bool selected = false;
	do {



		std::cin >> ch;
		switch (ch) {

		case'S':
		case's': isServer = true; std::cout << "Server" << std::endl; selected = true; break;
		case'C':
		case'c': isServer = false; std::cout << "Client" << std::endl; selected = true; break;

		default: std::cout << "Wrong Choice" << std::endl;

		}

	} while (!selected);

	netCore = new NetCore(isServer);
	if (isServer) {
		netCore->receiveRequest();
		}

	setShips();
	gameData->setShipsNumber();
	//std::cout << "Running" << std::endl;
	gameState = GameState::run;
	//std::cout << "StateChanged" << std::endl;
	runGame();
	gameData->clearData();
}

GameCore::~GameCore()
{

	delete graphicCore;
	delete gameData;
	
}

