#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    list<int>* table;
    int size;
public:
    HashTable(int size) {
        this->size = size;
        table = new list<int>[size];
    }

    void insert(int key) {
        int index = key % size;
        table[index].push_back(key);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                cout << *it << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    int arr[] = { 86, 90, 27, 29, 38, 30, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    HashTable ht(7);
    for (int i = 0; i < n; i++) {
        ht.insert(arr[i]);
    }
    ht.print();
    return 0;
}