#include "stdafx.h"
#include "CircleSigned.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

CircleSigned::CircleSigned() : Circle() {
	this->sign = new char[strlen("Hello") + 1];
	this->sign = strcpy(sign, "Hello");
}

CircleSigned::CircleSigned(double csx, double csy, double csradius, char* cssign) : Circle(csx, csy, csradius) {
	this->sign = new char[strlen(cssign) + 1];
	this->sign = strcpy(sign, cssign);
}

CircleSigned::CircleSigned(const CircleSigned &circleSigned) : Circle(circleSigned) {
	this->sign = new char[strlen(circleSigned.sign) + 1];
	this->sign = strcpy(sign, circleSigned.sign);
}

CircleSigned::~CircleSigned() {
	if (!sign)
		delete[] sign;
}

char* CircleSigned::getSign()
{
	return sign;
}

void CircleSigned::setSign(char* csg)
{
	this->sign = csg;
}

ostream& operator<< (ostream& stream, CircleSigned& circleSigned) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 51; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(12) << "Point X" << (char)179 << setw(12) << "Point Y" << (char)179 << setw(12) << "Radius" << (char)179 << setw(12) << "Sign" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 51; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill(' ') << setw(12) << circleSigned.getX() << setfill(' ') << (char)179 << setw(12) << circleSigned.getY() << setfill(' ') << (char)179 << setw(12) << circleSigned.getRadius() << (char)179 << setw(12) << circleSigned.getSign() << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 51; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}