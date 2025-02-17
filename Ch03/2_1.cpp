#include <iostream>

using namespace std;

class Calculator {
    private :
        int Addcnt;
        int Mincnt;
        int Mulcnt;
        int Divcnt;
        
        
    public :
        void init();
        float Add(float x, float y);
        float Min(float x, float y);
        float Mul(float x, float y);
        float Div(float x, float y);

        void ShowOpcount();
};

void Calculator::init() {
    Addcnt = 0;
    Mincnt = 0;
    Mulcnt = 0;
    Divcnt = 0;
}

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
    cout << cal.Div(3.5, 1.7) << endl;
    cout << cal.Min(2.2, 1.5) << endl;
    cout << cal.Div(4.9, 1.2) << endl;
    
    cal.ShowOpcount();
    
    return 0;
}
