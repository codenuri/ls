#include <iostream>

// shallow copy vs deep copy

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& other ) : age(other.age)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name)+1, other.name);	
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; 
}
