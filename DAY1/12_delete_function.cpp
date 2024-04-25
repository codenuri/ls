// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 함수 삭제 문법
	// => 사용자가 만들지 않으면 컴파일러가 기본 제공하는 멤버 함수를
	// => 만들지 말라고 하기 위해 사용
	Point(const Point&) = delete;
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 컴파일러가 제공하는 디폴트 복사 생성자 사용
				  // 삭제 되어 있다면 에러!!
}