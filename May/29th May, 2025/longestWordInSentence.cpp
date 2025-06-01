#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter the sentence : ";
    getline(cin, sentence);
    stringstream ss(sentence);
    string word;
    string result;
    int maximumLength = 0;
    while(ss >> word) {
        if(word.length() > maximumLength) {
            maximumLength = word.length();
            result = word;
        }
    }
    cout << "Longest word in the sentence is => " << result;
}