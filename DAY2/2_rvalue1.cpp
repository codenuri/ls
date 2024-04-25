// 4_rvalue - 87 page

int x = 0;
int  foo() { return x;} // x의 값 "0" 반환
int& goo() { return x;} // x 의 별명 반환




// lvalue : 등호의 왼쪽과 오른쪽에 모두 올수 있는 표현식
//		    값과 이름(id)을 가진다.
//          단일식을 넘어서 사용.
//			주소연산자로 주소를 구할수 있다
//			"참조를 반환하는 함수"

// rvalue : 등호의 오른쪽에만 올수 있는 표현식(왼쪽에 올수 없다.)
//		    이름이 없고, 값만 있다. 단일식에서만 사용가능.
//			주소연산자로 주소를 구할수 없다
//			"값을 반환하는 함수"
//			리터럴, 임시객체

int main()
{
	int v1 = 10, v2 = 10;

	v1 = 20; 	// ok	  v1 : lvalue
	10 = v1;	// error. 10 : rvalue
	v2 = v1;

	int* p1 = &v1; // ok
	int* p2 = &10; // error.

	foo() = 10; // error. "0 = 10"
	goo() = 10; // ok     "x = 10"

	// 질문 #1
	const int c = 0;
	c = 10; // error. c 는 lvalue ? rvalue ?
			// "immutable lvalue"

	// 질문 #2
	// 모든 rvalue 는 상수이다 ??
	Point{0,0}.x = 10; // error. 문법상 rvalue 이므로 왼쪽에 올수 없는것
					   // 임시객체는 상수는 아닙니다.
	Point{0, 0}.set(10,10); // ok. 멤버 함수는 통한 상태 변경가능.
}












