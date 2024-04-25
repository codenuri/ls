int main()
{
	int n = 10;

	// const : readonly 를 만드는 것
	const int c1 = n;  //ok
	const int c2 = 10; //ok

	// constexpr : 우변은 반드시 컴파일 시간에 알아아 한다는 것
//	constexpr int c3 = n;  // error
	constexpr int c4 = 10; // ok

	
//	const int ret1 = foo(); // foo 는 실행할때 값이 결정되어도 된다.
//	constexpr int ret2 = foo(); // foo 는 반드시 컴파일 할때 해달라는 지시.
}

// 2:15분에 시작합니다.