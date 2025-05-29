#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter size of array(rows and columns) : ";
    cin >> rows >> cols;
    vector<vector<int>> arr(rows, vector<int> (cols));
    cout << "Enter elements of array:-" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Sum of each row of array:-" << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i+1 << " : " << sum << endl;
    }
}