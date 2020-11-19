#shader vertex
#version 410 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;

out vec2 v_TexCoord;
out vec3 v_Position;
out vec3 v_Normal;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
	v_Position = vec4(ModelMatrix * position).xyz;
	v_TexCoord = texCoord;
	v_Normal = mat3(ModelMatrix) * normal;

	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * position;
};

#shader fragment
#version 410 core

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
	sampler2D specularTex;
};

layout(location = 0) out vec4 color;

//in
in vec2 v_TexCoord;
in vec3 v_Position;
in vec3 v_Normal;

//Uniforms
uniform Material material;
uniform vec4 u_Color;
uniform vec3 lightPos0;
uniform vec3 cameraPos;

vec3 calculateAmbient(Material material)
{
	return material.ambient;
}

vec3 calculateDiffuse(Material material, vec3 v_Position, vec3 v_Normal)
{
	vec3 posToLightDirVec = normalize(lightPos0 - v_Position);
	float diffuse = clamp(dot(posToLightDirVec, v_Normal), 0, 1);
	vec3 diffuseFinal = material.diffuse * diffuse;

	return diffuseFinal;
}

vec3 calculateSpecular(Material material, vec3 v_Position, vec3 v_Normal, vec3 lightPos0, vec3 cameraPos)
{
	vec3 lightToPosDirVec = normalize(v_Position - lightPos0);
	vec3 reflectDirVec = normalize(reflect(lightToPosDirVec, normalize(v_Normal)));
	vec3 posToViewDirVec = normalize(cameraPos - v_Position);
	float specularConstant = pow(max(dot(posToViewDirVec, reflectDirVec), 0), 20);
	vec3 specularFinal = material.specular * specularConstant;

	return specularFinal;
}

void main()
{
	vec3 ambientFinal = calculateAmbient(material);
	vec3 diffuseFinal = calculateDiffuse(material, v_Position, v_Normal);
	vec3 specularFinal = calculateSpecular(material, v_Position, v_Normal, lightPos0, cameraPos);

	//Attenuation

	//Final:
	vec4 texColor0 = texture(material.diffuseTex, v_TexCoord);
	vec4 texColor1 = texture(material.specularTex, v_TexCoord);
	color = texColor1 * (vec4(ambientFinal, 1.f) + vec4(diffuseFinal, 1.f) + vec4(specularFinal, 1.f));
};


