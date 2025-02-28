#include "header.h"


int main() {
    int select;
    AccountHandler actHandler;
    while (1) {
        Mainpage();

        cin >> select;
        cout << endl;

        switch (select)
        {
        case 1: actHandler.CreateAccount(); break;
        case 2: actHandler.Deposit();  break;
        case 3: actHandler.Withdraw();  break;
        case 4: actHandler.PrintAccounts(); break;
        case 5: exit(0);

        default: 
            cout << "잘못된 값" << endl << endl; continue;
        }
    }

    return 0;
}
