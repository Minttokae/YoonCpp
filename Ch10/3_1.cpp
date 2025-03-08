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
    friend void operator>>(istream& istm, Point& pnt);
};

void operator>>(istream& istm, Point& pnt) {
    istm >> pnt.xpos;
    istm >> pnt.ypos;
}

int main() {
    Point pnt2;
    cin >> pnt2;

    pnt2.ShowPosition();
    
    return 0;
}
