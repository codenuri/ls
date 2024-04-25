// C++ 에서 constexpr
// 1. constexpr 상수 - C++11
// 2. constexpr 함수 - C++11
// 3. constexpr if  - C++17

// constexpr 함수
// => 인자의 값을 컴파일 시간에 알수 있고(constant expression)
// => 함수 호출 결과를 컴파일 할때 알아야 한다면
// => 함수 실행을 컴파일할때 해달라는 것.

constexpr int Factorial(int n)
{
	// 이 안에서는 
	// => "화면출력", "파일작업", "입력", "동적 메모리할당" 등의 작업은 안됩니다.
	// => 단순한 연산, 재귀 호출, 제어문(반복문) 정도는 가능.
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[ Factorial(5) ]; // ok

	int arr2[ Factorial(n )]; // error. 인자값을 컴파일 할때 알수 없다.

	int s1 = Factorial(n); // ok. 실행시간에 실행..	

	int s2 = Factorial(5); // 컴파일시간 ?  실행시간 ?
							// => 컴파일러종류 버전에 따라 다를수 있다.
							// => 최신 컴파일러는 대부분 컴파일 시간
	constexpr int s3 = Factorial(5); // 반드시 컴파일 할때 해달라.
	
}