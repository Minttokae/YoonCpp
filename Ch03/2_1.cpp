#include <iostream>

using namespace std;

class Calculator {
    private :
        int Addcnt = 0;
        int Mincnt = 0;
        int Mulcnt = 0;
        int Divcnt = 0;
        
        
    public :
        float Add(float x, float y);
        float Min(float x, float y);
        float Mul(float x, float y);
        float Div(float x, float y);

        void ShowOpcount();
};

float Calculator::Add(float x, float y){
    Addcnt++;
    return x + y;
}
float Calculator::Min(float x, float y){
    Mincnt++;
    return x - y;
}
float Calculator::Mul(float x, float y){
    Mulcnt++;
    return x * y;
}
float Calculator::Div(float x, float y){
    Divcnt++;
    return x / y;
}

void Calculator::ShowOpcount(){
    cout << "덧셈 : " << Addcnt << " 뺄셈 : " << Mincnt << " 곱셈 : " << Mulcnt << " 나눗셈 : " << Divcnt << endl;
}

int main() {
    Calculator cal;
    
    cal.init();
    cout << cal.Add(3.2, 2.4) << endl;
    cout << cal.Div(3.2, 2.4) << endl;
    cout << cal.Min(3.2, 2.4) << endl;
    cout << cal.Mul(3.2, 2.4) << endl;
    
    cal.ShowOpcount();
    
    return 0;
}
