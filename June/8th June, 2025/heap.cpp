// Learning Heap in cpp
// Making a max-heap using array from scratch

#include <iostream>
#include <queue>
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

void heapify(int arr[], int size, int index) {
    int largest = index;
    int leftChildIndex = 2 * index;
    int rightChildIndex = 2 * index + 1;

    if(leftChildIndex <= size && arr[index] < arr[leftChildIndex]) largest = leftChildIndex;
    if(rightChildIndex <= size && arr[index] < arr[rightChildIndex]) largest = rightChildIndex;

    if(largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

//heap sort
void heapSort(int arr[], int size) {
    int heapSize = size;
    while(heapSize > 1) {
        swap(arr[heapSize], arr[1]);
        heapSize--;
        heapify(arr, heapSize, 1);
    }
}

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

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Array after heapifying: ";
    for(int i = 1;i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Array after sorting: ";
    for(int i = 1;i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Using Priority Queue (include queue for it)
    priority_queue<int> pq; //Max-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap; //Min-Heap

    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(2);

    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(2);

    cout << "Element at top of pq : " << pq.top() << endl;
    pq.pop();
    cout << "Element at top of pq : " << pq.top() << endl;
    cout << "Size of pq : " << pq.size() << endl;
    if(!pq.empty()) cout << "There are still elements in pq" << endl;

    cout << "Element at top of minHeap : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at top of minHeap : " << minHeap.top() << endl;
    cout << "Size of minHeap : " << minHeap.size() << endl;
}