#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sizeOfArray;
    cout << "Enter size of the array : ";
    cin >> sizeOfArray;
    int arr[sizeOfArray-1];
    cout << "Enter elements of array from 1 to " << sizeOfArray <<  " except one number in between :-" << endl;
    for(int i = 0; i < sizeOfArray-1; i++) {
        cin >> arr[i];
    }
    int sumOfArray = 0;
    for(int i : arr) {
        sumOfArray += i;
    }
    int actualSum = (sizeOfArray * (sizeOfArray+1)) / 2;
    cout << "Missing number  = " << actualSum - sumOfArray;
}