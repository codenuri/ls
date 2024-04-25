// 9_enum - 32 page
// C++98 enum
// => COLOR 이름 없이 사용가능. 위험합니다. 아래 main 참고
enum COLOR { red = 0, blue = 1, green = 2};

int main()
{
	int n1 = COLOR::red; // 정확한 표기법
	int n2 = red;        // COLOR 생략가능

	int red = 100;

	int n3 = red; // ? 100 ? 0  지역변수 red..
}





