#include <iostream>
#include <conio.h>

using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	
	Point *p3 = new Point;

	p3->xpos = p1.xpos + p2.xpos;
	p3->ypos = p1.ypos + p2.ypos;

	return *p3;
}

int main(void) {

	Point* pos1 = new Point;
	Point* pos2 = new Point;

	pos1->xpos = 1;
	pos1->ypos = 2;

	pos2->xpos = 2;
	pos2->ypos = 3;

	Point* pos3 = new Point;
	*pos3 = PntAdder(*pos1, *pos2);

	cout << pos3->xpos << ' ' << pos3->ypos;

	delete pos1;
	delete pos2;
	delete pos3;
	
	_getch();

	return 0;
}
