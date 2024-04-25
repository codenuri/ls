// 1_√ ±‚»≠11 - 65 page..
// aggregate initialization

struct Point
{
	int x, y;

	Point()             : x(0), y(0) {}	// 1
	Point(int a, int b) : x(a), y(b) {}	// 2
};

int main()
{
	Point p1;	
	Point p2(1, 2);
}