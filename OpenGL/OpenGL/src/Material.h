#include "Shader.h"
#include "vendor/glm/vec2.hpp"
#include "vendor/glm/vec3.hpp"
#include "vendor/glm/vec4.hpp"
#include "vendor/glm/gtc/type_ptr.hpp"

class Material
{
private:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	int diffuseTex;
	int specularTex;
public:

	Material(
		glm::vec3 ambient,
		glm::vec3 diffuse,
		glm::vec3 specular,
		int diffuseTex,
		int specularTex
	)
	{
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->diffuseTex = diffuseTex;
		this->specularTex = specularTex;
	}

	~Material()
	{

	}

	void sendToShader(Shader& shader)
	{
		shader.SetUniform3fv("material.ambient", 1, glm::value_ptr(ambient));
		shader.SetUniform3fv("material.diffuse", 1, glm::value_ptr(diffuse));
		shader.SetUniform3fv("material.specular", 1, glm::value_ptr(specular));
		shader.SetUniform1i("material.diffuseTex", diffuseTex);
		shader.SetUniform1i("material.specularTex", specularTex);
	}
};