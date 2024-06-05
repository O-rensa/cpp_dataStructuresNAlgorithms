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
    HashTable<int> myHashTableVar{};

    // set value
    std::cout << "Set Values" << std::endl;
    myHashTableVar.setValue("march 6", 310.0);
    myHashTableVar.setValue("march 7", 340.0);
    myHashTableVar.setValue("march 8", 380.0);
    myHashTableVar.setValue("march 9", 297.0);
    myHashTableVar.setValue("march 10", 323.0);

    // display values
    std::cout << std::endl << "Display Values" << std::endl;
    std::cout << "March 6: " << myHashTableVar.getValue("march 6") << std::endl;
    std::cout << "March 7: " << myHashTableVar.getValue("march 7") << std::endl;
    std::cout << "March 8: " << myHashTableVar.getValue("march 8") << std::endl;
    std::cout << "March 9: " << myHashTableVar.getValue("march 9") << std::endl;
    std::cout << "March 10: " << myHashTableVar.getValue("march 10") << std::endl;
    
    // delete value on march 8
    std::cout << std::endl << "Delete March 8" << std::endl;
    myHashTableVar.deleteValue("march 8");

    std::cout << std::endl << "Display Values" << std::endl;
    std::cout << "March 6: " << myHashTableVar.getValue("march 6") << std::endl;
    std::cout << "March 7: " << myHashTableVar.getValue("march 7") << std::endl;
    std::cout << "March 8: " << myHashTableVar.getValue("march 8") << std::endl;
    std::cout << "March 9: " << myHashTableVar.getValue("march 9") << std::endl;
    std::cout << "March 10: " << myHashTableVar.getValue("march 10") << std::endl;

}
