// 8_nullptr - 29page

int main()
{
	// C++98 스타일
	int  n1 = 0; // 0은 정수 입니다
	int* p1 = 0; // 하지만, 포인터 초기화에 0 사용가능합니다.
//	int* p2 =10; // error. 리터럴 0만 가능하고 10은 안됩니다.

	// C++11 부터는 포인터 초기화 시에 0대신 nullptr 권장
	int* p3 = nullptr; // ok
//	int  n2 = nullptr; // error. nullptr 은 포인터 초기화만 가능
}