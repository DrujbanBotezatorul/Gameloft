#include "stdafx.h"
#include "ShaderManager.h"


ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
}

int ShaderManager::Load()
{
	sr->fileVS = "../" + sr->fileVS;
	sr->fileFS = "../" + sr->fileFS;

	const char *fileVS = sr->fileVS.c_str();
	const char *fileFS = sr->fileFS.c_str();

	vertexShader = esLoadShader(GL_VERTEX_SHADER, (char*)fileVS);

	if (vertexShader == 0)
		return -1;

	fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, (char*)fileFS);

	if (fragmentShader == 0)
	{
		glDeleteShader(vertexShader);
		return -2;
	}

	program = esLoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	positionAttribute = glGetAttribLocation(program, "a_posL");
	colorAttribute = glGetAttribLocation(program, "a_color");
	matrixUniform = glGetUniformLocation(program, "u_rot");
	uvAttribute = glGetAttribLocation(program, "a_uv");
	uvBlendAttribute = glGetAttribLocation(program, "a_uv_blend");
	textureUniform[0] = glGetUniformLocation(program, "u_texture");
	textureUniform[1] = glGetUniformLocation(program, "u_texture1");
	textureUniform[2] = glGetUniformLocation(program, "u_texture2");
	textureUniform[3] = glGetUniformLocation(program, "u_texture3");

	return 0;
}
