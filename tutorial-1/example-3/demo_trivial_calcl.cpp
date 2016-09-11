#include <iostream>
#include <iomanip>
#include "calculator_trivial.h"

using std::cout;
using std::endl;
using std::setw;

int main(int argc, char ** argv)
{
	int a = 15,b = 3;

	cout << setw(16) << "Summation is: " << setw(5) << add_two_numbers(a,b) << endl;
	cout << setw(16) << "Subtraction is: " << setw(5) << subtract_two_numbers(a,b) << endl;
	cout << setw(16) << "Product is: " << setw(5) << multiply_two_numbers(a,b) << endl;
	cout << setw(16) << "Division is: " << setw(5) << divide_two_numbers(a,b) << endl;
	cout << setw(16) << "Remainder is: " << setw(5) << rem_div_two_numbers(a,b) << endl;

	return 0;
}
