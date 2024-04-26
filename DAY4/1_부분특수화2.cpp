// 3_부분특수화1 - 156 p
#include <iostream>


template<typename T> class Stack
{
public:
	void push(T a) { std::cout << "T" << std::endl; }
};

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}
