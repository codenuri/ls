#include <iostream>

class CompilerGeneratedName
{
	int v1, v2;
public:
	inline int operator()(int a, int b) const { return a + b + v1 + v2; }

	// 아래 함수에서 "return a + b + v1 + v2" 를 할수 없습니다.
	// =>그래서 "캡쳐한 람다표현식은 함수 포인터로 변환 안됩니다."
	inline static int helper(int a, int b) { return a + b; }

	using FP = int(*)(int, int);

	operator FP() const { return &CompilerGeneratedName::helper ;}
};


int main()
{
	int v1 = 0, v2 = 0;
	// 아래 코드는 에러 입니다.
	// => 캡쳐한 람다 표현식은 "함수포인터 변환 안됩니다."
	int(*f1)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; };
}

// cppreference.com 에서 1번째 화면 "expression" 선택










