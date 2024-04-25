class Point 
{
	int x, y;
public:
	Point(int a, int b) : x{a}, y{b} {}
};
void f1(int n)    {}
void f2(Point pt) {}
Point f3() { return {1,2};}

int main()
{
	// 함수의 인자 전달은 "복사 초기화(copy initialization)" 입니다.
	f1(3);   // int n = 3;
	f1({3}); // int n = {3};

	f2({1,2}); // Point pt = {1,2}
}