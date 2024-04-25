// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx{};

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy{};

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;

	// 람다표현식으로 초기화된 auto 변수에 다른 람다 표현식을 담을수 없습니다.
	// => 모든 람다표현식은 다른 타입 이므로!!
	auto f3 = [](int a, int b) { return a + b; };

//	f3 = [](int a, int b) { return a + b; }; // error

	int n1 = f3(1,2);
	int n2 = f3.operator()(1, 2); // 이렇게 사용해도 됩니다.
}





