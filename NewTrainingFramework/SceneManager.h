#pragma once
#include <vector>
#include "CameraScene.h"
#include "ObjectScene.h"

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

