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
	
	// 대입연산자 
	// Cat c2 = c1; // 복사 생성자
	// c2 = c1;     // 대입 연산자
	Cat& operator=(const Cat& c)
	{
		if( &c == this) return *this;
		age = c.age;

		if ( strlen(name) != strlen(c.name) )
		{
			delete[] name;
			name = new char[strlen(c.name)+1];
		}
		strcpy_s(name, strlen(c.name) + 1, c.name);
		return *this;
	}



	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}

	Cat& operator=(Cat&& c)
	{
		if( &c == this) return *this;

		delete[] name;

		age = c.age;
		name = c.name;

		c.name = nullptr;
	
		return *this;
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




