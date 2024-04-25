// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0 이므로
{								// foo(arg) 는 에러!! 리터럴 0만 포인터로변환가능
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
//	int n = 0;
//	foo(n); // error
	foo(0); // ok
//	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // ok 

}
// 결론 : 완벽한 전달을 사용하는 코드에는 포인터 의미의 "0" 을 사용할수 없습니다.
//       nullptr 사용하세요








