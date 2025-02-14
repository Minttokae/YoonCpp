#include <iostream>
#include <conio.h>

using namespace std;

void SwapByRef2(int& ref1, int& ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void) {
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(23, 45);
  /*참조자 매개변수는 변수를 받아야 하는데 상수를 넘기게 되면 오류가 발생 */
  
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2;

	_getch();

	return 0;
}
