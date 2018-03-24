#include "stdafx.h"
#include "List.h"
#include "ExceptionErr.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

List::List() { 
	this->sizes = 0; 
}

List::List(CircleSquare ñircleSquare) : CircleSquare(ñircleSquare) { 
	this->sizes = 1;
}

List::List(const List &csList) : CircleSquare(csList) {
	this->sizes = csList.sizes;
}

CircleSquare* List::getList() {
	return csList;
}

void List::setList(CircleSquare* cs) {
	this->csList = cs;
}

void List::addCircleSquare(CircleSquare lst) {
	addCircleSquare(lst, sizes);
}

void List::addCircleSquare(CircleSquare a, int ind) {
	if (ind < 0 || ind > sizes) ind = sizes;

	CircleSquare* tmp = new CircleSquare[++sizes];

	for (int i = 0; i < ind; i++)
		tmp[i] = csList[i];

	tmp[ind] = a;

	for (int i = ind + 1; i < sizes; i++)
		tmp[i] = csList[i - 1];

	//delete[] csList;
	csList = tmp;
}

void List::removeCircleSquareAt(int ind) {
	if (ind < 0 || ind >= sizes) return;

	CircleSquare* tmp = new CircleSquare[sizes - 1];

	for (int i = 0; i < ind; i++)
		tmp[i] = csList[i];

	for (int i = ind + 1; i < sizes; i++)
		tmp[i - 1] = csList[i];

	sizes--;
	delete[] csList;
	csList = tmp;
}

int List::getListLength() {
	return sizes;
}

void List::operator+=(CircleSquare a) {
	addCircleSquare(a);
}

CircleSquare List::operator[](int index) {
	if (index < 0 || index > sizes || index >= 100) throw;

	return csList[index];
}

void List::printBinary(string path) {
	ofstream fout;
	fout.open(path + string("binFile.dat"), ios::trunc | ios::binary);
	if (fout)
	{
		for (int i = 0; i < getListLength(); i++)
		{
			fout.write((const char*)&csList[i], sizeof(csList[i]));
		}
		cout << "Uspishno" << endl;
		fout.close();
	}
	if (!fout)
		throw ("Nemozhlivo zapisati\n");
}

void List::readBinary(string path) {
	ifstream fin(path + string("binFile.dat"), ios::binary);
	if (fin)
	{
		for (int i = 0; i < getListLength(); i++)
		{
			fin.read((char*)&csList[i], sizeof(csList[i]));
			cout << csList[i] << endl;
		}
		fin.close();
	}
	if (!fin)
		throw("Nemozhlivo zchitati\n");
}

ostream& operator<< (ostream& stream, List& lst) {
	if (lst.sizes != 0) {
		//øàïêà
		stream << (char)218;
		for (int i = 0; i < 51; i++)
			stream << (char)196;
		stream << (char)191 << endl;

		stream << (char)179 << setw(12) << "Position X" << (char)179 << setw(12) << "Position Y" << (char)179 << setw(12) << "Radius" << (char)179 << setw(12) << "Side" << (char)179 << endl;

		//ñåðåäèíà
		stream << (char)195;
		for (int i = 0; i < 51; i++)
			stream << (char)196;
		stream << (char)180 << endl;

		for (int i = 0; i < lst.sizes; i++) {
			stream << (char)179 << setfill(' ') << setw(12) << lst[i].Point::getX() << setfill(' ') << (char)179 << setw(12) << lst[i].Point::getY() << setfill(' ') << (char)179 << setw(12) << lst[i].getRadius() << setfill(' ') << (char)179;
			stream << setw(12) << lst[i].getSide() << setfill(' ') << (char)179 << endl;
		}

		//íèç
		stream << (char)192;
		for (int i = 0; i < 51; i++)
			stream << (char)196;
		stream << (char)217 << endl;

		return stream;
	}
	else stream << "No CircleSquares" << endl;

	return stream;
}