#pragma once

#include "ObjectTemplates/Character.h"

class MouseCursor : public Character
{
public:

	MouseCursor();		
	virtual void Update() override;

	virtual void InitComponents() override;	

private:
	int m_XPosition, m_YPosition;
};