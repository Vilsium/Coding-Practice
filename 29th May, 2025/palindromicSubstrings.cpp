#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while(left <= right) {
        if(str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter string : ";
    cin >> str;
    vector<string> result;
    for(int i = 0; i < str.length(); i++) {
        for(int j = 1; j < str.length()-i; j++) {
            string substr = str.substr(i, j);
            if(isPalindrome(substr)) result.push_back(substr);
        }
    }
    cout << "All palindromic substrings are:-" << endl;
    for(string s : result) {
        cout << s << " ";
    }
}