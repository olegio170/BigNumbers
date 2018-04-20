#pragma once
#include <string>
#include <iostream>

using std::string;

class BigNum {
public:
	BigNum();
	BigNum(int num);
	BigNum(char* str);
	BigNum(string const& str);
	
	~BigNum();

	string getNum();
	string getValue();

	// Operations
	string add(BigNum operand, int offset = 0);
	string multiplication(BigNum operand);
	string leftShift();

	// Operators
	void operator += (BigNum operand);
	void operator += (string const& operand);
	void operator += (int operand);
	void operator += (char *operand);
private:
	string num;

	string toString(char *num);
	string toString(int num);
	string toString(double num);

	// Only one *pos* operations
	int posAddition(string::iterator iterator, int num);
	string posMultiplication(string::iterator operand, int operandLen);

	// Utilities

};