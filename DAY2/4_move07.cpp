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

/*
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
*/
};

int main()
{	
	// 이동 생성자가 없는 타입에 대해서 std::move() 를 사용했다면!!
	// => 복사 생성자 사용!!
	// => 이동이 필요 할때 복사를 해도 문제가 되지 않는다.
	// => 단, 성능 향상은 안된다.
	
	Cat c1("nabi", 2);
	Cat c2 = c1;   	// 복사 생성자
	c2 = c1;		// 대입 연산자

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




