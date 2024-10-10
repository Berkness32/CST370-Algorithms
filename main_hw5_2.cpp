// Title: Homework 5-2
// Abstract: Creating a hash table
// Name: Aaron Berkness
// Date: 10/8/24

#include <iostream>
#include <vector>

using namespace std;

// Check if number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Find next prime number
int nextPrime(int n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

// ----------------------------------------------------------------------
// Hash table class using linear probing
class HashTable {
    vector<int> table;
    int tableSize;
    int numElements;

public:
    HashTable(int size) : tableSize(size), numElements(0) {
        table.resize(size, -1);  // Initialize empty (-1)
    }

    // Determine index
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Insert a key using linear probing
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % tableSize;
            if (index == originalIndex) {
                cout << "Table is full, cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        numElements++;

        // Check load factor and rehash if needed
        if (double(numElements) / tableSize > 0.5) {
            rehash();
        }
    }

    // Function to rehash when load factor exceeds 0.5
    void rehash() {
//        cout << "Rehashing...\n";
        int newSize = nextPrime(tableSize * 2);  // Next prime number after doubling the table size
        vector<int> oldTable = table;

        tableSize = newSize;
        table.clear();
        table.resize(tableSize, -1);
        numElements = 0;

        for (int key : oldTable) {
            if (key != -1) {
                insert(key);
            }
        }
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << key << " Found" << endl;
                return true;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex) break;
        }
        cout << key << " Not found" << endl;
        return false;
    }

    // Display status of a specific index
    void displayStatus(int index) {
        if (table[index] == -1) {
            cout << "Empty" << endl;
        } else {
            cout << table[index] << endl;
        }
    }

    // Display the current size of the hash table
    void tableSizeDisplay() {
        cout << tableSize << endl;
    }
};
// ----------------------------------------------------------------------

int main() {
    int size, commandCount, value, index;
    cin >> size;
    HashTable hashTable(size);

    cin >> commandCount; 

    string command;
    for (int i = 0; i < commandCount; i++) {
        cin >> command;
        if (command == "insert") {
            cin >> value;
            hashTable.insert(value);
        } else if (command == "displayStatus") {
            cin >> index;
            hashTable.displayStatus(index);
        } else if (command == "tableSize") {
            hashTable.tableSizeDisplay();
        } else if (command == "search") {
            cin >> value;
            hashTable.search(value);
        }
    }

    return 0;
}

