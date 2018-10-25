
#include "Rectangle.h"


Rectangle::Rectangle(const Vertex &bottomLeft, const Vertex &topRight)
	:Rectangle(bottomLeft.m_x, bottomLeft.m_y, topRight.m_x, topRight.m_y)
{
}


Rectangle::Rectangle(const Vertex vertices[2]) : Rectangle(vertices[0], vertices[1])
{
}

Rectangle::Rectangle(const Vertex &start, double width, double height) : m_bottomLeft(start), m_topRight{ start.m_x + width , start.m_y - height }
{
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1) :
	m_bottomLeft{ x0,y0 }, m_topRight{ x1,y1 }
{
	if (!m_bottomLeft.isValid() || !m_topRight.isValid() || !m_topRight.isHigherThan(m_bottomLeft) || !m_topRight.isRighterThan(m_bottomLeft))
	{
		m_bottomLeft = { 20 , 10 };
		m_topRight = { 30 , 20 };
	}
}

//Destructor
Rectangle::~Rectangle()
{
}

//------------------Function---------------------------------------------------
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}


double Rectangle::getWidth() const
{
	return (m_bottomLeft.m_x - m_topRight.m_x);
}

double Rectangle::getHeight() const
{
	return (m_topRight.m_y - m_bottomLeft.m_y);
}

void Rectangle::draw(Board &board) const
{
	Vertex m_topLeft,
		m_bottomRight;
	m_topLeft = { m_bottomLeft.m_x, m_topRight.m_y };
	m_bottomRight = { m_topRight.m_x, m_bottomLeft.m_y };

	board.drawLine(m_bottomLeft, m_topLeft);
	board.drawLine(m_bottomLeft, m_bottomRight);
	board.drawLine(m_topRight, m_bottomRight);
	board.drawLine(m_topRight, m_topLeft);
}

Rectangle Rectangle::getBoundingRectangle() const
{
	return (Rectangle(m_bottomLeft, m_topRight));
}

double Rectangle::getArea() const
{
	return (getWidth() + getHeight());
}

double Rectangle::getPerimeter() const
{
	return (2 * getWidth() + 2 * getHeight());
}

Vertex Rectangle::getCenter() const
{
	Vertex center;
	center.m_x = (m_topRight.m_x + m_bottomLeft.m_x) / 2;
	center.m_y = (m_topRight.m_y + m_bottomLeft.m_y) / 2;
	return center;
}

bool Rectangle::scale(double factor)
{
	Vertex newTop, newBottom;
	Vertex center = getCenter();
	newTop.m_x = m_topRight.m_x + (factor - 1)*(m_topRight.m_x - center.m_x);
	newTop.m_y = m_topRight.m_y + (factor - 1)*(m_topRight.m_y - center.m_y);
	newBottom.m_x = m_bottomLeft.m_x + (factor - 1)*(m_bottomLeft.m_x - center.m_x);
	newBottom.m_y = m_bottomLeft.m_y + (factor - 1)*(m_bottomLeft.m_y - center.m_y);

	if (newTop.isHigherThan(newBottom) && newTop.isRighterThan(newBottom) && newTop.isValid() && newBottom.isValid())
	{
		m_bottomLeft = newBottom;
		m_topRight = newTop;
		return true;
	}
	return false;

}
