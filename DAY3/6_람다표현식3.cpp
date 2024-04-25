#include <iostream>

// auto 와 람다 표현식
int main()
{
	// 람다표현식 활용
	// 1. sort() 같은 알고리즘에 정책으로 전달하거나
	// 2. auto 변수에 담아서 함수(함수객체) 처럼 사용해도 됩니다.
	auto f = [](int a, int b) { return a + b; };
				// class xxx{}; xxx{}; 즉, 임시객체

	int ret = f(1,2); // 1 + 2

	// C#, SWIFT, RUST : 함수 안에 함수를 만들수 있습니다.(local 함수)
	// C++				: 함수 안에 함수를 만들수 없습니다.
	//					  하지만 람다표현식을 위처럼 사용하면 local 함수입니다.
}

