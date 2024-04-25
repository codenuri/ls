// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 완벽한 전달을 하려면
// 1. 인자의 복사본을 만들면 안된다. call by reference 필요
// 2. int&, int&& 버전을 따로 만들어야 한다.
// => 그런데, 아래 코드는 단 한가지 경우에 문제가 된다.(3번 참고.. )

template<typename F>
void chronometry(F f, int& arg) 
{								
	f(arg);	  
}
template<typename F>
void chronometry(F f, int&& arg) 
{								
	f(arg);	  
}

int main()
{
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}
