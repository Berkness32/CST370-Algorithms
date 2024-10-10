// Title: Homework 5-1
// Abstract: Creating a heap
// Name: Aaron Berkness
// Date: 10/8/24

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to heapify
void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

// Function to check if the array is a max heap
bool isMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (heap[i] < heap[2 * i + 1]) return false;
        if (2 * i + 2 < n && heap[i] < heap[2 * i + 2]) return false;
    }
    return true;
}

// Function to insert a new element
void insertHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the max element
void deleteMax(vector<int>& heap) {
    if (heap.size() == 0) {
        return;
    }

    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, heap.size(), 0);
}

// Function to display the max element
void displayMax(vector<int>& heap) {
    if (heap.size() > 0)
        cout << heap[0] << endl;
    else
        cout << "Heap is empty!" << endl;
}

// Function to display the entire heap
void displayHeap(vector<int>& heap) {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, commandCount, value;
    cin >> n;

    vector<int> heap(n);
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    if (!isMaxHeap(heap)) {
        cout << "This is NOT a heap" << endl;
        buildMaxHeap(heap);
    } else {
        cout << "This is a heap." << endl;
    }

    cin >> commandCount;

    string command;
    for (int i = 0; i < commandCount; i++) {
        cin >> command;
        if (command == "displayMax") {
            displayMax(heap);
        } else if (command == "insert") {
            cin >> value;
            insertHeap(heap, value);
        } else if (command == "deleteMax") {
            deleteMax(heap);
        } else if (command == "display") {
            displayHeap(heap);
        }
    }

    return 0;
}

