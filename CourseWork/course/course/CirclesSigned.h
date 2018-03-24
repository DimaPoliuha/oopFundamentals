#pragma once
#include "CircleSigned.h"

class CirclesSigned : public CircleSigned {
private:
	CircleSigned* csList;
	int length;
public:
	CirclesSigned();
	CirclesSigned(CircleSigned);
	CirclesSigned(const CirclesSigned &list);

	CircleSigned* getList();
	void setList(CircleSigned*);
	void addCircleSigned(CircleSigned);
	void addCircleSigned(CircleSigned, int);
	void removeCircleSignedAt(int);
	int getListLength();

	void operator +=(CircleSigned);
	CircleSigned operator[](int);

	friend ostream& operator<< (ostream& stream, CirclesSigned& list);
};