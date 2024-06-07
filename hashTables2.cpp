#include <iostream>
#include <vector>
#include <string>
#include <tuple>

// struct(s)
template<typename T>
struct hashObject{
    std::string key;
    T value;
    bool isNone;

    explicit hashObject<T>():
        key{},
        value{T{}},
        isNone{true}
    {}

    explicit hashObject<T>(std::string key, T val, bool none):
        key{key},
        value{val},
        isNone{none}
    {}
};

// class(es)
template<typename T>
class hashTable{
    private: 
        // member(s)
        int tableSize;
        std::vector<std::vector<hashObject<T>>> myVectors;
        // function(s)
        int getHash(std::string key);

    public: 
        // constructor(s)
        explicit hashTable<T>():
            tableSize{10},
            myVectors(10, std::vector(1, hashObject<T>()))
        {}

        explicit hashTable<T>(int size):
            tableSize{size},
            myVectors(size, std::vector(1, hashObject<T>()))
        {}

        // funcstion(s)
        T getItem(std::string key);
        void setItem(std::string key, T value);
        void deleteItem(std::string key);
};

// class function(s) definitions
// // hashTable
template<typename T> __attribute__((always_inline)) inline
int hashTable<T>::getHash(std::string key) {
    int h = 0;
    for(char c : key) {
        h += (int)c;
    }
    return h % hashTable<T>::tableSize;
}

template<typename T>
T hashTable<T>::getItem(std::string key) {
    using ht = hashTable<T>;
    int idx = ht::getHash(key);
    
    for(hashObject<T> obj : ht::myVectors[idx]){
        if (obj.key == key) {
            return obj.value;
        }
    }
    
    return T{};
}

template<typename T>
void hashTable<T>::setItem(std::string key, T value) {
    using ht = hashTable<T>;
    int idx = ht::getHash(key);
    bool isFound = false;

    for (hashObject<T> obj : ht::myVectors[idx]) {
        if ((!obj.isNone) && (obj.key == key)) {
            obj.value = value;
            isFound = true;
        }
    }

    if (!isFound) {
        (ht::myVectors[idx]).push_back(hashObject<T>(key, value, false));
    }

    std::cout << std::endl << "{ key: " << key << ",value: " << value << "} is set on index " << idx << std::endl;
}

template<typename T>
void hashTable<T>::deleteItem(std:: string key) {
    using ht = hashTable<T>;
    int idx = ht::getHash(key);
    auto iter = ht::myVectors[idx].begin();
    for (hashObject obj: ht::myVectors[idx]) {
        if (obj.key == key) {
            break;
        }
        iter++;
    }

    if (iter != ht::myVectors[idx].end()) {
        std::cout << "Deleting object with key " << key << std::endl;
        (ht::myVectors[idx]).erase(iter);
        std::cout << "Successfully deleted object with key " << key << std::endl; 
    }
    
}

int main() {
    hashTable<int> myTab{};

    std::cout << std::endl << "setting values to the table" << std::endl;
    myTab.setItem("march 6", 310);
    myTab.setItem("march 7", 420);
    myTab.setItem("march 8", 67);
    myTab.setItem("march 11", 250);
    myTab.setItem("march 17", 365);

    std::cout << "as per observation, both march 6 and march 17 are on the same index" << std::endl;
    std::cout << "but both are still available and none of them is deleted" << std::endl;

    std::cout << "showing value for march 6: { key: march 6, value: " << myTab.getItem("march 6") << "}" << std::endl; 
    std::cout << "showing value for march 17: { key: march 17, value: " << myTab.getItem("march 17") << "}" << std::endl; 
    
    std::cout << std::endl << "deleting march 8 value" << std::endl;
    myTab.deleteItem("march 8");
    std::cout << "showing value for march 8: { key: march 8, value: " << myTab.getItem("march 8") << "}" << std::endl; 
    
    return 0;
}