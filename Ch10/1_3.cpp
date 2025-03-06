#include <iostream>
using namespace std;

class Point 
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition()
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
friend bool operator==(const Point& pnt1, const Point& pnt2);
friend bool operator!=(const Point& pnt1, const Point& pnt2);
};

bool operator==(const Point& pnt1, const Point& pnt2){
    cout << "Good" << endl;
    return (pnt1.xpos == pnt2.xpos) && (pnt1.ypos == pnt2.ypos);
}

bool operator!=(const Point& pnt1, const Point& pnt2){
    cout << "Good" << endl;
    return (pnt1.xpos != pnt2.xpos) || (pnt1.ypos != pnt2.ypos);
}

int main() {
    Point P1(1,2);
    Point P2(2,3);
    Point P3(2,3);

    cout << (P1 == P2) << endl; 
    cout << (P1 != P2) << endl;
    cout << (P2 == P3) << endl; // 괄호 써주기
    
    return 0;
}
