#include <iostream>
#include <cstring>

using namespace std;

class Printer {
    private :
        char* str;
    public :
        void SetString(const char* sen); //const 붙이기! "" 안에 있는 값은 '읽기 전용'이므로 경고창이 뜸.
        void ShowString();
};

void Printer::SetString(const char* sen) {
    str = new char[strlen(sen) + 1];
    strcpy(str, sen);
}

void Printer::ShowString() {
    cout << str << endl; // for문으로 일일이 돌지 않아도 주소값 전달을 통해 바로 출력 가능.
}

int main() {
    Printer pnt;
    pnt.SetString("Hello World");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    
    return 0;
}
