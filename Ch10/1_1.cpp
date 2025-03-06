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
friend Point operator-(const Point&, const Point&);
};

Point operator-(const Point& pnt1, const Point& pnt2){
    return Point(pnt1.xpos - pnt2.xpos, pnt1.ypos - pnt2.ypos);            
}

int main() {
    Point P1(1,2);
    Point P2(2,3);
    Point P3 = P1 - P2;

    P3.ShowPosition();
    
    return 0;
}
