#pragma once
#include "../rapidxml-1.13/rapidxml_utils.hpp"
#include "CameraScene.h"
#include "ObjectScene.h"
#include <vector>
#include <string>
#include <sstream>

class SceneManager
{
private:
	static SceneManager* spInstance;
	SceneManager();
public:
	~SceneManager();

	Vector3 bgColor;
	vector<CameraScene> cameras;
	vector<ObjectScene> objects;
	int activeCamera;


	void Init();//initializari - pot fi si in constructor
	static SceneManager* getInstance();
	void metodaInstanta();//o metoda oarecare, nestatica
	void freeResources();//eliberarea zonelor de memorie alocate dinamic - se poate realiza si in destructor

};

