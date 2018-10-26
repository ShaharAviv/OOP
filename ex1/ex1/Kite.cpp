#include "Kite.h"


Kite::Kite(const IsoscelesTriangle triangles[2]) : m_triangle1(triangles[0]),m_triangle2(triangles[1])
{
	if (!validKite(m_triangle1, m_triangle2))
	{
		insertDefault();
	}
}

Kite::Kite(const Vertex & top, double width, double topHeight, double bottomHeight) 
	:m_triangle1(top,width,topHeight),m_triangle2({top.m_x,top.m_y - (topHeight) - bottomHeight},width,bottomHeight)
{
	if (!validKite(m_triangle1, m_triangle2))
	{
		insertDefault();
	}
}

double Kite::getTotalHeight() const
{
	return (m_triangle1.getHeight() + m_triangle2.getHeight());
}

void Kite::draw(Board & board) const
{
	board.drawLine(m_triangle1.getVertex(0), m_triangle1.getVertex(1));
	board.drawLine(m_triangle1.getVertex(1), m_triangle1.getVertex(2));
	board.drawLine(m_triangle2.getVertex(2), m_triangle2.getVertex(1));
	board.drawLine(m_triangle2.getVertex(1), m_triangle2.getVertex(0));
}

Rectangle Kite::getBoundingRectangle() const
{
	return Rectangle({ m_triangle1.getVertex(0).m_x,m_triangle2.getVertex(1).m_y },
					{ m_triangle2.getVertex(2).m_x,m_triangle1.getVertex(1).m_y });
}

double Kite::getArea() const
{

	return (m_triangle1.getArea + m_triangle2.getArea);
}

double Kite::getPerimeter() const
{
	return ((m_triangle1.getPerimeter - m_triangle1.getLength) + (m_triangle2.getPerimeter - m_triangle2.getLength));
}

Vertex Kite::getCenter() const
{
	Vertex center;
	center.m_x = m_triangle1.getVertex(1).m_x;
	center.m_y = m_triangle1.getVertex(0).m_y;

	return center;
}

Kite::~Kite()
{
}

void Kite::insertDefault()
{
	Vertex vertices1[3] = { {30,20},{25,25},{20,20} };
	Vertex vertices2[3] = { {30,20},{25,15},{20,20} };

	m_triangle1 = IsoscelesTriangle(vertices1);
	m_triangle2 = IsoscelesTriangle(vertices2);
}

bool Kite::validKite(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2)
{
	if (!(triangle1.getVertex(0).isEqual(triangle2.getVertex(0)) && doubleEqual(triangle1.getLength(), triangle2.getLength())))
	{
		return false;
	}
	return true;
}
