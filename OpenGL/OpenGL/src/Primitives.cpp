#include "Primitives.h"

Primitive::Primitive(std::string primType,int dimensionW, int dimensionL)
{
	p_Va = VertexArray();
	p_Vb = VertexBuffer();
	p_Layout = VertexBufferLayout();
	p_Ib = IndexBuffer();
	
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

	VertexArray va;
	VertexBuffer vb(positions, sizeof(float) * 4 * 9);

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);

	p_Va = va;
	p_Vb = vb;
	p_Layout = layout;
	p_Ib = ib;
}

void Primitive::Plane(int dimensionW, int dimensionL)
{
	
}
