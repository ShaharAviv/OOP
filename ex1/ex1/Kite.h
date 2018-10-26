#pragma once
#include "IsoscelesTriangle.h"

class Kite
{
public:
	Kite() = delete;
	Kite(const IsoscelesTriangle triangles[2]);
	Kite(const Vertex& top, double width, double topHeight, double bottomHeight);
	double getTotalHeight() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	//bool scale(double factor);

	~Kite();

private:
	IsoscelesTriangle m_triangle1, m_triangle2;
	void insertDefault();
	bool validKite(IsoscelesTriangle triangle1, IsoscelesTriangle triangle2);

};

