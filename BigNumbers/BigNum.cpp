#include "BigNum.h"

BigNum::BigNum()
{
	num = "0";
}

BigNum::BigNum(int value)
{
	string str = std::to_string(value);
	num = str;
	std::reverse(num.begin(), num.end());
}

BigNum::BigNum(char* str)
{
	num = str;
	std::reverse(num.begin(), num.end());
}

BigNum::BigNum(string const& str)
{
	num = str;
	std::reverse(num.begin(), num.end());
}

BigNum::~BigNum()
{

}

string BigNum::getNum()
{
	string result = num;
	std::reverse(result.begin(), result.end());
	return result;
}

string BigNum::getValue()
{
	return num;
}

string BigNum::add(BigNum operand, int offset)
{
	int mem = 0;
	string::iterator	operandIterator = operand.num.begin(),
						thisIterator = this->num.begin() + offset;
	while (operandIterator != operand.num.end() || mem)
	{
		char operandPosValue;
		if (operandIterator != operand.num.end()) {
			operandPosValue = *operandIterator + mem;
			operandIterator++;
		}
		else {
			operandPosValue = mem + '0';
		}

		if (thisIterator == this->num.end()) {
			this->num.push_back(operandPosValue);
			mem = 0;
		}
		else {
			mem = posAddition(thisIterator, operandPosValue);
		}
		++thisIterator;
	}

	return this->getNum();
}

string BigNum::multiplication(BigNum operand)
{
	BigNum result;
	int operandLen = operand.num.length();
	for (int i = 0; i < operandLen - 1; i++)
		result.num.push_back('0');

	int offset = 0;
	for (string::iterator iterator = operand.num.begin();
		 iterator != operand.num.end(); ++iterator, ++offset)
	{
		result.add(posMultiplication(iterator, operandLen), offset);
	}

	this->num = result.getValue();
	return this->getNum();
}

string BigNum::leftShift()
{
	// kostul
	if(this->num != "0")
		this->num.insert(0, 1, '0');
	return this->getNum();
}

void BigNum::operator += (BigNum operand)
{
	add(operand);
}

void BigNum::operator += (string const& operand)
{
	add(operand);
}

void BigNum::operator += (int operand)
{
	BigNum op(operand);
	add(op);
}

void BigNum::operator += (char *operand)
{
	BigNum op(operand);
	add(op);
}

string BigNum::toString(char *num)
{
	return "";
}

string BigNum::toString(int num)
{
	return "";
}

string BigNum::toString(double num)
{
	return "";
}

int BigNum::posAddition(string::iterator iterator, int item)
{
	int sum = *iterator + item  - '0';

	if (sum > '9') {
		*iterator = sum - 10;
		return 1;
	}
	else {
		*iterator = sum;
		return 0;
	}
}

string BigNum::posMultiplication(string::iterator operandIterator, int operandLen)
{
	BigNum result;
	for (int i = 0; i < operandLen-1; i++)
		result.num.push_back('0');

	int offset = 0;
	string::iterator thisIterator = this->num.begin();
	while (thisIterator != this->num.end())
	{
		BigNum product = (int)(*thisIterator - '0') * (*operandIterator - '0');
		result.add(product, offset);
		++thisIterator;
		++offset;
	}
	return result.getNum();
}