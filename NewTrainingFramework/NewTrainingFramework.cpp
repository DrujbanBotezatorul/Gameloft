// NewTrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Vertex.h"
#include "Shaders.h"
#include <conio.h>
#include "Globals.h"
#include "Camera.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


GLuint vboId, verticesId, indicesId;
Shaders myShaders;
GLfloat alpha = 0, pas = 0.01f;
Camera camera;

int nrVertices, nrIndices, model[400][3];
float pos[400][3];

void getModel(char* file, int *nrVertices, int *nrIndices, float poz[400][3], int model[400][3])
{
	ifstream modelFile (file);
	string line;
	int i = 0, x;

	getline(modelFile, line);
	sscanf(line.c_str(), "NrVertices: %d", nrVertices);
	while (getline(modelFile, line))
	{
		if (line[0] == 'N')
		{
			sscanf(line.c_str(), "NrIndices: %d", nrIndices);
			break;
		}
		sscanf(line.c_str(), "   %d. pos:[%f, %f, %f]", &x, &poz[i][0], &poz[i][1], &poz[i][2]);
		//cout << poz[i][0] << ' '<< poz[i][1] << '\n';
		i++;

	 }

	i = 0;

	while (getline(modelFile, line))
	{
		sscanf(line.c_str(), "   %d.    %d,    %d,    %d", &x, &model[i][0], &model[i][1], &model[i][2]);
		//cout << model[i][0] << ' ' << model[i][1] << model[i][2] << '\n';
		i++;
	}

	modelFile.close();

}

int Init ( ESContext *esContext )
{
	

	getModel("C:\\Users\\Apetroaie Claudiu\\Desktop\\Gameloft\\First\\proiect_2015\\NewResourcesPacket\\Models\\Croco.nfg", &nrVertices, &nrIndices, pos, model);

	glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );

	//triangle data (heap)
	Vertex verticesData[6];
	Vertex vertices[1000];
	int i;

	for (i = 0; i < nrVertices; i++)
	{
		vertices[i].pos.x = pos[i][0];
		vertices[i].pos.y = pos[i][1];
		vertices[i].pos.z = pos[i][2];

		vertices[i].color.x = 0.0f;
		vertices[i].color.x = 1.0f;
		vertices[i].color.x = 0.0f;
	}

	verticesData[0].pos.x = -0.5f;  verticesData[0].pos.y = 0.5f;  verticesData[0].pos.z = 0.0f;
	verticesData[1].pos.x = -0.5f;  verticesData[1].pos.y = -0.5f;  verticesData[1].pos.z = 0.0f;
	verticesData[2].pos.x = 0.5f;  verticesData[2].pos.y = -0.5f;  verticesData[2].pos.z = 0.0f;
	verticesData[3].pos.x = -0.5f;  verticesData[3].pos.y = 0.5f;  verticesData[3].pos.z = 0.0f;
	verticesData[4].pos.x = 0.5f;  verticesData[4].pos.y = 0.5f;  verticesData[4].pos.z = 0.0f;
	verticesData[5].pos.x = 0.5f;  verticesData[5].pos.y = -0.5f;  verticesData[5].pos.z = 0.0f;

	//verticesData[6].pos.x = -0.5f;  verticesData[6].pos.y = 0.5f;  verticesData[6].pos.z = -0.5f;
	//verticesData[7].pos.x = -0.5f;  verticesData[7].pos.y = -0.5f;  verticesData[7].pos.z = -0.5f;
	//verticesData[8].pos.x = 0.5f;  verticesData[8].pos.y = -0.5f;  verticesData[8].pos.z = -0.5f;
	//verticesData[9].pos.x = -0.5f;  verticesData[9].pos.y = 0.5f;  verticesData[9].pos.z = -0.5f;
	//verticesData[10].pos.x = 0.5f;  verticesData[10].pos.y = 0.5f;  verticesData[10].pos.z = -0.5f;
	//verticesData[11].pos.x = 0.5f;  verticesData[11].pos.y = -0.5f;  verticesData[11].pos.z = -0.5f;

	//verticesData[12].pos.x = -0.5f;  verticesData[12].pos.y = 0.5f;  verticesData[12].pos.z = 0.0f;
	//verticesData[13].pos.x = -0.5f;  verticesData[13].pos.y = -0.5f;  verticesData[13].pos.z = 0.0f;
	//verticesData[14].pos.x = 0.5f;  verticesData[14].pos.y = -0.5f;  verticesData[14].pos.z = 0.0f;
	//verticesData[15].pos.x = -0.5f;  verticesData[15].pos.y = 0.5f;  verticesData[15].pos.z = 0.0f;
	//verticesData[16].pos.x = 0.5f;  verticesData[16].pos.y = 0.5f;  verticesData[16].pos.z = 0.0f;
	//verticesData[17].pos.x = 0.5f;  verticesData[17].pos.y = -0.5f;  verticesData[17].pos.z = 0.0f;

	//verticesData[6].pos.x = -0.5f;  verticesData[6].pos.y = 0.5f;  verticesData[6].pos.z = -0.5f;
	//verticesData[7].pos.x = -0.5f;  verticesData[7].pos.y = -0.5f;  verticesData[7].pos.z = -0.5f;
	//verticesData[8].pos.x = 0.5f;  verticesData[8].pos.y = -0.5f;  verticesData[8].pos.z = -0.5f;
	//verticesData[9].pos.x = -0.5f;  verticesData[9].pos.y = 0.5f;  verticesData[9].pos.z = -0.5f;
	//verticesData[10].pos.x = 0.5f;  verticesData[10].pos.y = 0.5f;  verticesData[10].pos.z = -0.5f;
	//verticesData[11].pos.x = 0.5f;  verticesData[11].pos.y = -0.5f;  verticesData[11].pos.z = -0.5f;

	verticesData[0].color.x = 1.0f;  verticesData[0].color.y = 0.0f;  verticesData[0].color.z = 0.0f;
	verticesData[1].color.x = 0.0f;  verticesData[1].color.y = 1.0f;  verticesData[1].color.z = 0.0f;
	verticesData[2].color.x = 0.0f;  verticesData[2].color.y = 0.0f;  verticesData[2].color.z = 1.0f;
	verticesData[3].color.x = 1.0f;  verticesData[3].color.y = 0.0f;  verticesData[3].color.z = 0.0f;
	verticesData[4].color.x = 0.0f;  verticesData[4].color.y = 1.0f;  verticesData[4].color.z = 0.0f;
	verticesData[5].color.x = 0.0f;  verticesData[5].color.y = 0.0f;  verticesData[5].color.z = 1.0f;

	//verticesData[6].color.x = 1.0f;  verticesData[6].color.y = 0.0f;  verticesData[6].color.z = 0.0f;
	//verticesData[7].color.x = 0.0f;  verticesData[7].color.y = 1.0f;  verticesData[7].color.z = 0.0f;
	//verticesData[8].color.x = 0.0f;  verticesData[8].color.y = 0.0f;  verticesData[8].color.z = 1.0f;
	//verticesData[9].color.x = 1.0f;  verticesData[9].color.y = 0.0f;  verticesData[9].color.z = 0.0f;
	//verticesData[10].color.x = 0.0f;  verticesData[10].color.y = 1.0f;  verticesData[10].color.z = 0.0f;
	//verticesData[11].color.x = 0.0f;  verticesData[11].color.y = 0.0f;  verticesData[11].color.z = 1.0f;

	//buffer object
	//glGenBuffers(1, &vboId);
	//glBindBuffer(GL_ARRAY_BUFFER, vboId);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(verticesData), verticesData, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &verticesId);
	glBindBuffer(GL_ARRAY_BUFFER, verticesId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pos), pos, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indicesId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model), model, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//creation of shaders and program 
	return myShaders.Init("../Resources/Shaders/TriangleShaderVS.vs", "../Resources/Shaders/TriangleShaderFS.fs");

}

void Draw ( ESContext *esContext )
{
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(myShaders.program);

	//glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBindBuffer(GL_ARRAY_BUFFER, verticesId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesId);

	
	if(myShaders.positionAttribute != -1)
	{
		glEnableVertexAttribArray(myShaders.positionAttribute);
		glVertexAttribPointer(myShaders.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	}

	if(myShaders.colorAttribute != -1)
	{
		glEnableVertexAttribArray(myShaders.colorAttribute);
		glVertexAttribPointer(myShaders.colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(Vector3));
	}

	Matrix mr;
	//mr.SetRotationZ(alpha);
	mr = camera.getViewMatrix() * camera.getPerspectiveMatrix();
	//mr = camera.getViewMatrix();

	if(myShaders.matrixUniform != -1)
	{
		glUniformMatrix4fv(myShaders.matrixUniform, 1, GL_FALSE, (GLfloat*)mr.m);
	}

	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, nrIndices, GL_UNSIGNED_SHORT, 0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

void Update ( ESContext *esContext, float deltaTime )
{
	camera.updateDeltaTime(deltaTime);

	alpha += pas;
	//pas *= (-1);
	if (alpha > 2 * PI)
	{
		alpha -= 2*PI;
	}
}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{
	

	switch (key)
	{
	case('w'): 
	case('W'):
		{
			camera.moveOy(-1);
			break;
		}
	case('s'):
	case('S'):
		{
			camera.moveOy(1);
			break;
		}
	case('a'):
	case('A'):
	{
		camera.moveOx(-1);
		break;
	}

	case('d'):
	case('D'):
	{
		camera.moveOx(1);
		break;
	}

	case('q'):
	case('Q'):
	{
		camera.moveOz(-1);
		break;
	}

	case('e'):
	case('E'):
	{
		camera.moveOz(1);
		break;
	}

	case(VK_RIGHT):
	{
		camera.rotateOy(1);
		break;
	}
	case(VK_LEFT):
	{
		camera.rotateOy(-1);
		break;
	}
	case(VK_UP):
	{
		camera.rotateOx(-1);
		break;
	}
	case(VK_DOWN):
	{
		camera.rotateOx(1);
		break;
	}
	case('l'):
	case('L'):
	{
		camera.rotateOz(-1);
		break;
	}
	case('p'):
	case('P'):
	{
		camera.rotateOz(1);
		break;
	}


	}


}

void CleanUp()
{
	glDeleteBuffers(1, &vboId);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//identifying memory leaks
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 

	ESContext esContext;

    esInitContext ( &esContext );

	esCreateWindow ( &esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if ( Init ( &esContext ) != 0 )
		return 0;

	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();

	
	printf("Press any key...\n");
	_getch();

	
	return 0;
}

