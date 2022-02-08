#include "GameCore.h"

void GameCore::runGame()
{
	std::cout << "InRunning" << std::endl;

	std::pair <char, int> shootCoords;
	//char requestResult=0;
	std::string requestResult ;

	std::cout << "BeforeUpdate" << std::endl;
	graphicCore->updateScreen();
	std::cout << "AfterUpdate" << std::endl;

	if (isServer) {

		do {
			std::cout << "Enter fire coords" << std::endl;

			shootCoords = shoot();
			netCore->sendRequest(shootCoords.first, shootCoords.second);
			requestResult = netCore->receiveReply();
			std::cout << "ReqRes:" << requestResult << std::endl;
			updateGameData(shootCoords.first, shootCoords.second, requestResult);
			graphicCore->updateScreen();
			if (gameState != GameState::run) { std::cout << "Returning" << std::endl;  return; }
		} while ((requestResult[0] == 'O') || (requestResult == "X"));
	}
	
	while (gameState == GameState::run) {

		do{
			std::cout << "Wait for enemy to fire" << std::endl;
			
			requestResult =  updateGameData(netCore->receiveRequest());
			
			graphicCore->updateScreen();
			if (gameState != GameState::run) { std::cout <<"Returning" << std::endl;  return; }
		} while ((requestResult =="X") ||(requestResult[0] == 'O'));
			do {
				std::cout << "Enter fire coords" << std::endl;

				shootCoords = shoot();
				netCore->sendRequest(shootCoords.first, shootCoords.second);
				requestResult = netCore->receiveReply();
				updateGameData(shootCoords.first, shootCoords.second, requestResult);
				graphicCore->updateScreen();
				if (gameState != GameState::run) { std::cout << "Returning" << std::endl;  return; }
			} while ( (requestResult[0] =='O')|| (requestResult == "X"));


	}



}
