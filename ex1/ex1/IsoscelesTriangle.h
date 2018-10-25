#pragma once
#include "Rectangle.h"

class IsoscelesTriangle
{
public:
	IsoscelesTriangle() = delete;
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(const Vertex& center, double width, double height);

	Vertex getVertex(int index) const;
	double getLength() const;
	double getScelesLength() const;
	double getHeight() const;
	
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

	~IsoscelesTriangle();

private:
	Vertex m_arr[3];
	bool IsLegal() const;
};

