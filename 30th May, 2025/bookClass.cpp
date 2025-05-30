#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
    }

    void display() {
        cout << "The book " << this->title << " is written by " << this->author;
    }
};

int main() {
    Book myBook("Let Us C", "Yashwant Kanetkar");
    myBook.display();
}