#include <iostream>
using namespace std;

void swap(int* n1, int *n2){
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void swap(char* c1, char* c2){
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

int main() {
    int num1 = 20, num2 = 10;
    swap(&num1, &num2);
    cout<<num1<<' '<<num2<<endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    cout<<ch1<<' '<<ch2<<endl;
    
    return 0;
}
