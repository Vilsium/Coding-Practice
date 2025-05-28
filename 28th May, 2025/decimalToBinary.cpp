#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cout << "Enter number in decimal : ";
    cin >> num;
    string binaryNumber = "";
    int temp = num;
    while(temp > 0) {
        binaryNumber += to_string(temp % 2);
        temp /= 2;
    }
    reverse(binaryNumber.begin(), binaryNumber.end());
    cout << "Binary representation of " << num << " = " << binaryNumber;
}