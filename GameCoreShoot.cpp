#include "GameCore.h"

std::pair<char, int> GameCore::shoot()
{
	//char nx1;
	//int ny1;
	bool entered = false;
	while (!entered) {

		//std::cin >> nx1 >> ny1;
		//
		////std::cout << nx1 << " " << ny1 << " " << (nx1 >= 'A') << (nx1 <= 'J') << (ny1 >= 1) << (ny1 <= 10) << std::endl;
		//if ((nx1 >= 'A') && (nx1 <= 'J') && (ny1 >= 1) && (ny1 <= 10))
		//{

		std::pair <char, int> enteredInfo = enterCoords();
			entered = true;
			for (auto it : gameData->shots)
			{
					if ((std::get<0>(it)== enteredInfo.first) && (std::get<1>(it)== enteredInfo.second) )
				{ 
					entered = false; 
					
					std::cout << "Wrong info entered" << std::endl;
					break;
				}

			}
			
			if (entered) { return std::make_pair(enteredInfo.first, enteredInfo.second);  }
			

		//}
		//else { std::cout << "Wrong info entered" << std::endl; }
	}
	return std::make_pair(-1, -1);
}
