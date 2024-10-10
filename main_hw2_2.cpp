// Title: Homework 2-2
// Abstract: Checking if a string is a palindrome
// Name: Aaron Berkness
// Date: 9/10/24

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word;
    stack<char> palindrome;
    int odd, half;
    
//    cout << "What word do you want to test? ";
    cin >> word;
    
    odd = word.length() % 2;
    if (odd == 1) {
        half = word.length() / 2;
//        cout << "Half is " << half << endl;
    } else {
        half = word.length() / 2;
        half--;
//        cout << "Half is " << half << endl;
    }
    palindrome.push(0);
    
    for (int i = 0; i < word.length(); i ++) {
        if (isalpha(word[i])) {
            if (palindrome.top() == word[i]) {
                palindrome.pop();
//                cout << "Popping: " << word[i] << endl;
            } else {
                palindrome.push(tolower(word[i]));
//                cout << "Pushing: " << tolower(word[i]) << endl;
            }
            
            if (odd == 1 && i == half) {
//                cout << "Popping: " << word[i] << endl;
                palindrome.pop();
            }
        }
        
    }
    
    if (palindrome.top() == 0) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
}
