#include "Primitives.h"
#include <iostream>
Primitive::Primitive(std::string primType,int dimensionW, int dimensionL)
{
	
	if (primType == "Triangle")
		Triangle();
	if (primType == "Quad")
		Quad();
	if (primType == "Plane")
		Plane(dimensionW, dimensionL);
}

Primitive::~Primitive()
{
}

void Primitive::Triangle()
{
	
}

void Primitive::Quad()
{
	float positions[] = { //Quad positions
			//Positions			//Tex Coords		//Normals
		   -0.5f, -0.5f, 0.f,   0.f, 0.0f, 0.0f,	0.f, 0.0f,  1.0f, //0 Bottom Left
			0.5f, -0.5f, 0.f,   1.0f, 0.0f, 0.f,	0.0f, 0.0f, 1.f, //1 Bottom Right
			0.5f, 0.5f, 0.f,    1.0f, 1.0f, 0.f,	0.0f, 0.0f, 1.f, //2 Top right
		   -0.5f, 0.5f, 0.f,    0.0f, 1.0f, 0.f,	0.0f, 0.0f, 1.f  //3 Top Left
	};

	unsigned int indices[] = { //Quad indices
		0, 1, 2,
		2, 3, 0
	};
	//VertexArray va = p_Va;
	p_Va = VertexArray();
	p_Vb = VertexBuffer(positions, sizeof(float) * 4 * 9);

	p_Layout = VertexBufferLayout();
	p_Layout.Push<float>(3);
	p_Layout.Push<float>(3);
	p_Layout.Push<float>(3);
	p_Va.AddBuffer(p_Vb, p_Layout);

	p_Ib = IndexBuffer(indices, 6);

	std::cout << p_Va.GetID()<< std::endl;
	std::cout << p_Vb.GetID() << std::endl;
}

void Primitive::Plane(int dimensionW, int dimensionL)
{
	
}
