// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}
	// C++17 부터 위 코드는 아래 처럼 사용가능합니다.
	// if ( 초기화구문 ; 조건식 )
	if ( int ret2 = foo(); ret2 == 0)
	{
	} //<== ret2 파괴.

	// switch 도 가능합니다.
	switch( int n = foo(); n) 
	{
		case 1: break;
	}
}