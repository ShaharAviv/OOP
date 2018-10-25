#include "Kite.h"


Kite::Kite(const IsoscelesTriangle triangles[2]) : m_triangle1(triangles[0]),m_triangle2(triangles[1])
{
	if (!validKite(m_triangle1, m_triangle2))
	{
		Vertex vertices1[3] = { {30,20},{25,25},{20,20} };
		Vertex vertices2[3] = { {30,20},{25,15},{20,20} };

		m_triangle1 = IsoscelesTriangle(vertices1); 
		m_triangle2 = IsoscelesTriangle(vertices2);
	}
}

Kite::Kite(const Vertex & top, double width, double topHeight, double bottomHeight) 
	:m_triangle1(top,width,topHeight),m_triangle2({top.m_x,top.m_y - (topHeight) - bottomHeight},width,bottomHeight)
{
	if (!validKite(m_triangle1, m_triangle2))
	{

	}
}

Kite::~Kite()
{
}

bool Kite::validKite(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2)
{
	if (!(triangle1.getVertex(0).isEqual(triangle2.getVertex(0)) && doubleEqual(triangle1.getLength(), triangle2.getLength())))
	{
		return false;
	}
	return true;
}
