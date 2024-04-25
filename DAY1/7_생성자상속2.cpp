#include <list>
#include <initializer_list>
#include <iostream>

// 파생 클래스를 만들때 "멤버 데이타" 를 추가하는 경우
// => 생성자도 만들어서 멤버 데이타를 초기화 하는 것이 관례

// 파생 클래스를 만들때 "멤버 함수" 만 추가하는 경우
// => 생성자를 만들지 않는 경우가 더 많습니다.
// => 이 경우는 기반 클래스 생성자를 상속 받는것이 편리 합니다

template<typename T>
class MyList : public std::list<T>
{
public:
	void show() const 
	{
		for( auto& e : *this)
			std::cout << e << ", ";
		std::cout << "\n";
	}
	// C++98 이라면 아래 처럼 list 에 있는 모든 생성자를 여기도 구현
	MyList(int sz, int v) : std::list<T>(sz, v) {}
	MyList(int sz)        : std::list<T>(sz) {}
//	MyList(std::initializer_list<T> e) : std::list<T>(e) {}

	// C++11 이후에는 생성자 상속 문법이면 됩니다
	using std::list<T>::list;
};

int main()
{
	MyList<int> st1(10, 3); 
	MyList<int> st2(10);
	MyList<int> st3 = {1,2,3,4,5};
}




