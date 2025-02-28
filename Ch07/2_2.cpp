#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char* title;
    char* isbn;
    int price;
public:
    Book(char* btitle, char* code, int money) : price(money) {
        title = new char[strlen(btitle) + 1];
        isbn = new char[strlen(code) + 1];
        strcpy(title, btitle);
        strcpy(isbn, code);
    }
    void ShowBookInfo() {
        cout << "Title : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "Price : " << price << endl;
    }
};

class EBook : public Book {
    char* DRMKey;
public:
    EBook(char* btitle, char* code, int money, char* Key) : Book(btitle, code, money) {
        DRMKey = new char[strlen(Key) + 1];
        strcpy(DRMKey, Key);
    }
    void ShowBookInfo() {
        Book::ShowBookInfo();
        cout << "DRMKey : " << DRMKey << endl;
    }
};

int main() {
    Book book("c++", "555-5555-55", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("c++ E", "666-66666-66", 10000, "fldsj41242");
    ebook.ShowBookInfo();
    return 0;
}
