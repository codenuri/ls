// 5_람다표현식6

// 람다표현식은 인자를 받는 방법 - 143p 아래 부분

int main()
{
	foo([](int a, int b) { return a + b; } );
	foo([](int a, int b) { return a - b; });
}
