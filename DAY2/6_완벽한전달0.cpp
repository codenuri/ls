#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);


	int&& r2 = 10;
	foo(r2);
}







