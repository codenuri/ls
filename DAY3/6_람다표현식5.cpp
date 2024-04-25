// 143 
#include <functional>
#include <vector>

int main()
{
	// 람다표현식을 담는 방법
	// 1. auto 변수
	// 2. 함수포인터
	// 3. std::function
	auto f1 = [](int a, int b) { return a + b; };

	int(*f2)(int, int) = [](int a, int b) { return a + b; };
	
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// 인라인 치환성
	f1(1, 2); // f1.operator()(1, 2). 즉, 함수이름을 사용해서 호출한것
			  // 인라인 치환됨.
	f2(1, 2); // 주소를 사용해서 호출. 즉, 인라인 치환 안됨
	f3(1, 2); // 인라인 치환 안됨.

	// #1. 람다표현식을 변수에 담아서 함수 처럼 사용하려면
	// => auto 사용하세요

	// #2. 람다표현식 여러개를 컨테이너에 보관하려면 std::function
//	std::vector<auto> v; // error!!!

	std::vector< std::function< int(int, int)> > v;

	v.push_back([](int, int) { return a + b;});
}
