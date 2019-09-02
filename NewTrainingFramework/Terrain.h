#pragma once
#include "ObjectScene.h"
#include "Vertex.h"
class Terrain :
	public ObjectScene
{
public:
	int nrCells;
	float dimCells, offsetY;

	void GenerateModel(Vector3);
	//void Draw(Vector3);

	Terrain();
	~Terrain();
};

