// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

int main()
{
	int n = 10;

	foo(10);
	goo(n);

	std::cout << n << std::endl;
}
