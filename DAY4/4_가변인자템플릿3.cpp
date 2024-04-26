#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	goo( args ); // error. pack 을 직접 함수 인자로 사용할수 없습니다.

	// ========================================================
	// pack expansion : pack 안의 요소를 , 를 사용해서 열거해달라는 문법.
	// "pack을사용하는패턴"... => "E1패턴", "E2패턴","E3패턴"

	goo( args... ); // goo(1, 2, 3)

	goo( (++args)...); // goo( ++E1, ++E2, ++E3)

//	goo( hoo(args...) ); // 위의 goo, hoo 참고해서 생각해 보세요
						 // goo( hoo( E1, E2, E3 )) 인데... 
						 // hoo 는 인자가 한개이므로
						 // error

	goo( hoo(args)... ); // goo( hoo(E1), hoo(E2), hoo(E3) );
}


int main()
{
	foo(1, 2, 3);
}
