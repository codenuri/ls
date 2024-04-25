// C++98 enum
// => COLOR 이름 없이 사용가능. 위험합니다. 아래 main 참고
// enum COLOR { red = 0, blue = 1, green = 2};

// C++11 의 enum class
// => 타입성이 강화된 새로운 enum 문법
enum class COLOR { red = 0, blue = 1, green = 2};

int main()
{
	int n0 = red; 		 // error. COLOR 생략할수 없음.
	int n1 = COLOR::red; // error. int 타입으로 변환 안됨
	
	COLOR n3 = COLOR::red; // ok. 

	// C언어는 "COLOR::green - COLOR::red" 등의 기법을 사용할때도 있습니다.
	// => 이런기술이 필요하면 static_cast로 하세요
	int n4 = static_cast<int>(COLOR::green);  // 이렇게하면 정수 변환 가능.
}
void set_color(int c) {} // set_color(COLOR::red) 로 사용할수 없음
void set_color(COLOR c) {} // 이렇게 해야 합니다.
							// int 로 받았다면 set_color(100)도가능





