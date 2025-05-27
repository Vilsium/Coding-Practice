#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int sizeOfArray;
    cout << "Enter size of array : ";
    cin >> sizeOfArray;
    int arr[sizeOfArray];
    cout << "Enter elements of array:-" << endl;
    for(int i = 0; i < sizeOfArray; i++) {
        cin >> arr[i];
    }
    vector<int> result;
    unordered_set<int> st;
    for(int i : arr) {
        if(st.find(i) == st.end()) {
            st.insert(i);
            result.push_back(i);
        }
    }
    cout << "Array after removing duplicates:-" << endl;
    for(int i : result) {
        cout << i << " ";
    }
}