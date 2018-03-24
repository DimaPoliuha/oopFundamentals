// Class  вадрат(позиц≥€ х, у, сторона)
#pragma once
#include "Point.h"

class Square : public Point {
protected:
	double side;
public:
	Square();
	Square(double, double, double);
	Square(const Square &square);
	~Square() {};

	double getSide();

	void setSide(double);

	friend ostream& operator<< (ostream& stream, Square& square);
};