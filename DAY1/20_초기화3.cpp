int main()
{
	// C++98 : 표준 타입끼리의 암시적 변환 허용 (데이타 손실 발생)
	int  n1 = 3.4; // ok. 하지만 나쁜 코드
	char c1 = 500; // ok. 하지만 오버플로우!

	// prevent narrow - 56 page
	int n2{ 3.4 }; 	// error 
	char c2{ 500 }; // error. 오버 플로우 발생

}