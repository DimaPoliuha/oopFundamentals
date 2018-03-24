#include "stdafx.h"
#include "Point.h"
#include <iostream>
#include <iomanip>
using namespace std;

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double px, double py) {
	this->x = px;
	this->y = py;
}

Point::Point(const Point &point) {
	this->x = point.x;
	this->y = point.y;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

void Point::setX(double xx)
{
	x = xx;
}

void Point::setY(double yy)
{
	y = yy;
}

ostream& operator<< (ostream& stream, Point& point) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 25; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(12) << "Point X" << (char)179 << setw(12) << "Point Y" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 25; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill(' ') << setw(12) << point.getX() << setfill(' ') << (char)179 << setw(12) << point.getY() << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 25; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}