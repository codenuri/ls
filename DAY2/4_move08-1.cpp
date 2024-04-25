#include <iostream>
#include <string>

// 규칙 2. 사용자가 복사 계열만 만들었을때 
// => 컴파일러는 이동 계열을 제공하지 않음.
// => std::move() 사용시 에러는 아니고 "사용자의 복사 생성자 사용"

// => 이동 계열을 컴파일러에게 요청하려면 "=default" 로 하면 된다. 아래 클래스 참고
struct Object
{
	std::string name;
	Object(const std::string& n) : name(n) {} 

	Object(const Object& other) : name(other.name)
	{
		std::cout << "사용자가 만든 복사생성자\n";
	}
/*
	Object(Object&&) = default;
	Object& operator=(Object&&) = default;
	Object& operator=(const Object&) = default;
*/
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);  // 사용자가만든 복사 호출

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // "obj2"
}
