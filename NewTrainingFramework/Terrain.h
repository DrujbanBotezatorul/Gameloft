#pragma once
#include "ObjectScene.h"
class Terrain :
	public ObjectScene
{
public:
	int nrCells, dimCells, offsetY;

	Terrain();
	~Terrain();
};

