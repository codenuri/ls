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
	virtual void foo()      override final {} // 파생클래스는 더이상 재정의 할수 없다.
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};
class Derived2 : public Derived 
{
public:
	virtual void foo() override {} // error. 더이상 재정의 안됨.
};

int main()
{
}