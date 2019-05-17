#pragma once
#include "ShaderResources.h"
#include "../Utilities/utilities.h"

class ShaderManager
{
public:
	ShaderResources* sr;
	GLint shaderId;

	int Load();

	ShaderManager();
	~ShaderManager();
};

