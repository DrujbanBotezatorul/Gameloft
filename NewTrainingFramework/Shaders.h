#pragma once
#include "../Utilities/utilities.h"

class Shaders 
{
public:
	GLuint program, vertexShader, fragmentShader;
	char fileVS[260];
	char fileFS[260];
	GLint positionAttribute;
	GLint colorAttribute;
	GLint uvAttribute;
	GLint uvBlendAttribute;
	GLint matrixUniform;
	GLint textureUniform[5];

	int Init(char * fileVertexShader, char * fileFragmentShader);
	~Shaders();
};