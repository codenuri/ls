// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n); // ok
f1(3); // error

// 함수 인자로
// int&   : int 타입의 lvalue 만 받겠다는 의도
// int&&  : int 타입의 rvalue 만 받겠다는 의도

// T&     : 임의 타입(모든 타입) 의 lvalue 만 받겠다는 의도.

template<typename T> void f3(T& a) { }

int main()
{
	int n = 3;

	// #1. 사용자가 타입을 명시적으로 전달하는 경우
	f3<int>(n);    // T = int    T& = int&    f3(int& ) 함수 생성
	f3<int&>(n);   // T = int&   T& = int& &  f3(int& ) 함수 생성	
	f3<int&&>(n);  // T = int&&  T& = int&& & f3(int& ) 함수 생성

	// #2. 사용자가 타입을 전달하지 않으면 컴파일러가 인자를 보고
	// => 최대한 노력해서 함수를 생성
	f3(3);  // T=int, int&, int&& 중 어떻게 결정해도 3을 받을수 없다.
			// 따라서, 컴파일 에러!!
	f3(n);  // n 은 int 타입이므로 T=int로 결정.
			// 최종 함수는 f3(int& )
}
// 3:20 분에 시작합니다.



template<typename T> void f4(T&& a)
{
}
