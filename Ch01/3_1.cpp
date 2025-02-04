#include <iostream>
using namespace std;

int BoxVolume(int lenth, int width, int height){
    return lenth * width * height;
}

int BoxVolume(int lenth, int width){
    return lenth * width;
}

int BoxVolume(int lenth){
    return lenth;
}

int main() {

    cout<<BoxVolume(3,2,1)<<endl;
    cout<<BoxVolume(3,3)<<endl;
    cout<<BoxVolume(3)<<endl;
    
    return 0;
}
