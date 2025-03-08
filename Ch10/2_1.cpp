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
/*
    Point& operator-(){
        xpos = -xpos;
        ypos = -ypos;
        return *this;
    }
    이렇게 하면 객체값을 변경하고 참조하게 됨.
*/
    Point operator-(){
        return Point(-xpos, -ypos);
    }
};



int main() {
    Point pnt1(1,2);
    Point pnt2 = -pnt1;

    pnt2.ShowPosition();
    
    return 0;
}
