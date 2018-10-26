#include "House.h"

House::House(const Rectangle &rectangle, const IsoscelesTriangle &triangle) : m_rec(rectangle.getBottomLeft(), rectangle.getTopRight()), 
			 m_triangle(triangle.getCenter(), triangle.getLength(), triangle.getHeight())
{
	if (!isGood()) 
	{	
		Vertex arr[] = { {20 , 20}, {25 , 25}, {30 , 20} };
		m_rec = { {20 , 10}, {30 , 20} };
		m_triangle = arr;
	}	
}

House::House(const Vertex& roofTop, double width, double roofHeight, double baseHeight)
	:m_triangle({ roofTop.m_x, roofTop.m_y - (roofHeight / 2) }, width, roofHeight), 
	 m_rec({roofTop.m_x - width/2, roofTop.m_y - roofHeight - baseHeight}, width, baseHeight)
	 
{

}



House::~House()
{
}

//---------------------------Function-------------------------------------------
bool House::isGood() const
{
	return (sameY(m_rec.getTopRight(), m_triangle.getVertex(0)) && m_triangle.getVertex(0).isHigherThan(m_triangle.getVertex(0)) &&
		sameX(m_triangle.getVertex(2), m_rec.getTopRight()));
}
//------------------------------------------------------------------------------
bool House::extendRoof(double width)
{

	return false;
}
