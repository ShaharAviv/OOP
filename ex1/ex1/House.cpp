#include "House.h"

House::House(const Rectangle &rectangle, const IsoscelesTriangle &triangle) : m_rec(rectangle), m_triangle(triangle)
{
	if (!IsGood()) 
	{	
		m_rec = { {m_rec.getBottomLeft()}, {m_rec.getTopRight() } };
		m_triangle = { {m_triangle.getCenter()}, {m_triangle.getLength()}, {m_triangle.getHeight()} };
	}	
}

House::~House()
{
}

//---------------------------Function-------------------------------------------
bool House::IsGood() const
{
	return (sameY(m_rec.getTopRight(), m_triangle.getVertex(0)) && m_triangle.getVertex(0).isHigherThan(m_triangle.getVertex(0)) &&
		sameX(m_triangle.getVertex(2), m_rec.getTopRight());
}
