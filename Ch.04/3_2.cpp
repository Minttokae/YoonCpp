#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
    enum {CLERK = 0, SENIOR = 1, ASSIST = 2, MANAGER = 3};
}

class NameCard {
    char* myName;
    char* Company;
    char* myNum;
    int myPos;

public:
    NameCard(char* name, char* comp, char* num, int pos): myPos(pos) {
        myName = new char[strlen(name) + 1];
        strcpy(myName, name);
        
        Company = new char[strlen(comp) + 1];
        strcpy(Company, comp);
        
        myNum = new char[strlen(num) + 1];
        strcpy(myNum, num);
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
    ~NameCard(){
        delete []myName;
        delete []Company;
        delete []myNum;
    }
};

int main() {
    NameCard manClerk("Lee", "ABC", "010-3643-3936", COMP_POS::CLERK);
    manClerk.ShowNameCardInfo();
    return 0;
}
