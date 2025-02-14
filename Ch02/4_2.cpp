#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <iostream>

using namespace std;

int main() {

	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++) {
		cout << rand() % 101 << endl;
	}

	_getch();
	return 0;
}
