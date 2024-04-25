// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// 멤버 데이타 캡쳐 ?
		auto f = [](int a) { return a + data; };

	}
};

int main()
{
	Test t;
	t.foo(); 
}

