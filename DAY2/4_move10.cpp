#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	

	// 이동 생성자나, 이동 대입연산자를 직접 만들게 된다면
	// 1. 되도록 예외가 발생하지 않도록 만드세요
	//    (이동의 구현 코드는 대부분 예외 없습니다. 포인터 복사 )
	// 2. 그리고, 예외가 없다고 컴파일러에게 반드시 알려주세요

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};
int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사
	Object o3 = std::move(o1); //항상 이동
	Object o4 = std::move_if_noexcept(o2); // 이동생성자에 예외가없다면 이동
										  // 예외 가능성이 있으면 복사
	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

// 2:15 분에 시작합니다.