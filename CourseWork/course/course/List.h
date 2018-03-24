// Class Масив фігур на екрані
#pragma once
#include "CircleSquare.h"

class List : public CircleSquare {
private:
	CircleSquare* csList;
	int sizes;
public:
	List();
	List(CircleSquare);
	List(const List &list);

	CircleSquare* getList();
	void setList(CircleSquare*);
	void addCircleSquare(CircleSquare);
	void addCircleSquare(CircleSquare, int);
	void removeCircleSquareAt(int);
	int getListLength();

	void operator +=(CircleSquare);
	CircleSquare operator[](int);
	void printBinary(std::string);
	void readBinary(std::string);

	friend ostream& operator<< (ostream& stream, List& list);
};