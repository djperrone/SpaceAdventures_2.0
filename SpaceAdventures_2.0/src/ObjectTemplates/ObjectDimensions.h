
#pragma once
#include "Math/Vector2d.h"

class ObjectDimensions
{
public:
	ObjectDimensions();
	ObjectDimensions(int width, int height, float scale)
		: m_Width(width), m_Height(height), m_Scale(scale)
	{}

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline float GetScale() const { return m_Scale; }

private:
	int m_Width, m_Height;
	float m_Scale;
};