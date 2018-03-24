#pragma once
#include <exception>
#include <string>
using namespace std;

class ExceptionErr :public exception {
protected:
	string exceptionError;
public:
	ExceptionErr(string er) : exception(), exceptionError(exceptionError) {}
	virtual const char* terror() const throw() {
		return exceptionError.c_str();
	}
};