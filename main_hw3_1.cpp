// Title: Homework 3-1
// Abstract: Display numbers in ascending order
// Name: Aaron
// Date: 9/17/24

#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    int loopCount = 0;
    stack<int> consecutive;
    
    while (loopCount < 1) {
        cin >> loopCount;
    }
    int nums[loopCount];
    
    for (int i = 0; i < loopCount; i++) {
        cin >> nums[i];
    }
    
    insertionSort(nums, loopCount);
    
    int count = 1;
    consecutive.push(0);
    consecutive.push(nums[loopCount - 1]);
    for (int i = (loopCount - 2); i > -1; i--) {
        int temp = nums[i + 1];
        if (temp - 1 != nums[i]) {
            if (consecutive.top() == temp) {
                consecutive.push(nums[i]);
                count++;
            } else {
                consecutive.push(nums[i + 1]);
                count++;
                consecutive.push(nums[i]);
                count++;
            }
        } else {
            if (consecutive.top() != -1) {
                consecutive.push(-1);
                count++;
            }
        }
    }
    
    if (consecutive.top() != nums[0]) {
        consecutive.push(nums[0]);
        count++;
    }
    
    
    for (int i = 0; i < count; i++) {
        if (consecutive.top() != -1) {
            cout << consecutive.top();
            consecutive.pop();
            if (consecutive.top() != -1) {
                cout << " ";
            }
        } else {
            cout << "-";
            consecutive.pop();
        }
    }
}
