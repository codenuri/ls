// 함수 인자로
// int&   : int 타입의 lvalue 만 받겠다는 의도
// int&&  : int 타입의 rvalue 만 받겠다는 의도
// T&     : 임의 타입(모든 타입) 의 lvalue 만 받겠다는 의도.

// T&&    : 임의 타입(모든 타입) 의 lvalue 와 rvalue 를 모두 받을수 있다.
//          받을수 있다는 의미는 "해당 함수를 생성" 한다는 것
//		    생성된 함수는 "call by value"가 아닌 "call by reference"

// lvalue(n)을 보내면 T=int&   T&&=int& &&    f4(int&) 생성됨
// rvalue(3)을 보내면 T=int    T&&=int&&      f4(int&&) 생성됨

// T&& 이름
// effective-modern C++ 책에서 "universal reference" 로 제안
// 하지만 나중에에 표준위원회는 "forwarding reference" 로 부르자고 결정
// => forward 할때 사용하는 reference 라는 의미


template<typename T> void f4(T&& a) { }

int main()
{
	int n = 3;

	// #1. 타입인자를 명시적으로 전달하는 경우
	f4<int>(3);    // T = int    T&& = int   &&    f4(int&&) 함수 생성
	f4<int&>(n);   // T = int&   T&& = int&  &&    f4(int&)  함수 생성
	f4<int&&>(3);  // T = int&&  T&& = int&& &&    f4(int&&) 함수 생성

	// #2. 타입인자를 전달하지 않으면 함수 인자를 보고 
	// => 컴파일러가 함수를 생성할수 있도록 "T를 결정"
	f4(n); 	// n 은 int 타입이지만
			// A. T=int  로 결정하면 f4(int&&) 이므로 n 을 받을수 없는 함수.
			// B. T=int& 로 결정하면 f4(int&)  이므로 n 을 받을수 있다.
			// T&& 인경우에 한해서 "B" 규칙을 적용!!

	f4(3); // T=int, int&& 모두 가능하지만, T=int 로 결정
			// 최종함수는 f4(int&&)
}



