#include <iostream>

int& foo(int& a) { return a;}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... args)
{
	return f( std::forward<T>(args)... ); 
}

class Test 
{
public:
	void foo(int a) {}
};

int main()
{
	Test t;

	// chronometry 를 아래 처럼 사용가능하게 발전시켜 보세요
	chronometry(&Test::foo, &t, 5); // 멤버 함수에 대해서도 동작할수 있게
								// 멤버 함수를 호출하려면 객체도 필요하므로
								// 같이 전달
}