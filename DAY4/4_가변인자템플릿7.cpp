// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// "인자를 한개" 만 완벽한 전달
/*
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(args)); 
}
*/
// "인자갯수 제한"을 없이 사용하게 변경해 보세요
template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... args)
{
	return f( std::forward<T>(args)... ); 
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

