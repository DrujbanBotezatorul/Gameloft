#pragma once
#include "ObjectScene.h"
#include "Vertex.h"
class Terrain :
	public ObjectScene
{
public:
	int nrCells;
	float dimCells, offsetY;

	void CreateModel(Vector3);
	//void Draw(Vector3);

	Terrain();
	~Terrain();
};

