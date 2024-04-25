#include <iostream>
// 85 page
struct Base
{
	int value = 10; // c++11 부터 이렇게 초기화가능
};
struct Derived : public Base
{
	// 기반 클래스와 동일이름의 멤버데이타 추가 가능합니다.
	int value = 20;
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20

	// 아래 2줄의 차이점은 ?
	std::cout << static_cast<Base>(d).value << std::endl;   // 10
	std::cout << static_cast<Base&>(d).value << std::endl;  // 10

	static_cast<Base>(d).value = 30; // error. 임시객체
	static_cast<Base&>(d).value = 30; // ok.
}

// 정리. 임시객체는
// 1. 사용자가 의도적으로 생성하기도 하고(함수 인자로 사용할때)
// => draw_line(Point{1,1}, Point{3,3});

// 2. 특정 코드 때문에 생성 되기도 합니다.
// => 값을 반환하는 함수
// => 값 타입으로 캐스팅..
// => "람다표현식" 은 "임시객체를 만드는 표기법" 입니다.

// 임시객체가 언제 생성되는 지를 정확히 알고 있어야 합니다.

// 9:50 분에 시작합니다