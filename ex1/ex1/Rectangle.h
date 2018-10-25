#pragma once
#include "Utilities.h"
#include "Board.h"

class Rectangle
{
public:
	Rectangle(const Vertex&, const Vertex&);
	Rectangle(const Vertex ver[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex&, double width, double height);

	void draw(Board&) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;
	~Rectangle();

private:
	Vertex m_topRight,
		   m_bottomLeft;
};
