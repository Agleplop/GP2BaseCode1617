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

	void OnRender(mat4& view, mat4& projection);
	void OnUpdate();
	void OnInit();
	void OnDestroy();

	void LoadTexture(const string& texture);
	void LoadShaders(const string& vsFileName, const string& fsFileName);
	void CopyVertexData(Vertex *pVerts, int numberOfVertices);
private:
	GLuint m_VBO;
	GLuint m_VAO;

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
protected:
};

#endif
