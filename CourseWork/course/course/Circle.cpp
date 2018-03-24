#include "stdafx.h"
#include "Circle.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

Circle::Circle() : Point() {
	this->radius = 10;
}

Circle::Circle(double cx, double cy, double cradius) : Point(cx, cy) {
	this->radius = cradius;
}

Circle::Circle(const Circle &circle) : Point(circle) {
	this->radius = circle.radius;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(double rd)
{
	this->radius = rd;
}

ostream& operator<< (ostream& stream, Circle& circle) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(12) << "Point X" << (char)179 << setw(12) << "Point Y" << (char)179 << setw(12) << "Radius" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill(' ') << setw(12) << circle.getX() << setfill(' ') << (char)179 << setw(12) << circle.getY() << setfill(' ') << (char)179 << setw(12) << circle.getRadius() << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}