#include <iostream>

// rule of 5, 3

// 생성자에서 자원을 할당하면(new 등을 사용)
// C++98 시절에는 3개의 멤버 함수를 추가로 만들어야 합니다.(rule of 3 )
// => 소멸자 필요
// => 복사 생성자 도 필요 ( 얕은 복사 문제 해결 )
// => 대입 연산자도 필요

// C++11 부터는 위 3개에 추가로
// => 이동 생성자, 이동 대입연산자도 만드는 것이 좋습니다.
// => rule of 5

// rule of 0
// => 사용자가 직접 자원을 할당하지 말고 STL 을 사용하세요
// => char* => std::string
// => int*  => std::vector  또는 smart pointer
// => 사용자가 자원을 관리하지 않으면 "복사계열" 과 "이동계열" 을 직접 만들필요없다.
//    컴파일러가 모두 제공.

class Cat
{
//	char* name;
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name(n), age(a)
	{
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;   	// 복사 생성자
	c2 = c1;		// 대입 연산자

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}
/*
// C++
std::string s1 = "AA";
std::string s2 = s1; 			// 복사
std::string s3 = std::move(s1); // 이동

// RUST
var s1 = "AAA";
var s2 = s1; // 이동
var s3 = s1.Clone(); // 복사
*/



