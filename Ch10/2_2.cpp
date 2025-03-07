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
    Point& operator-(){
        xpos = -xpos;
        ypos = -ypos;
        return *this;
    }
    friend Point operator~(Point pnt);
};

Point operator~(Point pnt){
    int temp = pnt.xpos;
    pnt.xpos = pnt.ypos;
    pnt.ypos = temp;
    return pnt;
}


int main() {
    Point pnt1(1,2);
    Point pnt2 = ~pnt1;

    pnt2.ShowPosition();
    
    return 0;
}
