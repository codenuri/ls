// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자 ( C++98 문법 )
	// => 직접 초기화만 가능하고, 복사초기화는 사용할수 없다.
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// 인자가 한개인 생성자가 있다면 아래 4가지 형태로 객체생성 가능.
	Vector v1(10); 	// C++98 스타일의 direct initialization
	Vector v2 = 10; // C++98 스타일의 copy   initialization
	Vector v3{ 10 };// C++11 스타일의 direct initialization
	Vector v4 = { 10 }; // C++11 스타일의 copy   initialization

	//----------------
	foo(10); // Vector v = 10
}







