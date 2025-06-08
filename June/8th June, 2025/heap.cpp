// Learning Heap in cpp
// Making a heap using array from scratch

#include <iostream>
using namespace std;

class heap {
private:
    int arr[100];
    int size;

public:
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1) {
            int parentIndex = index / 2; //calculating the index of the parent where the node has been inserted
            if(arr[parentIndex] < arr[index]) {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else return ;
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    heap hp;
    hp.insert(50);
    hp.insert(55);
    hp.insert(53);
    hp.insert(52);
    hp.insert(54);
    hp.print();
}