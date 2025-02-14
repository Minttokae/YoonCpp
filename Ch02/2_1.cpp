#include <iostream>
#include <conio.h>

using namespace std;

int main(void) {

	const int num = 12;
	const int* ptr = &num;
	const int*& ref = ptr;

	cout << *ptr << endl;
	cout << *ref;

	_getch();

	return 0;
}
