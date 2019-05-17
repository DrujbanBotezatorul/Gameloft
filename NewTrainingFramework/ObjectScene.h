#pragma once
#include <string>
#include <vector>
#include "../Utilities/utilities.h"


using namespace std;

class ObjectScene
{
public:
	GLint id, modelId, shaderId;
	string type, blend, name;
	vector<int> textureIds;
	Vector3 colors, position, rotation, scale;
	bool depthTest;

	ObjectScene();
	~ObjectScene();
};

