#pragma once
#include "IsoscelesTriangle.h"

class Kite
{
public:
	Kite() = delete;
	Kite(const IsoscelesTriangle triangles[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);

	~Kite();

private:
	IsoscelesTriangle m_triangle1, m_triangle2;

	bool validKite(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2);

};

