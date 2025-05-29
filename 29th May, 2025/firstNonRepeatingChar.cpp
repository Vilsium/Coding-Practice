#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    cout << "Enter string : ";
    cin >> str;
    unordered_map<char, int> mpp;
    for(char c : str) {
        mpp[c]++;
    }
    for(char c : str) {
        if(mpp[c] == 1) {
            cout << c << " is the first non repeating character in the string " << str;
            break;
        }
    }
}