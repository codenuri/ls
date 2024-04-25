// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }


// forward : 전달받은 인자를 다시 다른 함수로 보내는 것
// perfect forward : 다른 함수에 보낼때 어떠한 변화도 없이 그대로 전달하는것

template<typename F, typename T>
void chronometry(F f, const T& arg) // ??? 완벽한 전달을 하려면
{									// 2번째 인자를 어떻게 해야할까 ??
	// <----- 시간 기록
	f(arg);	  
	// <----- 다시 시간을 구해서 걸린시간 출력
}
int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10) 의 수행시간을 측정해 달라
	chronometry(goo, n);  // goo(n)  의 수행시간을 측정해 달라

	std::cout << n << std::endl;
}
