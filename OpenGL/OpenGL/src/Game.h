#pragma once
#include <iostream>

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include "Material.h"
#include "Renderer.h"

#include "GLFW/glfw3.h"

class Game
{
private:
	//Shader w_Shader = Shader("res/shaders/Basic.shader"); //w_ is for window
	GLFWwindow* w_Window;
	int w_Width, w_Height, w_FbW, w_FbH, w_GLMajor, w_GLMinor;
	const char* w_Title;
	bool w_Resizeable;

	glm::vec3 m_Position, m_Rotation, m_Scale; //m_ is for matrices
	glm::mat4 m_ModelMatrix;

	glm::mat4 m_ViewMatrix;
	glm::vec3 m_CameraPos;
	glm::vec3 m_WorldUp;
	glm::vec3 m_CamFront;

	glm::mat4 m_ProjectionMatrix;
	float m_Fov;
	float m_NearPlane;
	float m_FarPlane;

	glm::vec3 l_LightPos0; //l_ is for lighting
	//Private functions
	void init();
	void initOpenGLOptions();
	void initShader();
	void initMatrices();

public:
	//Constructors/Destructors
	Game(const int width, const int height, const char* title, int GLMajor, int GLMinor, bool resizable);
	virtual ~Game();

	//Functions
	void Update();
	void Render(Renderer renderer);

	void updateShader();
	void updateMatrices();
	
	//Window accessors
	inline GLFWwindow* GetWindow() const { return w_Window; }
	inline int GetFbW() const { return w_FbW; }
	inline int GetFbH() const { return w_FbH; }

	//Matrix accessors
	inline glm::mat4 GetModelMatrix() { return m_ModelMatrix; }
	inline glm::mat4 GetViewMatrix() { return m_ViewMatrix; }
	inline glm::mat4 GetProjectionMatrix() { return m_ProjectionMatrix; }
};