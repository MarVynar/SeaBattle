#pragma once
#include "GameData.h"

class GraphicCore
{

	void showMyField();
	void showEnemyField();


	GameData* gamedata;


public:
	GraphicCore(GameData * gamedata);
	GraphicCore(const GraphicCore &core);
	~GraphicCore();



	void operator = (const GraphicCore & core);

	void updateScreen();


};

