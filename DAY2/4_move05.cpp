// std::move()소개
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// 복사 생성자 호출
	Cat c3 = foo();	// 이동 생성자 호출
	Cat c4 = static_cast<Cat&&>(c2); // 캐스팅 때문에 이동생성자 호출
	Cat c5 = std::move(c3); // std::move 가 결국 위 캐스팅입니다.
}

// static_cast<Type&&>(obj) 의 의미
// => lvalue 인 obj 를 rvalue 로 해석해 달라는 "value casting"
// => 타입 캐스팅이 아닙니다.

// 핵심 : std::move 가 자원을 이동하는 것이 아닙니다.
// 1. 단지 rvalue 로 캐스팅을 하고
// 2. 캐스팅 결과를 복사가 아닌 이동 생성자가 호출되는 것이고
// 3. 자원의 이동은 해당 클래스의 "이동생성자"가 하는것

std::string s1 = "hello";
std::string s2 = std::move(s1);
				// 1. static_cast<std::string&&>(s1)
				// 2. 캐스팅 때문에 std::string "복사생성자가 아닌 이동생성자 호출"
				// 3. std::string 의 이동생성자에서 자원 이동.

int n1 = 10;
int n2 = std::move(n1);	// 아무 효과 없음
			// static_cast<int&&>(n1)

char s1[10] = "hello";
char s2[10] = std::move(s1); // 아무 효과 없고. error
							// char s2[10] = s1; 자체가 에러

const char* s1 = "hello";
const char* s2 = std::move(s1);	// 에러 아니지만 이동 효과 없음.



// 오후 수업은 13:00 에 시작 합니다.
