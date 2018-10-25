#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3]) 
	:m_arr{vertices[0],vertices[1],vertices[2]}
{
	if (!isLegal())
	{
		m_arr[0] = { 20 , 20 };
		m_arr[1] = { 25 , 25 };
		m_arr[2] = { 30 , 20 };
	}
}

//-------------------Function-----------------------------------------------
IsoscelesTriangle::IsoscelesTriangle(const Vertex & center, double width, double height) : m_arr{ {center.m_x - width / 2,  center.m_y - height}, 
									{center}, {center.m_x + width / 2, center.m_y - height} }
{
	if (!isLegal())
	{
		m_arr[0] = { 20 , 20 };
		m_arr[1] = { 25 , 25 };
		m_arr[2] = { 30 , 20 };
	}
}
//-------------------Function-----------------------------------------------
Vertex IsoscelesTriangle::getVertex(int index) const
{
	return m_arr[index];
}
//-------------------------------------------------------------------------
Vertex IsoscelesTriangle::getCenter() const
{
	return { m_arr[1].m_x,m_arr[2].m_y + getHeight() / 2 };
}
//-------------------------------------------------------------------------
Vertex IsoscelesTriangle::getLeft() const
{
	return m_arr[0];
}
//-------------------------------------------------------------------------
Vertex IsoscelesTriangle::getRight() const
{
	return m_arr[2];
}
//-------------------------------------------------------------------------
bool IsoscelesTriangle::scale(double factor)
{
	return false;
}
//--------------------------------------------------------------------------
double IsoscelesTriangle::getLength() const
{
	return distance(m_arr[0],m_arr[2]);
}

//--------------------------------------------------------------------------
double IsoscelesTriangle::getScelesLength() const
{
	return distance(m_arr[1],m_arr[0]);
}

//--------------------------------------------------------------------------
double IsoscelesTriangle::getHeight() const
{
	return (m_arr[1].m_y-m_arr[0].m_y);
}
//-------------------------------------------------------------------------
void IsoscelesTriangle::draw(Board & board) const
{
	board.drawLine(m_arr[0], m_arr[2]);
	board.drawLine(m_arr[2], m_arr[1]);
	board.drawLine(m_arr[1], m_arr[0]);
}
//-------------------------------------------------------------------------
Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	if(m_arr[1].isHigherThan(m_arr[0]))
		return Rectangle(m_arr[0], { m_arr[2].m_x, m_arr[1].m_y });

	else
		return Rectangle({ m_arr[0].m_x, m_arr[1].m_y } , m_arr[2]);
}
//-------------------------------------------------------------------------
double IsoscelesTriangle::getArea() const
{
	return ((distance(m_arr[0], m_arr[2])*getHeight()) / 2);
}
//-------------------------------------------------------------------------
double IsoscelesTriangle::getPerimeter() const
{
	return (distance(m_arr[0], m_arr[1]) + distance(m_arr[1], m_arr[2]) + distance(m_arr[2], m_arr[0]));
}

//-------------------------------------------------------------------------

//Destructor
IsoscelesTriangle::~IsoscelesTriangle()
{
}


//--------------------------------------------------------------------------
bool IsoscelesTriangle::isLegal() const
{//Function that check if the triangle is legal
	double side1,
	       side2;
	side1 = distance(m_arr[0], m_arr[1]);
	side2 = distance(m_arr[2], m_arr[1]);
	if (m_arr[0].isValid() && m_arr[1].isValid() && m_arr[2].isValid() && sameY(m_arr[0], m_arr[2]) && doubleEqual(side1, side2))
	{
		return true;
	}
	return false;

}