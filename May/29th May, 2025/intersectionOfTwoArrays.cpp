#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int sizeOfArray1, sizeOfArray2;
    cout << "Enter size of array1 and array 2 : ";
    cin >> sizeOfArray1 >> sizeOfArray2;
    vector<int> arr1(sizeOfArray1);
    vector<int> arr2(sizeOfArray2);
    cout << "Enter elements for array1:-" << endl;
    for(int i = 0; i < sizeOfArray1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter elements for array2:-" << endl;
    for(int i = 0; i < sizeOfArray2; i++) {
        cin >> arr2[i];
    }
    unordered_set<int> st1(arr1.begin(), arr1.end());
    unordered_set<int> st2(arr2.begin(), arr2.end());
    unordered_set<int> intersectionSet;
    for(int i : st2) {
        if(st1.find(i) != st1.end()) {
            intersectionSet.insert(i);
        }
    }
    cout << "Elements present in intersection of array1 and array2 are => ";
    for(int i : intersectionSet) {
        cout << i << " ";
    }
}