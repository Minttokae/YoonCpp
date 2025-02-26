#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

namespace COMP_POS {
    enum { CLERK = 0, SENIOR = 1, ASSIST = 2, MANAGER = 3 };
}

class NameCard {
    char* myName;
    char* Company;
    char* myNum;
    int myPos;

public:
    NameCard(const char* name, const char* comp, const char* num, int pos) : myPos(pos) { 
//""내에 있는 문자열은 const char*이기 때문에 const를 붙여야 오류가 발생하지 않는다.
        myName = new char[strlen(name) + 1];
        strcpy(myName, name);

        Company = new char[strlen(comp) + 1];
        strcpy(Company, comp);

        myNum = new char[strlen(num) + 1];
        strcpy(myNum, num);
    }

//깊은 복사 생성자
    NameCard(NameCard& copy) : myPos(copy.myPos) {
        myName = new char[strlen(copy.myName) + 1];
        strcpy(myName, copy.myName);

        Company = new char[strlen(copy.Company) + 1];
        strcpy(Company, copy.Company);

        myNum = new char[strlen(copy.myNum) + 1];
        strcpy(myNum, copy.myNum);
    }


    void ShowNameCardInfo() {
        cout << "이름: " << myName << endl;
        cout << "회사: " << Company << endl;
        cout << "전화번호: " << myNum << endl;

        string Kpos;
        switch (myPos) {
        case 0: Kpos = "점원"; break;
        case 1: Kpos = "주임"; break;
        case 2: Kpos = "대리"; break;
        case 3: Kpos = "매니저"; break;
        }

        cout << "직급: " << Kpos << endl;

    }
    ~NameCard() {
        delete[]myName;
        delete[]Company;
        delete[]myNum;
    }
};

int main() {
    NameCard manClerk("Lee", "ABC", "010-3643-3936", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    manClerk.ShowNameCardInfo();
    copy1.ShowNameCardInfo();
    _getch();
    return 0;
}
