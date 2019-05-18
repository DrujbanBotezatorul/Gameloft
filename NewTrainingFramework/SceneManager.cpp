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

void SceneManager::Init()
{
	using namespace rapidxml;
	xml_document<> doc;
	ifstream file("../Resources/sceneManager.xml");
	stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();

	xml_node<> *pNode = pRoot->first_node("backgroundColor")->first_node();
	bgColor.x = atof(pNode->value());

	pNode = pNode->next_sibling();
	bgColor.y = atof(pNode->value());

	pNode = pNode->next_sibling();
	bgColor.z = atof(pNode->value());

	for (xml_node<> *pNode = pRoot->first_node("cameras")->first_node("camera"); pNode; pNode = pNode->next_sibling("camera"))
	{
		CameraScene camera;

		xml_attribute<> *pAttr = pNode->first_attribute();
		camera.id = atoi(pAttr->value());

		xml_node<> *currentNode = pNode->first_node("position");
		xml_node<> *currentNodeVector = currentNode->first_node();
		camera.position.x = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		camera.position.y = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		camera.position.z = atof(currentNodeVector->value());

		currentNode = pNode->first_node("target");
		currentNodeVector = currentNode->first_node();
		camera.target.x = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		camera.target.y = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		camera.target.z = atof(currentNodeVector->value());

		currentNode = pNode->first_node("up");
		currentNodeVector = currentNode->first_node();
		camera.up.x = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		camera.up.y = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		camera.up.z = atof(currentNodeVector->value());

		currentNode = pNode->first_node("translationSpeed");
		camera.translationSpeed = atof(currentNode->value());

		currentNode = pNode->first_node("rotationSpeed");
		camera.rotationSpeed = atof(currentNode->value());

		currentNode = pNode->first_node("fov");
		camera.Fov = atof(currentNode->value());

		currentNode = pNode->first_node("near");
		camera.Near = atof(currentNode->value());

		currentNode = pNode->first_node("far");
		camera.Far = atof(currentNode->value());

		cameras.push_back(camera);

	}

	for (xml_node<> *pNode = pRoot->first_node("objects")->first_node("object"); pNode; pNode = pNode->next_sibling("object"))
	{
		ObjectScene object;
		vector<int> textureIds;

		xml_attribute<> *pAttr = pNode->first_attribute();
		object.id = atoi(pAttr->value());

		xml_node<> *currentNode = pNode->first_node("model");
		object.modelId = atoi(currentNode->value());

		currentNode = pNode->first_node("shader");
		object.shaderId = atoi(currentNode->value());

		currentNode = pNode->first_node("type");
		object.type = currentNode->value();

		if (pNode->first_node("wired/"))
		{

		}

		currentNode = pNode->first_node("blend");
		object.blend = currentNode->value();

		currentNode = pNode->first_node("name");
		object.name = currentNode->value();

		if (pNode->first_node("color"))
		{
			currentNode = pNode->first_node("color");
			xml_node<> *currentNodeVector = currentNode->first_node();
			object.colors.x = atof(currentNodeVector->value());

			currentNodeVector = currentNodeVector->next_sibling();
			object.colors.y = atof(currentNodeVector->value());

			currentNodeVector = currentNodeVector->next_sibling();
			object.colors.z = atof(currentNodeVector->value());

		}

		currentNode = pNode->first_node("textures");
		for (xml_node<> *currentNodeVector = currentNode->first_node("texture"); currentNodeVector; currentNodeVector = currentNodeVector->next_sibling("texture"))
		{
			int textureId = atoi(currentNodeVector->first_attribute()->value());
			textureIds.push_back(textureId);
		}

		object.textureIds = textureIds;

		currentNode = pNode->first_node("position");
		xml_node<> *currentNodeVector = currentNode->first_node();
		object.position.x = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		object.position.y = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		object.position.z = atof(currentNodeVector->value());

		currentNode = pNode->first_node("rotation");
		currentNodeVector = currentNode->first_node();
		object.rotation.x = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		object.rotation.y = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		object.rotation.z = atof(currentNodeVector->value());

		currentNode = pNode->first_node("scale");
		currentNodeVector = currentNode->first_node();
		object.scale.x = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		object.scale.y = atof(currentNodeVector->value());

		currentNodeVector = currentNodeVector->next_sibling();
		object.scale.z = atof(currentNodeVector->value());

		objects.push_back(object);

	}

	activeCamera = atoi(pRoot->first_node("activeCamera")->value());

}

void SceneManager::Draw(ESContext *esContext)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (std::vector<ObjectScene>::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		it->Draw();
	}


	//eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void SceneManager::Update()
{

}
