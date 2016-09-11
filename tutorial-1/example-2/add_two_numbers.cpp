#include <iostream>

using std::cout;
using std::endl;

int add_two_numbers(int, int);

int main(int argc, char** argv)
{
	int a = 5;
	int b = 13;

	int sum = add_two_numbers(a,b);

	cout  << "The sum of " << a << " and " << b << " is = " << sum << endl;
	return 0;
}

int add_two_numbers(int a, int b)
{
	return a + b;
}
