#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Vertex.h"

using namespace std;

class Model
{
public:
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	int nrVertices, nrIndices;
	void loadNFG(const char* location);
	Model(const char* location);
	~Model();
};

