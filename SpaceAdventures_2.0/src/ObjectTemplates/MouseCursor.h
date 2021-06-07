#pragma once

#include "ObjectTemplates/Actor.h"

class MouseCursor : public Actor
{
public:

	MouseCursor();		
	void Tick();

	virtual void InitComponents() override;	

private:
	int m_XPosition, m_YPosition;
};