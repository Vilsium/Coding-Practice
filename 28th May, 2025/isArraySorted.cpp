#include <iostream>
#include <vector>
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
    bool isSorted = true;
    for(int i = 0; i < sizeOfArray-1; i++) {
        if(arr[i] > arr[i+1]) {
            isSorted = false;
            break;
        }
    }
    if(isSorted) cout << "Given array is sorted in ascending order";
    else cout << "Given array is not sorted";
}