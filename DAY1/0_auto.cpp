int main()
{
	int n1 = 0;

	// 우변의 표현식으로 좌변의 타입 결정
	// => 컴파일 시간에 결정
	// => 실행시간 오버헤드는 없음.
	auto a1 = 3;   	// int    a1 = 3;
	auto a2 = 3.4;	// double a2 = 3.4;

	const int c = 10;
	auto a3 = c;   // int ?  const int ? => int

	int x[3] = {1,2,3};
	auto a4 = x; // int a4[3]  = x;
				 // int* a4 = x;       <== ok..

	auto& a5 = x; // int*& a5 = x;
				  // int(&a5)[3] = x;  <== ok.
}












//강석민 강사 ( smkang @ codenuri.co.kr )
// github.com/codenuri/ls   에서
// DAY1.zip 받으시면 됩니다.
// 실습환경 : visual studio 또는 g++, clang 모두 가능.
// 강사는 visual studio code + g++13
// www.isocpp.org
// 주요 내용 : move, 완벽한 전달, 람다, variadic template
// 1일차 : 간단한 문법들 위주로 설명
// 2~4일차 : 핵심 문법들. 
// 
