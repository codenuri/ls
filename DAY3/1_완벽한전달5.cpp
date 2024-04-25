// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

/*
template<typename F>
void chronometry(F f, int& arg) 
{								
//	f(arg);	  
	f(static_cast<int&>(arg)); // 없어도 되는 필요 없는 캐스팅입니다.
								// 하지만 있어도 에러 아니고, 
								// 컴파일 과정에서 아무일도 하지 않고, 제거됨.
}
template<typename F>
void chronometry(F f, int&& arg) 
{					
	f(static_cast<int&&>(arg)); 
}
*/
// T&& 를 사용하면 위의 2개 함수를 자동 생성가능합니다.
// => 또한 int 뿐 아니라 모든 타입에 대해서 함수 생성 가능.

template<typename F, typename T>
void chronometry(F f, T&& arg) 
{					
	// 아래 캐스팅은 항상 "rvalue" 로 캐스팅하는 캐스팅이다 ? => 아니다
	// static_cast<int&&>(arg) : 항상 rvalue 로 캐스팅
	// static_cast<ㅅT&&>(arg)  : 항상 rvalue 로 캐스팅 아님. 
	// 							  T안에 & 가 포함될수 있다.

	// 아래 캐스팅은 chronometry 사용시 2번째 인자로
	// lvalue 를 전달하면 (필요없지만 )                  lvalue 로 캐스팅하고
	// rvalue 를 전달하면 (받으면서 lvalue 가 된것을 다시 ) rvalue 로 캐스팅하고

//	f(static_cast<T&&>(arg)); 

	f( std::forward<T>(arg)); // 이 코드과 위 코드와 동일합니다.
							  // forward 함수가 내부적으로 위 처럼 캐스팅
							  // T&& 가 아닌 T 형태로 전달해야 합니다.

}

int main()
{
	int n = 3;

	// 아래 코드를 보고, 생성된 함수의 2번째인자, 캐스팅 코드를 예측해 보세요
	chronometry(foo, 3); // T = int,   T&& = int&&   chronometry(int&& arg)
						 // static_cast<int&&>(arg)

	// 5번소스 아래 코드 "hoo" 가 아니고 "goo" 입니다.
	chronometry(goo, n); // T = int&, T&& = int& &&   chronometry(int& arg)
						 // static_cast<int&>(arg)
}
