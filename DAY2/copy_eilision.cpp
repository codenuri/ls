// copy_eilision.cpp

class Point 
{
public:
	Point(int a,int b) {} 
};
int main()
{	
	// 아래 한줄을 완벽히 이해해 봅시다.
	Point pt = Point(1, 2);
	
	// C++98 : 1. 우변의 표기법 때문에 임시객체 생성
	//         2. 임시객체가 복사 생성자를 사용해서 pt에 복사
	// => 그런데, 컴파일러들이 최적화를 통해서 임시객체 를 제거. 인자가 2개인 생성자호출
	// => 단, 복사생성자가 private 있다면 컴파일 에러.

	// C++11 : 1. 우변의 표기법 때문에 임시객체 생성
	//         2. 임시객체가 이동 생성자를 사용해서 pt에 복사
	// => 그런데, 컴파일러들이 최적화를 통해서 임시객체 를 제거. 인자가 2개인 생성자호출
	// => 단, 복사생성자가 이동생성자가 private 있다면 컴파일 에러.		

	// C++17 : 컴파일러 최적화가 더이상 "최적화"가 아닌 "문법"으로 !!
	// => 무조건 인자가 2개인 생성자호출
	// => "mandatory copy elision" 이라는 문법.
	// => 복사 생성자나 이동생성자가 private 또는 삭제되어도 에러 아님.
}
// move 복습하시다가 생각대로 결과가 나오지 않으면 "최적화 때문"

// g++ 소스.cpp -std=c++11 -fno-elide-constructors
// => 단, C++17 도 하지 마세요. 임시객체가 사라지는 문법이 적용됩니다.
/*
class Empty 
{
public:
	explicit Empty() = default; // 자동생성하는 생성자가 explicit 가 아니라서
								// explict 로 하기위해서 만든 코드
};

void foo(Empty e) {} // Empty e = {}

foo( {} );
*/