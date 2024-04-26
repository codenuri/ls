#include <iostream>

// fold expression 할때
// => 대부분의 이항 연산자 사용가능합니다.
// => 초기값은 객체를 사용해도 됩니다.
// => pack 이름 위치에는 pack 을 사용하는 패턴을 적으셔도 됩니다.

template<typename ... Types>
void Show(Types ... args)
{
	( std::cout << ... << args );
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



