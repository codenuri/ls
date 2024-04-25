#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 1. 사용자가 복사 계열(복사 생성자, 대입연산자) 과 이동 계열을 모두 만들지 않으면
//		 (소멸자도 만들지 않아야 한다.)
// => 컴파일러가 모두 제공
// => 복사 생성자에서는 모든 멤버를 복사로
// => 이동 생성자에서는 모든 멤버를 이동으로 ( 모든 멤버를 std::move 이동)  

// => 가장 좋은 클래스!!

// 아래 클래스는 사용자가 동적할당하지는 않지만
// => 멤버 데이타인 std::string name 이 동적할당하고 있다는 것을 꼭 기억하세요
struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 일반 생성자입니다(복사생성자아님)
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}
