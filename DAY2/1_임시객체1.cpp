// 1_임시객체1 - 77 page
#include <iostream>

// 임시객체 : modern c++ 에서 추가된 개념은 아닌데..
//         move 를 이해하려면 반드시 알아야 합니다.

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // named object : 이름이 있는 객체
					// 수명 : 자신을 선언한 {}을 벗어날때 파괴

//	Point (1, 2);	// unnamed object : 이름이 없는 객체
					// 수명 : 자신을 선언한 문장의 끝(;)에서 파괴
					// 임시객체(temporary) 라고도 합니다.

	// 아래 코드 실행결과 확인해 보세요.
	Point(1,2), std::cout << "X" << std::endl;

	std::cout << "-------" << std::endl;
}
// 참고. 임시객체 만들때
// 1. () 를 사용하면 함수 호출과 헷갈리게 됩니다. : Point(1,2)
// 2. {} 를 사용하면 가독성이 좋습니다.         : Point{1,2}


