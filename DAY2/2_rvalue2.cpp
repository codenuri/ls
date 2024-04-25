// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       "표현식(expression)" 에 부여 되는 개념

// expression : 한개의 값을 나타내는 코드 집합
// statement  : C/C++에서는 ; 으로 끝나는 하나의 문장. 실행의 단위

// result : expression 의 결과로 나온값
// 			2개의 특징으로 구분합니다.
//			1. type
//			2. value category : lvalue, rvalue

int main()
{
	int n = 0;
	( n + 2 ) * 3;

	n + 2;	// result : 2
			// type : int
			// value category : rvalue 
			//	( 사용자가 할당한 메모리가 아닌 연산의 결과로 임시로 만든값)

	(n = 3); // 최종 결과값은 "n". 사용자가 할당한 메모리. lvalue
	(n = 3) = 10; // ok.. "n=3" 이라는 표현식은 lvalue!

	n = 3;
	++n = 10; // ok. ++n 은 lvalue

	n++ = 10; // error. n++ 은 rvalue. 즉, 프로그램실행중에 만들어진
				//					임시값 반환.. 
				//					사용자가 할당한 메모리 아님.
}			

// rvalue expression
// => 프로그램 연산 과정에 만들어지는 임시값들. ( n + 2)
// => 리터럴
// => 임시객체.

// lvalue expression 
// => named object
// => reference 를 반환하는 함수
// => "n = 10", "++n" 등 최종결과가 다시 사용자가 할당한 메모리가 나오는 코드.