#ifndef _MyGame_H
#define _MyGame_H

#include "GameApplication.h"

class MyGame:public GameApplication
{
public:
	MyGame();
	~MyGame();

	void render();
	void update();
	void initScene();
	void destroyScene();
private:
	GLuint m_VBO;
	GLuint m_VAO;

	//Shader Program
	GLuint m_ShaderProgram;

	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;
	mat4 m_ModelMatrix;

	GLuint m_Texture;
	GLuint m_ClampSampler;

	GameObject * m_TestObject;
	GameObject * m_TeaPot;

	vec3 m_CameraPosition;
	vec3 m_LightDirection;

	vec4 m_AmbientMatColour;
	vec4 m_DiffuseMatColour;
	vec4 m_SpecularMatColour;
	float m_SpecularPower;
};
#endif
