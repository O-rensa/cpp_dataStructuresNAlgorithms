#include <iostream>
#include <string>
#include <vector>

// function protypes
int getHash(std::string key);

// classes

// hash table class
template <typename T>
class HashTable{
    
    public:
    // members
        int tSize;
        std::vector<T> hTable;

    // constructor(s)
    HasTable<T>() {
        tSize{100},
        hTable(100, 0)    
    }

    HashTable<T>(int size):
        tSize{size},
        hTable(size, 0)
    {}  
};

int main() {
    
}

// functions
int getHash(std::string key) {
    int hash{0};

    for(char c: key) {
        hash += (int)c;
    }

    return hash % 100;
}
