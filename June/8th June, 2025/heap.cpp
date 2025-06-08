// Learning Heap in cpp
// Making a max-heap using array from scratch

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
        size++;
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

    //delete root node from the max-heap
    void deleteRoot() {
        if(size == 0) {
            cout << "No elements to delete";
            return ;
        }

        swap(arr[1], arr[size]);
        size--;
        int index = 1;
        while(index < size) {
            int leftChildIndex = 2*index;
            int rightChildIndex = 2*index + 1;
            
            if(leftChildIndex < size && arr[index] < arr[leftChildIndex]) {
                swap(arr[index], arr[leftChildIndex]);
                index = leftChildIndex;
            } else if(rightChildIndex < size && arr[index] < arr[rightChildIndex]) {
                swap(arr[index], arr[rightChildIndex]);
                index = rightChildIndex;
            } else return ;
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
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

    hp.deleteRoot();
    hp.print();
}