// 7_�����ڻ��1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// C++98 : 생성자는 상속될수 없다.
	// C++11 : 생성자도 아래처럼하면 상속될수있다.
	using Base::Base; // 생성자 상속 문법.
};

int main()
{
	// 아래 코드를 생각해 보세요
	Derived d1;
	Derived d2(5);
}
