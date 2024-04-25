void draw_line(int x1, int y1, int x2, int y2) {}

int main()
{
	// 1,1 ~ 3,3 위치에 선을 그리고 싶다.

	// #1. 변수를 만들어서 인자로 전달
	int x1 = 1, y1 = 1;
	int x2 = 3, y2 = 3;
	draw_line(x1, y1, x2, y2);

	// #2. literal 을 직접 전달
	draw_line(1, 1, 3, 3);
}