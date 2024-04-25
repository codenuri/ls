#include <iostream>

class Counter 
{
public:
	int cnt = 0;

//	Counter increment() 
	Counter& increment() 
	{
		++cnt; 
		return *this;
	}
	~Counter() { std::cout << "~Counter\n"; }

	Counter(const Counter& c) : cnt(c.cnt) 
	{
		std::cout << "Counter(const Counter&)\n";
	} 
	Counter() = default;
};
int main()
{
	Counter c;
	
	std::cout << "========================\n";
	c.increment().increment().increment();
	std::cout << "========================\n";

	std::cout << c.cnt << std::endl;
}