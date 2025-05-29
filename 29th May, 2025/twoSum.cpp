//Finding all the pairs that adds up to a target

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int sizeOfArray;
    cout << "Enter size of the array : ";
    cin >> sizeOfArray;
    vector<int> arr(sizeOfArray);
    cout << "Enter elements of array:-" << endl;
    for(int i = 0; i < sizeOfArray; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter your target number : ";
    cin >> target;
    vector<pair<int, int>> result;
    unordered_map<int, int> mpp;
    for(int i : arr) {
        int remTarget = target - i;
        if(mpp.find(remTarget) != mpp.end()) {
            result.push_back({i, remTarget});
            mpp[i]--;
        }
        mpp[i]++;
    }
    cout << "Pairs that equals to target:-" << endl;
    for(auto it : result) {
        cout << "<" << it.first << ", " << it.second << ">" << endl;
    }
}