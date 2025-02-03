#include <iostream>
using namespace std;

int main(){
    int amount;

    while(1){
        cout<<"이번달 판매 금액(1만원 단위) : ";
        cin>>amount;
        if (amount == -1) break;
        cout<<endl;

        cout<<"이번달 급여 : "<<50 + amount * 0.12;
    }
        cout<<"종료";
    return 0;
}
