#include "Game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Game::init()
{
	if (!glfwInit())
		glfwTerminate();

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, w_GLMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, w_GLMinor);
	glfwWindowHint(GLFW_RESIZABLE, w_Resizeable);

	/* Create a windowed mode window and its OpenGL context */
	w_Window = glfwCreateWindow(w_Width, w_Height, w_Title, NULL, NULL);

	glfwGetFramebufferSize(w_Window, &w_FbW, &w_FbH);
	glfwSetFramebufferSizeCallback(w_Window, framebuffer_size_callback);

	if (!w_Window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(w_Window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR: GLEW not initialized" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
}

void Game::initOpenGLOptions()
{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void Game::initMatrices()
{
	m_ModelMatrix = glm::mat4(1.f);
	m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(0.f, 0.f, 0.f));
	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_Rotation.x), m_Position);
	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_Rotation.y), glm::vec3(0.f, 1.f, 0.f));
	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_Rotation.z), glm::vec3(0.f, 0.f, 1.f));
	m_ModelMatrix = glm::scale(m_ModelMatrix, m_Scale);

	m_ViewMatrix = glm::mat4(1.f);
	m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CamFront, m_WorldUp);

	m_ProjectionMatrix = glm::mat4(1.f);
	m_ProjectionMatrix = glm::perspective(m_Fov,
		static_cast<float>(w_FbW / w_FbH),
		m_NearPlane, m_FarPlane);
}

Game::Game(const int width, const int height, const char* title, int GLMajor, int GLMinor, bool resizable)
	: w_Window(), w_Width(width), w_Height(height), w_Title(title),
	w_FbW(0), w_FbH(0), w_GLMajor(GLMajor), w_GLMinor(GLMinor), w_Resizeable(resizable)
{
	m_Position = glm::vec3(0.f);
	m_Rotation = glm::vec3(0.f);
	m_Scale = glm::vec3(1.f);

	m_CameraPos = glm::vec3(0.f, 0.f, 1.f);
	m_WorldUp = glm::vec3(0.f, 1.f, 0.f);
	m_CamFront = glm::vec3(0.f, 0.f, -1.f);

	m_Fov = 1.5789f;
	m_NearPlane = 0.1f;
	m_FarPlane = 1000.f;

	l_LightPos0 = glm::vec3(0.f, 0.f, 1.f);

	init(); //Window and libraries
	initOpenGLOptions(); //Culling, Blending.
	//initShader(); //includes all initial uniform binding
	initMatrices(); //matrices.
}

Game::~Game()
{

}

void Game::Update()
{
	glfwPollEvents();

	updateMatrices();
}

void Game::Render(Renderer renderer)
{
	renderer.Clear();

	glfwSwapBuffers(w_Window);
	glFlush();
}

void Game::updateMatrices()
{
	m_ModelMatrix = glm::mat4(1.f);
	m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(0.f, 0.f, 0.f));
	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_Rotation.x), m_Position);
	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_Rotation.y), glm::vec3(0.f, 1.f, 0.f));
	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_Rotation.z), glm::vec3(0.f, 0.f, 1.f));
	m_ModelMatrix = glm::scale(m_ModelMatrix, m_Scale);
	glfwGetFramebufferSize(w_Window, &w_FbW, &w_FbH);

	m_ProjectionMatrix = glm::mat4(1.f);
	m_ProjectionMatrix = glm::perspective(m_Fov,
		static_cast<float>(w_FbW) / w_FbH,
		m_NearPlane, m_FarPlane);
}