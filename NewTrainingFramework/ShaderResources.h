#pragma once
#include <string>

using namespace std;

class ShaderResources
{
public:
	int id;
	string fileVS;
	string fileFS;

	ShaderResources();
	~ShaderResources();
};

