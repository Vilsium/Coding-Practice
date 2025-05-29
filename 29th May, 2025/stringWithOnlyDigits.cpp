#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter string : ";
    cin >> str;
    for(char c : str) {
        if(isalpha(c)) {
            cout << str << " does not contains all only digits";
            return 0;
        }
    }
    cout << str << " contains only digits";
}