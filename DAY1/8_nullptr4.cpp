// 8_nullptr4.cpp
void f1(int* p) {}
void f2(char* p) {}

// nullptr 을 직접 만들어 봅시다. - C++11 이전에는 직접 만들어서 사용했습니다.
// 1. C++11 이전에 boost 라이브러리에서 아래 코드 를 제공했습니다.
// 2. C++11 에서 표준에 채택되는데, 표준에서는 nullptr 이 키워드 입니다.
//    (아래와 같은 객체가 아닌 키워드. 리터럴.)
struct nullptr_t 
{
	// 변환 연산자 : 객체가 다른 타입으로 암시적 변환 될때 호출되는 함수
	template<typename T>
	constexpr operator T*() const { return 0;}
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr); // nullptr_t => int* 로의 암시적 형변환이 필요!!
					// mynullptr.operator int*() 라는 멤버함수 필요
//	f2(mynullptr);
}