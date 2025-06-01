#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    int count = 0;
    for(char c : str) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    cout << "No of vowels in " << str << " = " << count;
}