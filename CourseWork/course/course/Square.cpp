#include "stdafx.h"
#include "Square.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

Square::Square() : Point() {
	this->side = 20;
}

Square::Square(double sx, double sy, double cside) : Point(sx, sy) {
	this->side = cside;
}

Square::Square(const Square &square) : Point(square) {
	this->side = square.side;
}

double Square::getSide()
{
	return side;
}

void Square::setSide(double sd)
{
	this->side = sd;
}

ostream& operator<< (ostream& stream, Square& square) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(12) << "Point X" << (char)179 << setw(12) << "Point Y" << (char)179 << setw(12) << "Side" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill(' ') << setw(12) << square.getX() << setfill(' ') << (char)179 << setw(12) << square.getY() << setfill(' ') << (char)179 << setw(12) << square.getSide() << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}