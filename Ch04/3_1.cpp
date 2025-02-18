#include <iostream>
using namespace std;

class Point{
private:
    int xpos;
    int ypos;

public:
    Point(int x, int y): xpos(x), ypos(y) 
        {}

    void ShowPointInfo() const{
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }

};

class Circle {
private:
    Point pos;
    int radius;

public:
    Circle(int x, int y, int r): pos(x, y), radius(r)
        {}

    void ShowCircleInfo() const{
        cout << "중심좌표: ";
        pos.ShowPointInfo();
        cout << "반지름: " << radius << endl;
    }
};

class Ring {
private:
    Circle circ1;
    Circle circ2;

public:
    Ring(int xpos1, int ypos1, int radius1,
            int xpos2, int ypos2, int radius2): circ1(xpos1, ypos1, radius1), circ2(xpos2, ypos2, radius2)
        {}
    
    void ShowRingInfo() const{
        cout << "Inner Circle " << endl;
        circ1.ShowCircleInfo();
        cout << endl;
        cout << "Outter radius " << endl;
        circ2.ShowCircleInfo();
    }
};

int main() {

    Ring ring(1,1,4,2,2,9); 
    
    ring.ShowRingInfo();
    
    return 0;
}
