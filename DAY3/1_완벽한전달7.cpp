// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

int& f3(int a, double d, int& n) { n = 200; return n;}

void f4() {}

// 완벽한 전달 코딩 관례
// 1.가변인자 템플릿으로 만들게 된다. - 내일 배우는 내용.
// 2. 반환값도 완벽히 돌려 주려면 "decltype(auto)" 를 사용합니다.

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg) 
{					
	return f( std::forward<T>(arg)... ); 
}

int main()
{
	int n = 3;

	chronometry(f4); // 인자가 없는 함수
	chronometry(foo, 10); // 인자가 한개

	int& ret = chronometry(f3, 1, 3.4, n);

	std::cout << n << std::endl; // 200
	ret = 30; // 결국 n 의 별명
	std::cout << n << std::endl; // 30
}
// 9:50 분에 시작합니다.