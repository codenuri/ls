#include <iostream>

// 함수객체와 const member function

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T> void foo(T f)
{
	int ret = f(1, 2);
}

int main()
{
	Plus p;

	foo(p);
}
