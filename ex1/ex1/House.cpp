#include "House.h"

House::House(const Rectangle &rectangle, const IsoscelesTriangle &triangle) : m_rec(rectangle), m_triangle(triangle)
{
	if (!IsGood()) 
	{
		
	}
}

House::~House()
{
}
//---------------------------Function-------------------------------------------
bool House::IsGood() const
{
	return (sameY(m_rec.getTopRight(), m_triangle.getVertex(0)) && m_triangle.getVertex(0).isHigherThan(m_triangle.getVertex(0)) 
		   && m_rec.getWidth
}
