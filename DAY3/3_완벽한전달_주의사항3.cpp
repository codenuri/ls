// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 코드는 forwarding reference 아닙니다.
	// => forwarding reference가 되려면 함수 템플릿 이어야 합니다.
	// => 아래 함수는 함수 템플릿이 아닙니다.
	// => "클래스 템플릿의 멤버 함수" 입니다.
	void foo(T&& arg)
	{
	}

	// 아래 코드가 forwarding reference 입니다.
	// => 함수 자체가 템플릿!!!
	// => 즉, 호출시 전달하는 인자를 보고 타입 결정!!
	template<typename U>
	void goo(U&& arg) {}
};
int main()
{
	int n = 0;
	Test<int> t; 	// 이순간 T=int 로 결정
					// void foo(int&& ) 로 결정.		
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n); 	// error
	t.foo(10);  // ok

	t.goo(n); // ok
	t.goo(10); // ok
}

// 11:00 에 시작 합니다.