#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sizeOfArray;
    cout << "Enter size of the array : ";
    cin >> sizeOfArray;
    int arr[sizeOfArray];
    cout << "Enter elements of array:-" << endl;
    for(int i = 0; i < sizeOfArray; i++) {
        cin >> arr[i];
    }
    int firstElement = arr[0];
    for(int i = 0; i < sizeOfArray-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[sizeOfArray - 1] = firstElement;
    cout << "Array after left rotating by 1:-" << endl;
    for(int i : arr) {
        cout << i << " ";
    }
}