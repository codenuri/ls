// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 규칙!!!
// 완벽한 전달을 하려면
// 1. 인자를 받을때 forwarding reference (T&&) 로 받으세요
// 2. 받은 인자를 다른 곳에 보낼때는 "std::forward<T>(arg)" 로
//    묶어서 보내세요.!!!

// 위 규칙만 외우시면 됩니다.

template<typename F, typename T>
void chronometry(F f, T&& arg) 
{					
	f( std::forward<T>(arg)); 
}



int main()
{
	int n = 3;

	chronometry(foo, 3); 
	chronometry(hoo, n); 
}
