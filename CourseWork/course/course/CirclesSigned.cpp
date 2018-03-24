#include "stdafx.h"
#include "CirclesSigned.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

CirclesSigned::CirclesSigned() {
	this->length = 0;
}

CirclesSigned::CirclesSigned(CircleSigned ñircleSquare) : CircleSigned(ñircleSquare) { }

CirclesSigned::CirclesSigned(const CirclesSigned &csList) : CircleSigned(csList) {
	this->length = csList.length;
}

CircleSigned* CirclesSigned::getList() {
	return csList;
}

void CirclesSigned::setList(CircleSigned* cs) {
	this->csList = cs;
}

void CirclesSigned::addCircleSigned(CircleSigned lst) {
	addCircleSigned(lst, length);
}

void CirclesSigned::addCircleSigned(CircleSigned a, int ind) {
	if (ind < 0 || ind > length) ind = length;

	CircleSigned* tmp = new CircleSigned[++length];

	for (int i = 0; i < ind; i++)
		tmp[i] = csList[i];

	tmp[ind] = a;

	for (int i = ind + 1; i < length; i++)
		tmp[i] = csList[i - 1];

	//delete[] csList;
	csList = tmp;
}

void CirclesSigned::removeCircleSignedAt(int ind) {
	if (ind < 0 || ind >= length) return;

	CircleSigned* tmp = new CircleSigned[length - 1];

	for (int i = 0; i < ind; i++)
		tmp[i] = csList[i];

	for (int i = ind + 1; i < length; i++)
		tmp[i - 1] = csList[i];

	length--;
	delete[] csList;
	csList = tmp;
}

int CirclesSigned::getListLength() {
	return length;
}

void CirclesSigned::operator+=(CircleSigned a) {
	addCircleSigned(a);
}

CircleSigned CirclesSigned::operator[](int index) {
	if (index < 0 || index > length || index >= 100) throw;

	return csList[index];
}

ostream& operator<< (ostream& stream, CirclesSigned& lst) {
	if (lst.length != 0) {
		//øàïêà
		stream << (char)218;
		for (int i = 0; i < 51; i++)
			stream << (char)196;
		stream << (char)191 << endl;

		stream << (char)179 << setw(12) << "Position X" << (char)179 << setw(12) << "Position Y" << (char)179 << setw(12) << "Radius" << (char)179 << setw(12) << "Sign" << (char)179 << endl;

		//ñåðåäèíà
		stream << (char)195;
		for (int i = 0; i < 51; i++)
			stream << (char)196;
		stream << (char)180 << endl;

		for (int i = 0; i < lst.length; i++) {
			stream << (char)179 << setfill(' ') << setw(12) << lst[i].Point::getX() << setfill(' ') << (char)179 << setw(12) << lst[i].Point::getY() << setfill(' ') << (char)179 << setw(12) << lst[i].getRadius() << setfill(' ') << (char)179;
			stream << setw(12) << lst[i].getSign() << setfill(' ') << (char)179 << endl;
		}

		//íèç
		stream << (char)192;
		for (int i = 0; i < 51; i++)
			stream << (char)196;
		stream << (char)217 << endl;

		return stream;
	}
	else stream << "No Circle Signed" << endl;

	return stream;
}