#include "MyGame.h"

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";

MyGame::MyGame()
{

}

MyGame::~MyGame()
{
	m_TestObject = nullptr;
	m_TestObject1 = nullptr;
}

void MyGame::initScene()
{
	Vertex verts[] = {
		{vec3(-0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,3.0f)},
		{vec3(0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,3.0f)},
		{vec3(-0.5f,  0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,0.0f)},
		{vec3(-0.5f, 0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,0.0f)},
		{vec3(0.5f, 0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,0.0f)},
		{vec3(0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,3.0f)}
	};

	m_TestObject = new GameObject();
	m_TestObject1 = new GameObject();

	string vsPath = ASSET_PATH + SHADER_PATH + "/simpleVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/textureFS.glsl";

	m_TestObject->LoadShaders(vsPath, fsPath);
	m_TestObject1->LoadShaders(vsPath, fsPath);


	//lets load texture
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";

	m_TestObject->LoadTexture(texturePath);
	m_TestObject1->LoadTexture(texturePath);
	
	m_TestObject->CopyVertexData(verts, 6);
	m_TestObject1->CopyVertexData(verts, 6);

}

void MyGame::destroyScene()
{
	if (m_TestObject)
	{
		m_TestObject->OnDestroy();
		delete m_TestObject;
		m_TestObject = nullptr;
	}
	if (m_TestObject1)
	{
		m_TestObject1->OnDestroy();
		delete m_TestObject1;
		m_TestObject1 = nullptr;
	}
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 100.0f);
	m_ViewMatrix = lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m_ModelMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -0.2f));
	
	m_TestObject->OnUpdate();
	m_TestObject1->OnUpdate();

	m_TestObject->TransformObject(0.01f, 0);
	m_TestObject->RotateObject(0, 0, -0.01f);
	m_TestObject->ScaleObject(-0.01f, 0.01f, 0);

	m_TestObject1->TransformObject(-0.01f, 0);
	m_TestObject1->RotateObject(0, 0, 0.01f);
	m_TestObject1->ScaleObject(0.01f, -0.01f, 0);
}

void MyGame::render()
{
	GameApplication::render();
	m_TestObject->OnRender(m_ViewMatrix, m_ProjMatrix);
	m_TestObject1->OnRender(m_ViewMatrix, m_ProjMatrix);
}
