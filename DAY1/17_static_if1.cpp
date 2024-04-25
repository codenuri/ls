// 에러를 찾아 보세요
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error
	}
};
int main()
{
	A a;
}
*/
// 
template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;  // (A)
	}
};
int main()
{
	A<int> a;

	a.foo(); // 이렇게 사용하는 코드가 있어야만 (A) 부분이 에러
}
// 지연된 인스턴스화 : 클래스 템플릿에서 사용된 함수만 인스턴스화(실제 C++코드로 생성)
//					된다는 문법. 