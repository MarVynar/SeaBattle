#include "GameCore.h"

void GameCore::setShips()
{
	



	bool selected = false;

	for (int currentDecks = 1; currentDecks <= maxDecks; currentDecks++)
		for (int i = 1; i <= (maxDecks - currentDecks + 1); i++)

		{
			selected = false;

			while (!selected) {
				/*char nx = 0;
				int ny = 0;
				char nx1 = 0;
				int ny1 = 0;
				char cny;*/

				std::pair<char, int> enterResult;
				std::pair<char, int> enterResult2;

				std::cout << "Please enter the first cell of" << i << " " << currentDecks << "-board ship (Letter + number)" << std::endl;

					bool entered = false;
					while (!entered) {
					
						//std::cin >> nx >> ny;
						//if ((cnx >= 'A') && (cnx <= 'J') {}
					//	std::pair<char, int> 
							enterResult = enterCoords();
					
						/*if ((nx >='A') && (nx<='J') && (ny>=1) && (ny<=10))
						{ */

							entered = true;
							for (auto it : gameData->ships)
							{

					
								if (it->checkCoords(enterResult.first, enterResult.second) != nullptr) { entered = false;  std::cout << "Wrong info entered1" << std::endl;  break; }

							}

						
					
						/*}
						else { std::cout << "Wrong info entered2" << std::endl; }*/
					}
				

				if (currentDecks > 1) {

					std::cout << "Please enter the next cell of" << currentDecks << "board ship" << std::endl;

					bool entered = false;
					while (!entered) {

						//std::cin >> nx1 >> ny1;
						//std::pair<char, int> 
						enterResult2 = enterCoords();
					
						/*if ((enterResult2.first >= 'A') && (nx1 <= 'J') && (ny1 >= 1) && (ny1 <= 10))
						{*/

							entered = true;
							for (auto it : gameData->ships)
							{
								for (int nx =-1;nx <=1;nx++) {
									for (int ny = -1; ny <= 1; ny++) {

										if (it->checkCoords((char)(enterResult2.first+nx), (enterResult2.second+ny)) != nullptr) { entered = false;  std::cout << "Wrong info entered3" << std::endl;  break; }


									}


								}
								//if (it->checkCoords(enterResult2.first, enterResult2.second) != nullptr) { entered = false;  std::cout << "Wrong info entered3" << std::endl;  break; }

							}



						//}
						//else { std::cout << "Wrong info entered4" << std::endl; }
					}

					std::cout << "Creating" << std::endl;
					gameData->ships.push_back(std::make_shared<Ship>(currentDecks, enterResult.first, enterResult.second, enterResult2.first, enterResult2.second));
					selected = true;
					std::cout << "Created" << std::endl;

				}
				else {

					gameData->ships.push_back(std::make_shared<Ship>(currentDecks, enterResult.first, enterResult.second));
					selected = true;

				}

			}



		}






}