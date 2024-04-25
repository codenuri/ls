#include <iostream>

// 람다표현식이 함수 포인터로 변환되는 원리!!
class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환이 필요한 경우 자동생성되는 함수
	inline static int helper(int a, int b) { return a + b; }


	// 함수 포인터로의 변환을 위한 변환 연산자 함수
	using FP = int(*)(int, int);

	operator FP() const { return &CompilerGeneratedName::helper ;}
};


int main()
{
	// 아래 코드의 원리를 생각해 봅시다.
	int(*f1)(int, int) = [](int a, int b) {return a + b; };

	int(*f2)(int, int) = CompilerGeneratedName{};
						// "임시객체.operator 함수포인터타입()" 을 찾게됩니다.
						// => 변환 연산자 함수
	int n = f2(1,2);
	std::cout << n << std::endl;
}





// 사전지식
/*
class Point 
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;				// this->x = a;
		y = b;				// this->y = b;
	}
};
Point p1, p2;
p1.set(10,20); // set(&p1, 10, 20)
*/









