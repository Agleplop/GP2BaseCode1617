#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Shader.h"
#include "Texture.h"
#include "Vertex.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void onRender(mat4& view,mat4& projection);
	void onUpdate();
	void onInit();
	void onDestroy();

	void loadTexture(const string& filename);
	void loadShaders(const string& vsFilename, const string& fsFilename);
	void copyVertexData(Vertex *pVerts, int numberOfVertcies, int * indices, int numberOfIndices);

	void setCameraPostion(vec3 &position)
	{
		m_CameraPosition = position;
	};

	void setLightDirection(vec3 &direction)
	{
		m_lightDirection = direction;
	};

	void setAmbientMatColour(vec4 &colour)
	{
		m_AmbientMatColour = colour;
	};

	void setDiffuseMatColour(vec4 &colour)
	{
		m_DiffuseMatColour = colour;
	};

	void setSpecularMatColour(vec4 &colour)
	{
		m_SpecularMatColour = colour;
	};

	void setSpecularPower(float &value)
	{
		m_SpecularPower = value;
	};
private:
	GLuint m_VBO;
	GLuint m_VAO;

	GLuint m_ElementBuffer;

	//Shader Program
	GLuint m_ShaderProgram;

	mat4 m_ModelMatrix;

	GLuint m_Texture;
	GLuint m_ClampSampler;

	vec3 m_Position;
	vec3 m_Rotation;
	vec3 m_Scale;

	mat4 m_TranslationMatrix;
	mat4 m_RotationMatrix;
	mat4 m_ScaleMatrix;

	int m_NumberOfVertices;
	int m_NumberOfIndices;

	vec3 m_CameraPosition;

	vec3 m_lightDirection;

	vec4 m_AmbientMatColour;
	vec4 m_DiffuseMatColour;
	vec4 m_SpecularMatColour;
	float m_SpecularPower;
protected:
};

#endif
