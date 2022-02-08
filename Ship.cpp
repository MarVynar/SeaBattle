#include "Ship.h"
#include <math.h>
#include <iostream>

using namespace std;

Ship::Ship(unsigned int num, char x, int y)
{
	alive = true;
	this->num = num;
	aliveNum = num;
	if (num == 1) {

		blocks = new ShipBlock(x, y);
	}
	else {
		
	}
}

Ship::Ship(unsigned int num, char x1, int y1, char x2, int y2)
{
	alive = true;
	this->num = num;
	aliveNum = num;
	if ((num > 1)&& (num<=4)) {
		blocks = new ShipBlock[num];

		int hDifference = (int)x1 - (int)x2;

		int vDifference = y1 - y2;
	
		if ((((hDifference )==0)&&(abs(vDifference) ==1)) || ((vDifference == 0) && (abs((hDifference)) == 1))) {

			for (int i = 1; i <= num; i++) {

		
				blocks[i - 1] = ShipBlock((char)((int)x1 - hDifference * (i - 1)), y1 - vDifference * (i - 1));
				
				cout << "BlockCoords " << (char)((int)x1 - hDifference * (i - 1)) << "-" << y1 - vDifference * (i - 1) << endl;
			}
		}

			

	}
	else {
		std::cout << "wrong num" << std::endl;
	}


}

Ship::~Ship()
{
}

ShipBlock* Ship::checkCoords(char letter, int number) ////Ptr!
{
	for (int i = 0; i < num; i++) {
		if (std::make_pair(letter, number) == blocks[i].getCoords()) {
			return &blocks[i]; 
		}

	}

	return nullptr;
}



void Ship::showCoords()
{
	for (int i = 0; i < num; i++) {
		std::cout << "Num " << num << " - " << blocks[i].getCoords().first << " - " << blocks[i].getCoords().second << std::endl;
	}
	std::cout << "----------" << std::endl;
}

std::string Ship::getCoords()
{
	std::string str = "";
	for (int i = 0; i < num; i++) {

		str += blocks[i].getCoords().first;
		std::cout << "Coords " << blocks[i].getCoords().second<<"+" <<std::to_string(blocks[i].getCoords().second) << std::endl;
	//	str += (char)( blocks[i].getCoords().second -1 );
		str += std::to_string(blocks[i].getCoords().second);

	}
	std::cout << "GetCoords " << str << std::endl;
	return str;
}

string Ship::damage(char x, int y)
{
	if (checkCoords(x, y) == nullptr) { return "+"; }
	else {
	
		aliveNum--;
		if (aliveNum == 0) {

			for (int i = 0; i < num; i++) {
				blocks[i].kill();
				
				
			}
			return "O";

		}
		else {
			checkCoords(x, y)->damage();

			return "X";

		}


	}

	
}
