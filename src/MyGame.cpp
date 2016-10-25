#include "MyGame.h"

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";

MyGame::MyGame()
{

}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	/*
	Vertex verts[] = {
		{vec3(-0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,3.0f)},
		{vec3(0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,3.0f)},
		{vec3(-0.5f,  0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,0.0f)},
		{vec3(-0.5f, 0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,0.0f)},
		{vec3(0.5f, 0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,0.0f)},
		{vec3(0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,3.0f)}
	};
	*/



	string vsPath = ASSET_PATH + SHADER_PATH + "/simpleVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/textureFS.glsl";

	//lets load texture
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";
	
}

void MyGame::destroyScene()
{

}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 100.0f);
	m_ViewMatrix = lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m_ModelMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -0.2f));
}

void MyGame::render()
{
	GameApplication::render();
}
