#pragma once
#include <iostream>
#include <cstdlib> //exit
#pragma warning(disable:4996)
#include <conio.h> // getch
#include <cstring>

#define MAX_CLIENT 50
#define NAME_LEN 10

using namespace std;


void Mainpage();

class Account {
	const int ID;
	char* name;
	int myMoney;
public:
	Account(int ID, char name[NAME_LEN], int balance);
	Account(const Account& copy);
	int GetID() const;
	char* Getname() const;
	int Getmoney() const ;
	void DepWith(int money, int type);
	~Account();
};

class AccountHandler {
	int top;
	Account* Accounts[MAX_CLIENT];

public:
	AccountHandler();
	int FindID(int ID);
	bool CreateAccount();
	void Deposit();
	void Withdraw();
	void PrintAccounts();
	~AccountHandler();
};
