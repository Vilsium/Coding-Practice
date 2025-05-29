#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sizeOfArray;
    cout << "Enter size of array : ";
    cin >> sizeOfArray;
    vector<int> arr(sizeOfArray);
    cout << "Enter elements in array in sorted order(ascending):-" << endl;
    for(int i = 0; i < sizeOfArray; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter element you want to search : ";
    cin >> target;
    int low = 0, high = sizeOfArray - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == target) {
            cout << target << " is present on the index " << mid;
            break;
        } else if(arr[mid] > target) high = mid-1;
        else low = mid+1;
    }
}