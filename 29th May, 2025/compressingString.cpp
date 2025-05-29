#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string : ";
    cin >> str;

    string result = "";
    int count = 1;

    for (int i = 1; i <= str.length(); i++) {
        if (str[i] == str[i - 1]) count++;
        else {
            result += str[i - 1] + to_string(count);
            count = 1;
        }
    }

    cout << str << " after compressing becomes => " << result;
    return 0;
}
