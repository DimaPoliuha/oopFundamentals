// Base Class Точка(позиція х, у)
#pragma once
#include <iostream>
using namespace std;

class Point {
protected:
	double x;
	double y;
public:
	Point();
	Point(double, double);
	Point(const Point &point);
	~Point() {};

	double getX();
	double getY();

	void setX(double);
	void setY(double);

	friend ostream& operator<< (ostream& stream, Point& point);
};