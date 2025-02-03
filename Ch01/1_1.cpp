#include <iostream>

int main(){
    int i, sum = 0;
    for (int j = 1; j <= 5; j++){
        std::cout<<j<<"번째 정수입력 :";
        std::cin>>i;
        std::cout<<std::endl;
        
        sum += i;
    }
    std::cout<<"합계 :"<<sum;
    return 0;
}
