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
    Point& operator+=(const Point& pnt){
        xpos += pnt.xpos;
        ypos += pnt.ypos;
        cout << "Good" << endl;
        return *this;
    }
    Point& operator-=(const Point& pnt){
        xpos -= pnt.xpos;
        ypos -= pnt.ypos;
        cout << "Good" << endl;
        return *this;
    }
};

int main() {
    Point P1(1,2);
    Point P2(2,3);
    P1 -= P2;
    P2 += P1;

    P1.ShowPosition();
    P2.ShowPosition();
    
    return 0;
}
