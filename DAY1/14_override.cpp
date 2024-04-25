// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 가상함수 재정의시 실수(오타)
	// => 에러가 아니라, 새로운 가상함수를 만든것으로 취급됨. 
//	virtual void fooo() {} // ok. 에러 아님.

	// 그래서 C++11 만들때 override 키워드 추가.
	virtual void goo(double a) override {} // error
	virtual void hoo() const   override {} // error
};


int main()
{
}