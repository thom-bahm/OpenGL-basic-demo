#pragma once
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Primitive
{
private:
	VertexArray p_Va;
	VertexBuffer p_Vb;
	VertexBufferLayout p_Layout;
	IndexBuffer p_Ib;
	

public:
	Primitive(std::string primType, int dimensionW, int dimensionL);
	virtual ~Primitive();

	void Triangle();
	void Quad();
	void Plane(int dimensionW, int dimensionL);

	inline VertexArray GetVa() { return p_Va; }
	inline VertexBuffer GetVb() { return p_Vb; }
	inline VertexBufferLayout GetLayout() { return p_Layout; }
	inline IndexBuffer GetIb() const { return p_Ib; }
	
};