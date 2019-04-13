#include "stdafx.h"
#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}


ResourceManager* ResourceManager::spInstance = NULL;
ResourceManager* ResourceManager::getInstance()
{
	if (!spInstance)
	{
		spInstance = new ResourceManager();
	}
	return spInstance;
}
void ResourceManager::metodaInstanta() {
	//nitel cod
}
