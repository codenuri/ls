#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;

	cout << d.value << endl; // 20

	// 멤버의 이름이 동일할때, 기반 클래스 멤버에 접근하는 방법
	// => 단, 값 캐스팅이 아닌 참조 캐스팅해야 합니다.
	cout << (static_cast<Base>(d)).value << endl;   // 값
	cout << (static_cast<Base&>(d)).value << endl; 
		

}
