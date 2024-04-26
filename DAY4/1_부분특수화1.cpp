// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// "클래스이름::이름" 에서 이름은 
	// 1. 값 일수도 있고 ( enum, static 멤버 등 )
	// 2. 타입 일수도 있다(using, typedef 등 )

	// 아래 코드에서 * 의 의미를 생각해 보세요
//	Test::data  * p; 	// 곱하기 의미
//	Test::DWORD * p; 	// 포인터 변수의 선언에 사용하는 포인터 연산자

	// 핵심 1. dependant name
	// => 템플릿 인자 T에 의존해서 꺼내는 이름
	// => 컴파일러는 항상 "값" 으로 해석한다.
	// => "타입" 으로 해석되게 하려면 "typename" 을 표기해야 한다.
	
	T::data  * p;	// ok
//	T::DWORD * p; 	// error
	typename T::DWORD * p;  // ok. dependant name 이 타입이라고
							//	   알려주는 것
}


int main()
{
	Test t;
	foo(t);
}


