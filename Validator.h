#pragma once
#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <string>
#include "Domain.h"
#include <vector>
using namespace std;

class ValidateException {
	vector<string> msgs;
public:
	ValidateException(const vector<string>& errors) :msgs{ errors } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend ostream& operator<<(ostream& out, const ValidateException& ex);
};

ostream& operator<<(ostream& out, const ValidateException& ex);

class CarteValidator {
public:
	void validate(const carte& p);
};
#endif // !VALIDATOR_H
