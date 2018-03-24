// Class Коло з написом(позиція х, у, радіус, напис)
#pragma once
#include "Circle.h"

class CircleSigned : public Circle {
protected:
	char* sign;
public:
	CircleSigned();
	CircleSigned(double, double, double, char*);
	CircleSigned(const CircleSigned &circleSigned);
	~CircleSigned();

	char* getSign();

	void setSign(char*);

	friend ostream& operator<< (ostream& stream, CircleSigned& circleSigned);
};