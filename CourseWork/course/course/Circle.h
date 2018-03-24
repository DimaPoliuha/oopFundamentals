// Class Коло (позиція х, у, радіус)
#pragma once
#include "Point.h"

class Circle : public Point {
protected:
	double radius;
public:
	Circle();
	Circle(double, double, double);
	Circle(const Circle &circle);
	~Circle() {};

	double getRadius();

	void setRadius(double);

	friend ostream& operator<< (ostream& stream, Circle& circle);
};