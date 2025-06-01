#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    // string reversedStr = str;
    // reverse(reversedStr.begin(), reversedStr.end());
    string reversedStr = "";
    int length = str.length();
    for(int i = length-1; i >= 0; i--) {
        reversedStr += str[i];
    }
    if(reversedStr == str) cout << str << " is a palindrome";
    else cout << str << " is not a palindrome";
}