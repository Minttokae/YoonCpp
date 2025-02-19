#include "header.h"

int main() {
    int select;

    while (1) {
        Mainpage();

        cin >> select;
        cout << endl;

        switch (select)
        {
        case 1: CreateAccount(); break;
        case 2: Deposit();  break;
        case 3: Withdraw();  break;
        case 4: PrintAccounts(); break;
        case 5: exit(0);

        default: 
            cout << "잘못된 값" << endl << endl; continue;
        }
    }

    return 0;
}
