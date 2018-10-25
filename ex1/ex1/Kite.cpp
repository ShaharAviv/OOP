#include "Kite.h"





Kite::Kite(const IsoscelesTriangle triangles[2]) : m_triangle1(triangles[0]),m_triangle2(triangles[1])
{
	if (!ValidKite(m_triangle1, m_triangle2))
	{
		Vertex vertices1[3] = { {30,20},{25,25},{20,20} };
		
		m_triangle1 = IsoscelesTriangle(vertices); 

		Vertex vertices2[3] = { {30,20},{25,15},{20,20} };
		IsoscelesTriangle temp2(vertices2);
		m_triangle2 = temp2;

	}
}

Kite::~Kite()
{
}

bool Kite::ValidKite(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2)
{
	if (!(triangle1.getLeft().isEqual(triangle2.getLeft()) && doubleEqual(triangle1.getLength(), triangle2.getLength())))
	{
		return false;
	}
	return true;
}
