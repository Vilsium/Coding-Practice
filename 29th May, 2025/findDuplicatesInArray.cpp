#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int sizeOfArray;
    cout << "Enter size of array : ";
    cin >> sizeOfArray;
    vector<int> arr(sizeOfArray);
    cout << "Enter elements of array:-" << endl;
    for(int i = 0; i < sizeOfArray; i++) {
        cin >> arr[i];
    }
    vector<int> result;
    unordered_set<int> st;
    for(int i : arr) {
        if(st.find(i) != st.end()) result.push_back(i);
        st.insert(i);
    }
    cout << "Duplicates in the array are:-" << endl;
    for(int i : result) {
        cout << i << " ";
    }
}