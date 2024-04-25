#include <string>

int main()
{
	int n = 10;

	std::string s;

	// n 이 짝수라면 s 에 "짝수", 홀수라면 "홀수" 라고 넣어 보세요
	// => if 문으로 해보세요.
	if ( n % 2 == 0)
		s = "짝수";
	else 
		s = "홀수";

	// RUST 는 if 문이 expression 으로 사용될수 있습니다
	s = if (n%2 == 0) "짝수" else "홀수";

	// C# 은 switch 가 expression 입니다.
	// switch 를 expression 으로 사용시 "default" 는 생략 불가
	s = switch( n) 
		{ 
			case 0: => "zero"; 
			case 1: => "one";
			case 2: => "two";
			default : => "other";
		};

}