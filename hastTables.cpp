#include <iostream>
#include <string>
#include <vector>

// classes

// hash table class
template <typename T>
class HashTable{
    private:
    // get hash
        int getHash(std::string key) {
            int hash = 0;
            for (char c: key) {
                hash += (int)c;
            }

            return hash % this->tSize;
        }

    public:
        // members
        int tSize;
        std::vector<T> hTable;

        // constructor(s)
        explicit HashTable<T>():
            tSize{100},
            hTable(100, 0)
        {}

        explicit HashTable<T>(int size):
            tSize{size},
            hTable(size, T{})
        {}

        // get value
        T getValue(std::string key) {
            int idx = this->getHash(key);
            return this->hTable[idx];
        }

        // set value
        void setValue(std::string key, T value) {
            int idx = this->getHash(key);
            this->hTable[idx] = value;
        }

        // delete value
        void deleteValue(std::string key) {
            int idx = this->getHash(key);
            this->hTable[idx] = T{};
        }
    
};

int main() {
    HashTable<int> myHashTableVar{10};
}
