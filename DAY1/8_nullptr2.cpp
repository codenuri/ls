// 8_nullptr2
#include <iostream>

void foo(int* p) {}

// 함수와 인자를 각각 받아서 호출해주는 함수 - C++11 이후 많이 사용되는 스타일 
template<typename F, typename ARG>
void forward_parameter(F f, ARG arg) // ARG arg = 0; 이므로 arg 는 int
{									 // foo(arg);  이므로 error
				// ARG arg = nullptr; 이 되므로 arg 는 std::nullptr_t
				// f(arg); // arg 가 std::nullptr_t 이므로 ok
	// 시간 측정
	f(arg);
	// 다시 시간 측정
}

int main()
{
	int n = 0;

	// 아래 2줄을 생각해 보세요
	foo(0); // ok
	foo(n); // error. 리터럴 0만 포인터로 변환 됩니다.
			//        0을 담은 정수형 변수는 포인터로 변환될수 없습니다.

//	forward_parameter(foo, 0); // foo(0)의 의도 인데.!!!???
							   // error
	forward_parameter(foo, nullptr); // 이코드는 ok..
									// 이렇게 사용하기 위해 nullptr 도입됨.
}








