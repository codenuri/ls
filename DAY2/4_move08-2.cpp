#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 3. 사용자가 이동 계열만 만들었을때 
// => 컴파일러는 복사 생성자를 제공안함(정확히는 삭제)
// => 복사생성자가 필요한 코드가 있었다면 "컴파일 에러"

// => 컴파일러가 제공하는 디폴트 버전이 필요하면 "=default" 로 요청가능.
struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} 

	Object(Object&& other ) : name( std::move(other.name) )
	{
		std::cout << "사용자가 만든 이동생성자\n";
	}
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
