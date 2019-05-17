#pragma once
#include <string>

using namespace std;

class ShaderResources
{
public:
	GLuint id;
	string fileVS;
	string fileFS;

	ShaderResources();
	~ShaderResources();
};

