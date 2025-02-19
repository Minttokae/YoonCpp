#include "header.h"

int top = 0;
AccountInfo Account[MAX_CLIENT];

void Mainpage() {
    cout << "-----MENU-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입    금" << endl;
    cout << "3. 출    금" << endl;
    cout << "4. 전체고객 잔액조회" << endl;
    cout << "5. 프로그램 종료" << endl << endl;

    cout << "선택: ";
}

bool CreateAccount() {
    cout << "ID를 입력해주세요: ";
    cin >> Account[top].ID;
    cout << "이름을 입력해주세요: ";
    cin >> Account[top].name;
    cout << "입금할 금액을 입력해주세요: ";
    cin >> Account[top].myMoney;

    top++;
    return 1;
}

void Deposit() {
    int ID, money;
    int i;
    cout << "ID를 입력해주세요: ";
    cin >> ID;

    for (i = 0; i < top; i++) {
        if (Account[i].ID == ID) {
            break;
        }
    }
    if (i == top) {
        cout << "올바르지 않은 아이디 입니다." << endl;
        return;
    }
    cout << Account[i].name << "고객님 " << "입금하실 금액을 입력해주세요:";
    cin >> money;
    Account[i].myMoney += money;

    cout << "입금 후 잔액: " << Account[i].myMoney << endl;
    cout << "아무 키를 누르면 메인화면으로 이동합니다." << endl<<endl;

    _getch();
}

void Withdraw() {
    int ID, money;
    int i;
    cout << "ID를 입력해주세요: ";
    cin >> ID;

    for (i = 0; i < top; i++) {
        if (Account[i].ID == ID) {
            break;
        }
    }
    if (i == top) {
        cout << "올바르지 않은 아이디 입니다." << endl;
        return;
    }

    cout << Account[i].name << "고객님 " << "출금하실 금액을 입력해주세요:";
    cin >> money;
    Account[i].myMoney -= money;

    cout << "출금 후 잔액: " << Account[i].myMoney << endl;
    cout << "아무 키를 누르면 메인화면으로 이동합니다." << endl << endl;

    _getch();
}

void PrintAccounts() {
    for (int i = 0; i < top; i++) {
        cout << "ID: " << Account[i].ID << endl;
        cout << "이름: " << Account[i].name << endl;
        cout << "잔액: " << Account[i].myMoney << endl << endl;
    }
}

