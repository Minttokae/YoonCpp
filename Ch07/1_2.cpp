#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(char* n, int age) : age(age)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~MyFriendInfo() {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(char* n, int age, char* address, char* num) : MyFriendInfo(n, age)
    {
        addr = new char[strlen(address) + 1];
        phone = new char[strlen(num) + 1];
        strcpy(addr, address);
        strcpy(phone, num);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소 : " << addr << endl;
        cout << "번호 : " << phone << endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main() {
    MyFriendDetailInfo frd1("Kang", 26, "수원", "010-3643-3936");
    frd1.ShowMyFriendDetailInfo();
        
    return 0;
}
