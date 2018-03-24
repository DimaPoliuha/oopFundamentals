#include "stdafx.h"
#include "CircleSquare.h"
#include "ExceptionErr.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

CircleSquare::CircleSquare() : Circle(0, 0, 10), Square(0, 0, 20) {
}

CircleSquare::CircleSquare(double csx, double csy, double csradius) : Circle(csx, csy, csradius),
Square(csx, csy, 2 * csradius) {
}

CircleSquare::CircleSquare(const CircleSquare &circleSquare) : Circle(circleSquare), Square(circleSquare) {
}

void CircleSquare::setRadius(double rad) {
	this->radius = rad;
}

void CircleSquare::inputX() {
	int correct, incorrect;
	double xx;
	char x_char[256];
	fflush(stdin);
	gets_s(x_char, 256);
	do
	{
		try {
			correct = 0;
			incorrect = 0;
			printf("\nVvedit X: ");
			gets_s(x_char, 256);
			xx = atof(x_char);
			for (int i = 0; i < strlen(x_char); i++) {
				if (isdigit(x_char[i]))
					correct++;
				if (ispunct(x_char[i]))
					correct++;
				if ((!isdigit(x_char[i])) && (!ispunct(x_char[i])))
					incorrect++;
				if (xx < -1000000000 || (xx > 1000000000)) {
					ExceptionErr exceptionError("Vihid za mezhi.\n");
					throw exceptionError;
				}
			}
		}
		catch (ExceptionErr& exceptionError)
		{
			cout << exceptionError.terror() << "Vihid za mezhi." << endl;
		}
	} while ((xx > 1000000000) || (xx < -1000000000) || (correct < 1) || (incorrect != 0));
	CircleSquare::Circle::Point::x = xx;
}

void CircleSquare::inputY() {
	int correct, incorrect;
	double yy;
	char y_char[256];
	fflush(stdin);
	do
	{
		try {
			correct = 0;
			incorrect = 0;
			printf("\nVvedit Y: ");
			gets_s(y_char, 256);
			yy = atof(y_char);
			for (int i = 0; i < strlen(y_char); i++) {
				if (isdigit(y_char[i]))
					correct++;
				if (ispunct(y_char[i]))
					correct++;
				if ( (!isdigit(y_char[i])) && (!ispunct(y_char[i])) )
					incorrect++;
				if (yy < -1000000000 || (yy > 1000000000)) {
					ExceptionErr exceptionError("Vihid za mezhi.\n");
					throw exceptionError;
				}
			}
		}
		catch (ExceptionErr& exceptionError)
		{
			cout << exceptionError.terror() << "Vihid za mezhi." << endl;
		}
	} while ((yy > 1000000000) || (yy < -1000000000) || (correct < 1) || (incorrect != 0));
	CircleSquare::Circle::Point::y = yy;
}

void CircleSquare::inputRadius() {
	int correct, incorrect;
	double rad;
	char rad_char[256];
	fflush(stdin);
	do
	{
		try {
			correct = 0;
			incorrect = 0;
			printf("\nVvedit radius (vid 0 do 1000000): ");
			gets_s(rad_char, 256);
			rad = atof(rad_char);
			for (int i = 0; i < strlen(rad_char); i++) {
				if (isdigit(rad_char[i]))
					correct++;
				if (ispunct(rad_char[i]))
					correct++;
				if ((!isdigit(rad_char[i])) && (!ispunct(rad_char[i])))
					incorrect++;
				if (rad < 0) {
					ExceptionErr exceptionError("Radius ne mozhe buti < 0.\n");
					throw exceptionError;
				}
			}
		}
		catch (ExceptionErr& exceptionError)
		{
			cout << exceptionError.terror() << "Nevirno zadano radius" << endl;
		}
	} while ((correct > 7) || (rad > 1000000) || (rad < 0) || (incorrect != 0));
	radius = rad;
	CircleSquare::Square::side = radius * 2;
}

bool CircleSquare::operator>(CircleSquare obj)
{
	return side > obj.side;
}

ostream& operator<< (ostream& stream, CircleSquare& circleSquare) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 51; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(12) << "Position X" << (char)179 << setw(12) << "Position Y" << (char)179 << setw(12) << "Radius" << (char)179 << setw(12) << "Side" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 51; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill(' ') << setw(12) << circleSquare.Point::getX() << setfill(' ') << (char)179 << setw(12) << circleSquare.Point::getY() << setfill(' ') << (char)179 << setw(12) << circleSquare.getRadius() << setfill(' ') << (char)179;
	stream << setw(12) << circleSquare.getSide() << setfill(' ') << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 51; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}