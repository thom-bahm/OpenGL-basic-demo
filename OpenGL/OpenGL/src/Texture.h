#pragma once
#include "Renderer.h"

class Texture
{
private:
	unsigned int m_RendererID, m_Slot;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture(const std::string& path, unsigned int slot);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline unsigned int GetSlot() const { return m_Slot; }
};