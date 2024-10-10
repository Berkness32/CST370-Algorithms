// Title: Homework 4-1
// Abstract: Placing negatives at the front
// Name: Aaron Berkness
// Date: 10/1/24

#include <iostream>
using namespace std;

int main() {
    int loopCount;
    cin >> loopCount;
    
    int array[loopCount];
    int array2[loopCount];
    for (int i = 0; i < loopCount; i++) {
        int temp;
        cin >> temp;
        array[i] = temp;
        array2[i] = temp;
    }
    
    // First Approach
//    cout << "First Approach" << endl;
    int i = 0;
    int j = loopCount - 1;
    while (i < j) {
        if (array[i] > 0 && array[j] < 0) {
//            cout << "Swapping " << array[i] << " and " << array[j] << endl;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        
        if (array[i] < 0) {
            i++;
        } else if (array[j] > 0) {
            j--;
        }
    }
    
    for (int i = 0; i < loopCount; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
    
    // Second Approach
//    cout << "Second Approach" << endl;
    i = 0;
    j = 0;
    while (j < loopCount) {
//        cout << "i at " << array2[i] << " and j at " << array2[j] << endl;
        
        if (array2[i] > 0 && array2[j] < 0) {
//            cout << "Swapping " << array2[i] << " and " << array2[j] << endl;
            int temp = array2[i];
            array2[i] = array2[j];
            array2[j] = temp;
            
            i++;
            j++;
        } else {
            j++;
        }
        
        if (array2[i] < 0) {
            i++;
        }
    }
    
    for (int i = 0; i < loopCount; i++) {
        cout << array2[i] << " ";
    }
    cout << "\n";
}
