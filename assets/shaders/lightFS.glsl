#version 410

out vec4 FragColor;

in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;

uniform vec3 lightDirection;

uniform vec4 ambientMaterialColour;
uniform vec4 diffuseMaterialColour;
uniform vec4 specularMaterialColour;
uniform float specularPower=25.0f;

uniform vec4 ambientLightColour=vec4(1.0f,1.0f,1.0f,1.0f);
uniform vec4 diffuseLightColour=vec4(1.0f,1.0f,1.0f,1.0f);
uniform vec4 specularLightColour=vec4(1.0f,1.0f,1.0f,1.0f);

void main()
{
	vec3 lightDir=normalize(-lightDirection);
	float diffuseTerm = dot(vertexNormalOut, lightDir);
	vec3 halfWayVec = normalize(cameraDirectionOut + lightDir);
	float specularTerm = pow(dot(vertexNormalOut, halfWayVec), specularPower);

	FragColor = (ambientMaterialColour*ambientLightColour) + (diffuseMaterialColour*diffuseLightColour*diffuseTerm) + (specularMaterialColour*specularLightColour*specularTerm);
}
