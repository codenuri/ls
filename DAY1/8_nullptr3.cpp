//8_nullptr3
#include <iostream>

int main()
{
	// literal 과 타입
	// => C/C++ 에서 모든 객체와 리터럴은 타입이 있습니다.
	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	false;		// bool			false 는 키워드 이고 리터럴
	nullptr;	// std::nullptr_t 타입, false 와 같은 키워드이고, 리터럴.

	std::nullptr_t a = nullptr;

	// 이에 a는 nullptr 과 완벽히 동일하게 사용가능
	int* p1 = a;
	char* p2 = a;

	// C++ 표준 문법 : std::nullptr_t 타입의 객체는 모든 타입의 포인터로
	//				암시적 형변환 가능하다.
}



