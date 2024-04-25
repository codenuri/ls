// 16_constexpr1

// 프로그램에서 상수란 ? 개념이 아래 2개의 개념이 혼용됩니다.
// constant expression : 컴파일 시간에 알수 있는가 ??
// read only(immutable) : 실행시 변경할수 없는가 ?

// C# 키워드
// const    : constant expression 을 의미
// readonly : immutable 의 개념. 

// C/C++
// const : read only 를 만드는 키워드, 컴파일 시간에 알수도 있고 모를수도 있다

// C++11
// constexpr - constant expressoin 으로 초기화되어야 한다.

// 배열의 크기, template 인자 등은
// => 반드시 constant expression 이어야 한다.

int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// 아래 코드에 대해서 생각해 보세요.
	int arr1[10]; // ok
	int arr2[n ]; // C89 : 배열의 크기는 "컴파일 시간에 알아야" 한다
				  // C99 : 배열의 크기로 변수 사용가능.
				  // 단, g++ 은 지원하지만, vc 는 지원 안됨. 
				  // vc 사용하므로 error.
	int arr3[c1]; // ok
	int arr4[c2]; // error

}
