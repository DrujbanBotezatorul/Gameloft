#pragma once
#include "../rapidxml-1.13/rapidxml_utils.hpp"
#include "ModelResources.h"
#include "ShaderResources.h"
#include "TextureResources.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ResourceManager
{
private:
	static ResourceManager* spInstance;
	ResourceManager();
public:
	~ResourceManager();

	vector<ModelResources> models;
	vector<ShaderResources> shaders;
	vector<TextureResources> textures;
	
	void Init();//initializari - pot fi si in constructor
	static ResourceManager* getInstance();
	void metodaInstanta();//o metoda oarecare, nestatica
	void freeResources();//eliberarea zonelor de memorie alocate dinamic - se poate realiza si in destructor

};

