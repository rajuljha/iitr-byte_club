#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i > 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[(i-1)/2], heap[i]);
            i = (i-1)/2;
        }
    }

    void printHeap() {
        for(int i=0; i<heap.size(); i++)
            cout << heap[i] << " ";
        cout << "\n";
    }


    void deleteMax() {
    if(heap.size() == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    heap[0] = heap.back();
    heap.pop_back();

    int i = 0;
    while(i < heap.size()) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        // Find the largest among root, left child and right child
        int largest = i;
        if(left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if(right < heap.size() && heap[right] > heap[largest])
            largest = right;

        // Swap and continue heapifying if root is not largest
        if(largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}
};



int main() {
    MaxHeap maxHeap;
    maxHeap.insert(3);
    maxHeap.insert(4);
    maxHeap.insert(9);
    maxHeap.insert(5);
    maxHeap.insert(2);

    maxHeap.printHeap();

    maxHeap.deleteMax();

    maxHeap.printHeap();

    return 0;
}