#include <iostream>

using namespace std;

struct Point {
    int xpos;
    int ypos;

    void MovePos(int x, int y) {
        xpos += x;
        ypos += y;
    }

    void Addpoint(const Point& pos){ // &가 없어도 결과는 같다. 하지만 값을 복사하여 메모리 복사 비용이 발생.
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void ShowPosition() {
        cout << '[' << xpos << ", " << ypos << ']' <<endl;        
    }   
};

int main() {

    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.Addpoint(pos2);
    pos1.ShowPosition();
    
    return 0;
}
