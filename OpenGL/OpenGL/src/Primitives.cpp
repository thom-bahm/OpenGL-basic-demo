#include "Primitives.h"

Primitive::Primitive(std::string primType,int dimensionW, int dimensionL)
{
	p_Va = VertexArray();
	p_Vb = VertexBuffer();
	p_Ib = IndexBuffer();
	p_Layout = VertexBufferLayout();
	
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
}

void Primitive::Quad()
{
}

void Primitive::Plane(int dimensionW, int dimensionL)
{
}
