#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter 2 strings : ";
    cin >> str1 >> str2;
    if(str1.length() != str2.length()) {
        cout << str1 << " and " << str2 << " are not anagrams";
        return 0;
    }
    unordered_map<char, int> mpp;
    for(char c : str1) {
        mpp[c]++;
    }
    for(char c : str2) {
        mpp[c]--;
    }
    for(auto it : mpp) {
        if(it.second != 0) {
            cout << str1 << " and " << str2 << " are not anagrams";
            return 0;
        }
    }
    cout << str1 << " and " << str2 << " are anagrams";
}