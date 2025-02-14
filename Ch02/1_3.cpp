#include <iostream>
#include <conio.h>

using namespace std;

void SwapPointer(int*& ref1, int*& ref2) { // *& 순서가 바뀌면 오류가 발생!
	int* temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void) {
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	cout << "val1 : " << *ptr1 << endl;
	cout << "val2 : " << *ptr2;

	_getch();

	return 0;
}
