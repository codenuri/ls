// 91 page
int main()
{
	int n = 10;

	int *p = &n;
	int* *pp = &p;	// 포인터에 포인터는 만들수 있습니다.(이중 포인터)

	int& r = n;
	int& &rr = r;	// 레퍼런스의 레퍼런스를 "직접 코딩으로" 만들수 없습니다.

	// 하지만, type 별칭이나, 타입 추론과정에서 발생하는 레퍼런스의 레퍼런스는
	// 에러가 아니고, "reference collapsing" 규칙 적용.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n ;  // int&  &	=> int& 
	RREF& r4 = n ;  // int&& &	=> int&
	LREF&& r5 = n;  // int&  &&	=> int&
	RREF&& r6 = 5;  // int&& &&	=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a; // int& & r = a;
			  // int& r = a;
}
int n = 0;
foo<int&>(n);





