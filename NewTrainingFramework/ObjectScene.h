#pragma once
#include <string>
#include <vector>
#include "../Utilities/utilities.h"


using namespace std;

class ObjectScene
{
public:
	int id, modelId, shaderId;
	string type, blend, name;
	vector<int> textureIds;
	Vector3 position, rotation, scale;

	ObjectScene();
	~ObjectScene();
};

