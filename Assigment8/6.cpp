#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> heap;   

    
    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

   
    void heapifyUp(int i) {
        if (i == 0) return;
        int parent = (i - 1) / 2;

        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            heapifyUp(parent);
        }
    }

public:
    
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

   
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

  
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }
};


int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(5);

    cout << "Max element: " << pq.top() << endl;

    pq.pop();
    cout << "After removing max, new top: " << pq.top() << endl;

    return 0;
}
