#pragma once
#include "IsoscelesTriangle.h"
class House
{
public:
	House() = delete;
	House(const Rectangle&, const IsoscelesTriangle&);
	House(const Vertex&, double, double, double);
	bool extendRoof(double);
	double getHeight() const;
	double getWidthDifference() const;

	~House();

private:
	//dfgdfgdfgdfggdfgdfgdfgdfgdfgdfgdfg
	IsoscelesTriangle m_triangle;
	Rectangle m_rec;
	bool isGood() const;

};
