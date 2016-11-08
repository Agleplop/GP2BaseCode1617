#include "ModelLoading.h"

//http://ogldev.atspace.co.uk/www/tutorial22/tutorial22.html
GameObject * loadModelFromFile(const string & filename)
{
	LOG(INFO,"Attempting to load model %s",filename.c_str());
	GameObject *gameObject = new GameObject();
	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	const aiScene* scene = aiImportFile(filename.c_str(), aiProcess_JoinIdenticalVertices|aiProcess_Triangulate | aiProcess_FlipUVs|aiProcess_GenSmoothNormals);

	if (scene)
	{
		LOG(INFO,"Parsing Model %s",filename.c_str());
		const aiMesh * mesh=scene->mMeshes[0];

		vector<int> indices;
		vector<Vertex> verts;

		for (int f = 0; f < mesh->mNumFaces; f++)
		{
			const aiFace * face = &mesh->mFaces[f];
			for (int i = 0; i < face->mNumIndices; i++)
			{
				int index = face->mIndices[i];
				indices.push_back(index);
			}
		}

		for (int v = 0; v < mesh->mNumVertices; v++)
		{
			Vertex ourV;

			aiVector3D position = mesh->mVertices[v];
			if (mesh->HasNormals())
			{
				aiVector3D normals = mesh->mNormals[v];
				ourV.normals = vec3(normals.x, normals.y, normals.z);
			}

			aiColor4D colour = aiColor4D(1.0f, 1.0f, 1.0f, 1.0f);

			if (mesh->mColors[0] != nullptr)
			{
				colour = mesh->mColors[v][0];
			}

			ourV.position = vec3(position.x, position.y, position.z);
			ourV.colour = vec4(colour.r, colour.g, colour.b, colour.a);


			verts.push_back(ourV);
		}


		gameObject->copyVertexData(&verts[0], verts.size(), &indices[0], indices.size());
	}
	else
	{
		LOG(ERROR,"Error Parsing Model %s",aiGetErrorString());
	}

	aiReleaseImport(scene);


	return gameObject;
}
