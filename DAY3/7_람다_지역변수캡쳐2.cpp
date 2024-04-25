#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

//	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	// mutable lambda : () 연산자 함수를 상수 멤버함수로 하지말라는 의미
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; 

	f1(0); // v1 = 100 이 수행되지만, 복사본 변경

	std::cout << v1 << std::endl; // 10


	std::cout << sizeof(f1) << std::endl; // 8


/*
	// 지역변수 캡쳐의 원리
	// => 위 람다 표현식 한줄을 보고 컴파일러가 아래 코드 생성
	class CompilerGeneratedName 
	{
		// 지역변수를 캡쳐하면 멤버데이타가 추가됨.
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

//		inline int operator()(int a) const  // non mutable 람다
		inline int operator()(int a)  		// mutable 람다
		{
			v1 = 100; 			// error. 상수 멤버함수에서는 멤버 데이타 수정안됨.
								// 단, mutable 람다 라면 에러 아님
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{v1, v2};
*/
}





