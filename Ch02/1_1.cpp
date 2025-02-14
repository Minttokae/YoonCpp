#include <iostream>
#include <conio.h>

using namespace std;

void Add1(int&);
void cngsign(int&);

int main() {
	int i;

	cin >> i;

	Add1(i);
	cngsign(i);


	cout << i;

	_getch();
}

void Add1(int& a) {
	a++;
}

void cngsign(int& a) {
	a -= 2 * a;
}
