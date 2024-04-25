#include <iostream>
#include <cstring>


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

		std::cout << "copy \n";
	}
	// 임시객체를 위한 복사 생성자(move 생성자라고 합니다.)
	Cat(Cat&& other ) 
		: name(other.name),  age(other.age)
	{
		// 임시객체가 자원을 포기하도록 한다.
		// => 이 코드를 작성하려면 "임시객체" 라도 non-const 로 받아서
		//    변경할수 있게 해야 한다.!
		other.name = nullptr;

		std::cout << "move \n";
	}	
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	// 아래 한줄의 성능을 생각해 보세요 
	Cat c1 = foo(); 	// move

	Cat c2("nabi", 2);
	Cat c3 = c2; 		// copy
}
// 위 코드가 예상대로 나오지 않을수 있습니다.
// => 컴파일러 최적화 때문에 
// => "copy ellision" 이라는 최적화!! 다음 단계에서 자세히.. 





