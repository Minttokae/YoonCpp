#include "header.h"


void Mainpage() {
    cout << "-----MENU-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입    금" << endl;
    cout << "3. 출    금" << endl;
    cout << "4. 전체고객 잔액조회" << endl;
    cout << "5. 프로그램 종료" << endl << endl;

    cout << "선택: ";
}

Account::Account(int ID, char inname[NAME_LEN], int balance) : ID(ID), myMoney(balance)
{
    name = new char[strlen(inname) + 1];
    strcpy(name, inname);
};

Account::Account(const Account& copy) : ID(copy.ID), myMoney(copy.myMoney) {
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
}

int Account::GetID() const{
    return ID;
}
char* Account::Getname() const{
    return name;
}
int Account::Getmoney() const{
    return myMoney;
}
void Account::DepWith(int money, int type) {
    if (type == 0)
        myMoney += money;
    else if (type == 1)
        if (myMoney > money)
            myMoney -= money;
        else {
            cout << "잔액 부족";
            return;
        }
}

Account::~Account() {
    delete[]name;
}

/*
***********************************************************************************
*/

AccountHandler::AccountHandler() : top(0) {}

int AccountHandler::FindID(int ID) {
    int i;
    for (i = 0; i < top; i++) {
        if (ID == Accounts[i]->GetID())
            return i;
    }
    return -1;
}

bool AccountHandler::CreateAccount() {
    int MakeID, money;
    char cname[NAME_LEN];

    cout << "ID를 입력해주세요: ";
    cin >> MakeID;
    cout << "이름을 입력해주세요: ";
    cin >> cname;
    cout << "입금할 금액을 입력해주세요: ";
    cin >> money;

    Accounts[top] = new Account(MakeID, cname, money);
    top++;

    return 1;
}

void AccountHandler::Deposit() {
    int ID, money;
    int i;
    cout << "ID를 입력해주세요: ";
    cin >> ID;

    if ((i = FindID(ID)) == -1) {
        cout << "올바르지 않은 아이디 입니다." << endl;
        return;
    }

    cout << Accounts[i]->Getname() << " 고객님 " << "입금하실 금액을 입력해주세요:";
    cin >> money;
    Accounts[i]->DepWith(money, 0);

    cout << "입금 후 잔액: " << Accounts[i]->Getmoney() << endl;
    cout << "아무 키를 누르면 메인화면으로 이동합니다." << endl<<endl;

    _getch();
}

void AccountHandler::Withdraw() {
    int ID, money;
    int i;
    cout << "ID를 입력해주세요: ";
    cin >> ID;

    if ((i = FindID(ID)) == -1) {
        cout << "올바르지 않은 아이디 입니다." << endl;
        return;
    }

    cout << Accounts[i]->Getname() << "고객님 " << "출금하실 금액을 입력해주세요:";
    cin >> money;
    Accounts[i]->DepWith(money, 1);

    cout << "출금 후 잔액: " << Accounts[i]->Getmoney() << endl;
    cout << "아무 키를 누르면 메인화면으로 이동합니다." << endl << endl;

    _getch();
}

void AccountHandler::PrintAccounts() {
    for (int i = 0; i < top; i++) {
        cout << "ID: " << Accounts[i]->GetID() << endl;
        cout << "이름: " << Accounts[i]->Getname() << endl;
        cout << "잔액: " << Accounts[i]->Getmoney() << endl << endl;
    }
}

AccountHandler::~AccountHandler() {
    for (int i = 0; i < top; i++) {
        delete Accounts[i];
    }
}

