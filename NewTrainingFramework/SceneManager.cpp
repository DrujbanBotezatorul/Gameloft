#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}


SceneManager* SceneManager::spInstance = NULL;
SceneManager* SceneManager::getInstance()
{
	if (!spInstance)
	{
		spInstance = new SceneManager();
	}
	return spInstance;
}
void SceneManager::metodaInstanta() {
	//nitel cod
}
