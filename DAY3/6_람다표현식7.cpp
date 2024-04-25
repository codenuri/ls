// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 하지만 대부분의 경우 반환 타입은 생략가능합니다.
	// => 컴파일러가 추론 가능
	auto f2 = [](int a, int b)  { return a + b; };

	// return 문장이 2개 이상인데, 서로 다른 타입을 반환 할때만
	// => return 타입 표기하면 됩니다.

	auto f3 = [](int a, double b) { if( a ==1 ) return a; return b;};
						// error

	auto f3 = [](int a, double b) -> double { if( a ==1 ) return a; return b;};						
						// ok
}

// 3:15 분에 시작합니다.