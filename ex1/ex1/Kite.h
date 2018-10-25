#pragma once
#include "IsoscelesTriangle.h"

class Kite
{
public:
	Kite() = default;
	Kite(const IsoscelesTriangle triangles[2]);

	~Kite();

private:
	IsoscelesTriangle m_triangle1, m_triangle2;
	bool ValidKite(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2);

};

