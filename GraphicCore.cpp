#include "GraphicCore.h"
#include <iostream>




GraphicCore::GraphicCore(GameData * gamedata)
{
	this->gamedata = gamedata;
	std::cout <<"GameData"<< this->gamedata<<" = " << gamedata<<std::endl;
}

GraphicCore::GraphicCore(const GraphicCore & core)
{
}

GraphicCore::~GraphicCore()
{
//	delete gamedata; // perekresne vydalennya?


}



void GraphicCore::operator=(const GraphicCore & core)
{
}

void GraphicCore::updateScreen()
{
	//clrscr
	showMyField();
	showEnemyField();

}

void GraphicCore::showMyField()
{
	//std::cout << " ";
	

	for (char letter = 'A'; letter <= 'J'; letter++) { std::cout << letter; } // A - 65 , a - 97
	std::cout << std::endl;
	for (int num = 1; num <= 10; num++) {
	//	std::cout << num;
	//	for (int i = 1; i <= 10; i++)
		for (char i = 'A'; i <= 'J'; i++)
		{ 
			//std::cout << i;
			bool selected = false;


			for (auto it : gamedata->ships)
			{
			
				//if (it->checkCoords(i, num) != '*') { selected = true; std::cout << it->checkCoords(i, num); break; }
				if (it->checkCoords(i, num) != nullptr) { selected = true; std::cout << it->checkCoords(i, num)->getSymbol(); break; }
	
			}

			if (!selected)	std::cout << "*";
		}
		std::cout << num<< std::endl;
	}
	
	std::cout << std::endl;
}

void GraphicCore::showEnemyField()
{
	//std::cout << " ";


	for (char letter = 'A'; letter <= 'J'; letter++) { std::cout << letter; } // A - 65 , a - 97
	std::cout << std::endl;
	for (int num = 1; num <= 10; num++) {
		//std::cout << num;
		for (char i = 'A'; i <= 'J'; i++)
		{
			bool selected = false;
				
			for (auto it : gamedata->shots) {

				if ((i == std::get<0>(it)) && (num == std::get<1>(it))) {
					selected = true;
					std::cout << std::get<2>(it);
					break;
				}
			}

			if (!selected)	std::cout << "*";
		}
		std::cout << num << std::endl;
	}

	std::cout << std::endl;
}


