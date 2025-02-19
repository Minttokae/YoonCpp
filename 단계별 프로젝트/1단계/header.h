#pragma once
#include <iostream>
#include <cstdlib> //exit
#include <conio.h> // getch

#define MAX_CLIENT 50
#define NAME_LEN 10

using namespace std;

void Mainpage();
bool CreateAccount();
void Deposit();
void Withdraw();
void PrintAccounts();

struct AccountInfo {
	int ID;
	char name[NAME_LEN];
	int myMoney;
};

