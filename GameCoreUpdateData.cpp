#include "GameCore.h"
#include <string>

std::string GameCore::updateGameData(std::pair<char, int> coords)
{
	std::string tmp;
	std::cout << "Is Hit: " << coords.first << "," << coords.second << "." <<  std::endl;
	for (auto it : gameData->ships)
	{
		tmp = it->damage(coords.first, coords.second);
		
		if (tmp != "+") {

			if (tmp == "O") {
				gameData->destroyShip();
				if (gameData->getShipsNumber() == 0) {
					gameState = GameState::lose;
					std::cout << "You lost!" << std::endl;
					tmp = "L";
					
				}
				else {

					tmp += it->getCoords();
				}
			}

			std::cout << "HitRes " << tmp << std::endl;
			netCore->sendRequest(tmp);
			
			return tmp;
		}

	}
	std::cout << "HitRes " << tmp << std::endl;
	netCore->sendRequest(tmp);
	//vyvid na svij ekran
	return tmp;
}

void GameCore::updateGameData(char x, int y, std::string ch)
{
	if (ch == "L") {
		gameState = GameState::win;
		std::cout << "You won!" << std::endl;
		//std::cout << "GameState " << gameState << std::endl;
	}
	else {

		std::cout << "Hit: " << x << "," << y << "," << ch << std::endl;
		gameData->shots.push_back(std::make_tuple (x, y, ch[0]));

		if(ch[0] == 'O') {

			std::cout << "O: " << ch << std::endl;
			//for (auto it : gameData->shots) 
			for (std::vector< std::tuple <char, int, char >  > ::iterator  it= gameData->shots.begin(); it!= gameData->shots.end(); it++)
			//for (int it = 0; it<gameData->shots.size(); it++)
			{
				std::cout << "It: " << ch << std::endl;
				for (int i = 1; i < ch.length(); i+=2) {
					std::cout << "[]: " << ch[i] <<"-"<< ch[i+1] << "-"<< std::get<2>(*it) << std::endl;
					if (std::get<0>(*it) == ch[i] && std::get<1>(*it) == atoi(&ch[i+1])) {std::get<2>(*it) = 'O';  std::cout << "[in]: " << ch[i] << "-" << ch[i + 1] << "-" << std::get<2>(*it) << std::endl;
					}
				}
				std::cout << "[out]: " << std::get<2>(*it) << std::endl;
				//if (std::get<0>( gameData->shots[it]) == ch[1] && std::get<1>(gameData->shots[it]) == atoi(&ch[2])) { std::get<2>(gameData->shots[it]) = 'O'; }
			}

			for (auto it : gameData->shots)
			{
				std::cout << "[2out]: " << std::get<2>(it) << std::endl;
				}


		}
			   
	}
	
}

