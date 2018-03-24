// Class Коло, вписане в квадрат (позиція х, у, радіус, сторона)
#pragma once
#include "Circle.h"
#include "Square.h"

class CircleSquare : public Circle, public Square {
public:
	CircleSquare();
	CircleSquare(double, double, double);
	CircleSquare(const CircleSquare &circleSquare);
	~CircleSquare() {};

	void setRadius(double);
	void inputX();
	void inputY();
	void inputRadius();

	bool CircleSquare::operator>(CircleSquare);

	friend ostream& operator<< (ostream& stream, CircleSquare& circleSquare);
};