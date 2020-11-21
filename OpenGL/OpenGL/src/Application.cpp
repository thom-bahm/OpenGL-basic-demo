#include "Game.h"

#include <iostream>
#include "Texture.h"
#include "Primitives.h"

//Keyboard Inputs
void updateInput(GLFWwindow* window, glm::vec3& position, glm::vec3& rotation, glm::vec3& scale)
{
	//Position
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
	{
		position.z += 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
	{
		position.x += 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
	{
		position.z -= 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
	{
		position.x -= 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && 
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
	{
		position.y += 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && 
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
	{
		position.y -= 0.01f;
	}
	//Rotation
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && 
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		rotation.y += 1.f;
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && 
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		rotation.y -= 1.f;
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && 
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		rotation.x += 1.f;
	}
	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && 
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		rotation.x -= 1.f;
	}
	//Scale
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		scale += 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
	{
		scale -= 0.01f;
	}
}

int main(void)
{
	glEnable(GL_DEBUG_OUTPUT);
	Game game(1080, 1080, "Engine", 4, 4, true);

	{
		
		float positions[] = { //Quad positions
			//Positions			//Tex Coords		//Normals
		   -0.8f, -0.8f, 0.f,   0.f, 0.0f, 0.0f,	0.f, 0.0f,  1.0f, //0 Bottom Left
			0.8f, -0.8f, 0.f,   1.0f, 0.0f, 0.f,	0.0f, 0.0f, 1.f, //1 Bottom Right
			0.8f, 0.8f, 0.f,    1.0f, 1.0f, 0.f,	0.0f, 0.0f, 1.f, //2 Top right
		   -0.8f, 0.8f, 0.f,    0.0f, 1.0f, 0.f,	0.0f, 0.0f, 1.f  //3 Top Left
		};

		unsigned int indices[] = { //Quad indices
			0, 1, 2,
			2, 3, 0
		};

		VertexArray va;
		VertexBuffer vb(positions, sizeof(float) * 4 * 9);

		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(3);
		layout.Push<float>(3);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		
		//Primitive quadPrim("Quad", 1, 1);
		
		Shader shader("res/shaders/shaders.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		Texture texture0("res/textures/texture_flame_hole_1024.png", 0);
		Texture texture1("res/textures/texture_flame_square-hole_2048.png", 1);
		texture0.Bind(texture0.GetSlot());
		texture1.Bind(texture1.GetSlot());

		Material material0(glm::vec3(0.4f), glm::vec3(1.f), glm::vec3(1.f), texture0.GetSlot(), texture1.GetSlot());

		glm::vec3 position(0.f);
		glm::vec3 rotation(0.f);
		glm::vec3 scale(1.f);

		glm::mat4 ModelMatrix(1.f); // creates 4x4 identity matrix (1's diagonally across)
		ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.f, 0.f, 0.f));
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), position);
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
		ModelMatrix = glm::scale(ModelMatrix, scale);

		glm::vec3 cameraPos(0.f, 0.f, 1.f);
		glm::vec3 worldUp(0.f, 1.f, 0.f); //Y is up vector, z is front and back
		glm::vec3 camFront(0.f, 0.f, -1.f);

		glm::mat4 ViewMatrix(1.f);
		ViewMatrix = glm::lookAt(cameraPos, cameraPos + camFront, worldUp);

		float fov = 1.5789f;
		float nearPlane = 0.1f;
		float farPlane = 1000.f;

		glm::mat4 ProjectionMatrix(1.f);
		ProjectionMatrix = glm::perspective(fov,
			static_cast<float>(game.GetFbW()) / game.GetFbH(),
			nearPlane, farPlane);

		glm::vec3 lightPos0(0.f, 0.f, 1.f);
		shader.Bind();

		shader.SetUniformMatrix4fv("ModelMatrix", 1, false, glm::value_ptr(ModelMatrix));
		shader.SetUniformMatrix4fv("ViewMatrix", 1, false, glm::value_ptr(ViewMatrix));
		shader.SetUniformMatrix4fv("ProjectionMatrix", 1, false, glm::value_ptr(ProjectionMatrix));

		shader.SetUniform3fv("lightPos0", 1, glm::value_ptr(lightPos0));
		shader.SetUniform3fv("cameraPos", 1, glm::value_ptr(cameraPos));

		shader.Unbind();

		Renderer renderer;

		float r = 0.f;
		float incr = 0.05f;

		while (!glfwWindowShouldClose(game.GetWindow()))
		{
			renderer.Clear();

			shader.Bind();
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
			material0.sendToShader(shader);

			shader.SetUniformMatrix4fv("ProjectionMatrix", 1, false, glm::value_ptr(ProjectionMatrix));
			shader.SetUniformMatrix4fv("ModelMatrix", 1, false, glm::value_ptr(ModelMatrix));

			ModelMatrix = glm::mat4(1.f);
			ModelMatrix = glm::translate(ModelMatrix, position);
			ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
			ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
			ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
			ModelMatrix = glm::scale(ModelMatrix, scale);
			int fbW = game.GetFbW();
			int fbH = game.GetFbH();
			glfwGetFramebufferSize(game.GetWindow(), &fbW, &fbH);

			ProjectionMatrix = glm::mat4(1.f);
			ProjectionMatrix = glm::perspective(fov,
				static_cast<float>(fbW) / fbH,
				nearPlane, farPlane);

			renderer.Draw(va, ib, shader);
			//IndexBuffer quadPrimIb = quadPrim.GetIb();
			//renderer.Draw(quadPrim.GetVa(), quadPrimIb, shader);
			//renderer.Draw(quadPrim.GetVa(), quadPrim.GetIb(), shader);

			/*
			shader.Bind();
			quadPrim.GetVa().Bind();
			quadPrim.GetIb().Bind();
			glDrawElements(GL_TRIANGLES, quadPrim.GetIb().GetCount(), GL_UNSIGNED_INT, nullptr);
			*/
			if (r > 1.0f)
				incr = -0.001f;
			else if (r < 0.0f)
				incr = 0.001f;

			r += incr;

			glfwSwapBuffers(game.GetWindow());

			glfwPollEvents();
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			updateInput(game.GetWindow(), position, rotation, scale);

			//glfwSetKeyCallback(game.GetWindow(), key_callback);
		}

	}

	glfwTerminate();
	return 0;
}