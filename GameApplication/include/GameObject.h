#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Vertex.h"
#include "Texture.h"
#include "Shader.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void onUpdate();
	void onRender(mat4& view, mat4& projection);
	void onInit();
	void onDestroy();

	void addChild(shared_ptr<GameObject> gameobject);

	mat4& getModelMatrix()
	{
		return m_Model;
	}

	void setPosition(vec3& pos)
	{
		m_Position = pos;
	};

	void setRotation(vec3& rot)
	{
		m_Rotation = rot;
	};

	void setScale(vec3& scale)
	{
		m_Scale = scale;
	};

	vec3& getPosition()
	{
		return m_Position;
	};

	vec3& getRotation()
	{
		return m_Rotation;
	};

	vec3& getScale()
	{
		return m_Scale;
	};

	void rotate(const vec3& delta);

	void loadTextureFromFile(const string& filename);
	void loadShadersFromFile(const string& vsFilename, const string& fsFilename);
	void copyVertexData(Vertex *pVertex, int numberOfVertices, int *pIndices, int numberOfIndices);
private:
	GameObject * m_pParent;
	vector<shared_ptr<GameObject> > m_ChildrenGameObjects;

	vec3 m_Position;
	vec3 m_Rotation;
	vec3 m_Scale;

	mat4 m_TranslationMatrix;
	mat4 m_ScaleMatrix;
	mat4 m_RotationMatrix;
	mat4 m_Model;

	GLuint m_VBO;
	GLuint m_EBO;
	GLuint m_VAO;
	int m_NumberOfVerts;
	int m_NumberOfIndices;

	//Shader Program
	GLuint m_ShaderProgram;
	GLuint m_Texture;
	GLuint m_Sampler;

	//Materials

};

#endif
