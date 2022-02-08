#include "GameCore.h"

std::pair <char, int> GameCore::enterCoords() {
	char nx1;
	int ny1;
	std::string cny;
	bool entered = false;
	while (!entered) {

		std::cin >> nx1 >> cny;
		std::cout << nx1 << " -- " << cny << " + " << cny.c_str() << std::endl;
		ny1 = atoi(cny.c_str());

		if ((nx1 >= 'A') && (nx1 <= 'J') && (ny1 >= 1) && (ny1 <= 10))
		{

			entered = true;


			if (entered) { return std::make_pair(nx1, ny1); }


		}
		else { std::cout << "Wrong info entered" << std::endl; }
	}
	return std::make_pair(-1, -1);


}