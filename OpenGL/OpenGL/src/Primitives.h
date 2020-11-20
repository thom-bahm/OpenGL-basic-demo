#pragma once
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Primitive
{
private:
	VertexArray pVa;
	VertexBuffer pVb;
	VertexBufferLayout pLayout;
	IndexBuffer pIb;
	

public:
	Primitive(std::string primType, int dimensionW, int dimensionL);
	virtual ~Primitive();

	void Triangle();
	void Quad();
	void Plane(int dimensionW, int dimensionL);

	
};