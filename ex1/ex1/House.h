#pragma once
#include "IsoscelesTriangle.h"

class House
{
public:
	House() = default;
	House(const Rectangle&, const IsoscelesTriangle&);
	~House();

private:
	IsoscelesTriangle m_triangle;
	Rectangle m_rec;
	bool IsGood() const;
};
