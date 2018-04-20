#include "BigNum.h"

int main()
{
	BigNum A("322"),B("1337");
	string result = B.multiplication(A);
	std::cin.get();

	return 0;
}