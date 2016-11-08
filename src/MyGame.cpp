#include "MyGame.h"

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";
const std::string MODEL_PATH = "/models";

MyGame::MyGame()
{
	//m_TestObject = nullptr;
	m_TeaPot = nullptr;

	m_CameraPosition = vec3(0.0f, 0.0f, 100.0f);
	m_LightDirection = vec3(0.0f, 0.0f, -1.0f);

	m_AmbientMatColour = vec4(0.0f, 0.5f, 0.0f, 1.0f);
	m_DiffuseMatColour = vec4(0.0f, 0.0f, 0.8f, 1.0f);
	m_SpecularMatColour = vec4(1.0f, 0.0f, 1.0f, 1.0f);
	m_SpecularPower = 0.25f;
}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	Vertex verts[] = {
		{vec3(-0.5f, -0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,3.0f)},
		{vec3(0.5f, -0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,3.0f)},
		{vec3(-0.5f,  0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,0.0f)},
		{vec3(0.5f, 0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,0.0f)}
	};

	int indices[] = { 0, 2, 1,
					1, 2, 3 };


	//m_TestObject = new GameObject();

	string vsPath = ASSET_PATH + SHADER_PATH + "/lightVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/lightFS.glsl";
	//m_TestObject->loadShaders(vsPath, fsPath);

	//lets load texture
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";
	//m_TestObject->loadTexture(texturePath);

	string modelPath = ASSET_PATH + MODEL_PATH + "/utah-teapot.fbx";

	//m_TestObject->copyVertexData(verts, 4, indices, 6);	

	m_TeaPot = loadModelFromFile(modelPath);
	m_TeaPot->loadShaders(vsPath, fsPath);
	
}

void MyGame::destroyScene()
{
	if (m_TeaPot)
	{
		m_TeaPot->onDestroy();
		delete m_TeaPot;
		m_TeaPot = nullptr;
	}

	//
	//if (m_TestObject)
	//{
	//	m_TestObject->onDestroy();
	//	delete m_TestObject;
	//	m_TestObject = nullptr;
	//}
	//
	
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 100.0f);
	m_ViewMatrix = lookAt(m_CameraPosition, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m_ModelMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -0.2f));

	m_TeaPot->setCameraPostion(m_CameraPosition);
	m_TeaPot->setLightDirection(m_LightDirection);

	m_TeaPot->setAmbientMatColour(m_AmbientMatColour);
	m_TeaPot->setDiffuseMatColour(m_DiffuseMatColour);
	m_TeaPot->setSpecularMatColour(m_SpecularMatColour);
	m_TeaPot->setSpecularPower(m_SpecularPower);

	//m_TestObject->onUpdate();
	m_TeaPot->onUpdate();
}

void MyGame::render()
{
	GameApplication::render();
	//m_TestObject->onRender(m_ViewMatrix, m_ProjMatrix);
	m_TeaPot->onRender(m_ViewMatrix, m_ProjMatrix);
}
