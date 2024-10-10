// Title: Homework 2-1
// Abstract: Calculating the distance between numbers
// Name: Aaron Berkness
// Date: 9/10/24

#include <iostream>
#include <cstdlib>
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
    
    while (loopCount < 1) {
//        cout << "How many numbers will you be entering? ";
        cin >> loopCount;
    }
    
    int num[loopCount];
    
//    cout << "Which numbers do you wish to test?" << endl;
    
    for (int i = 0; i < loopCount; i++) {
        cin >> num[i];
    }
    
//    cout << "\n";
    
    insertionSort(num, loopCount);
//    for (int i = 0; i < loopCount; i++) {
//        cout << num[i] << endl;
//    }
    
    int min, temp, index = 0;
    int maxIndex = 1;
    int matchingNum1[loopCount];
    int matchingNum2[loopCount];
    
    min = abs(num[0] - num[1]);
    matchingNum1[index] = num[0];
    matchingNum2[index] = num[1];
    index++;
    
    for (int x = 1; x < loopCount - 1; x++) {
        temp = abs(num[x] - num[x + 1]);
        if (temp < min) {
            min = temp;
            index = 0;
            matchingNum1[index] = num[x];
            matchingNum2[index] = num[x + 1];
            maxIndex = 1;
//            cout << "\n";
//            cout << "New minimum is: " << min << endl;
//            cout << "Adding matching pair: " << matchingNum1[index] << " " << matchingNum2[index] << endl;
            index++;
        } else if (temp == min) {
            matchingNum1[index] = num[x];
            matchingNum2[index] = num[x + 1];
//            cout << "Adding matching pair: " << matchingNum1[index] << " " << matchingNum2[index] << endl;
            index++;
            maxIndex++;
//            cout << "Max index: " << maxIndex << endl;
        }
    }
    
//    cout << "\n";
    cout << "Minimum distance: " << min << endl;
    for (int i = 0; i < maxIndex; i++) {
        //cout << "Loop index: " << i << endl;
        cout << "Pair: " << matchingNum1[i] << " " << matchingNum2[i] << endl;
        
    }
    
    
    return 0;
}
