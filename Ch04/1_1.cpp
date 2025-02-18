#include <iostream>
using namespace std;

class FruitSeller {
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money){
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int SaleApples(int money){
        if (money < 0) return 0; //if문 추가
        
        int apple = money/APPLE_PRICE;
        numOfApples -= apple;
        myMoney += money;
        return apple;
    }
    void ShowSalesRes() const{ //const 추가
        cout << "남은 사과: " << numOfApples << endl;
        cout <<<"판매 수익: " << myMoney << endl;
    }

class FruitBuyer {
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money){
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller& seller, int money){
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowSalesRes() const{ //const 추가
        cout << "남은 사과: " << numOfApples << endl;
        cout <<<"잔액: " << myMoney << endl;
    }
}
