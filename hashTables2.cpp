#include <iostream>
#include <vector>
#include <string>
#include <tuple>

template<typename T>
struct hashObject{
    int index;
    T value;
    bool isNone;
    hashObject<T>():
        index{},
        value{},
        isNone{}
    {}

    hashObject<T>(int idx, T val, bool none):
        index{idx},
        value{val},
        isNone{none}
    {}
};

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
            myVectors(10, std::vector(1, hashObject<T>{}))
        {}

        explicit hashTable<T>(int size):
            tableSize{size},
            myVectors(size, std::vector(1, hashObject<T>{}))
        {}

        // funcstion(s)
        T getItem(std::string key);
        void setItem(std::string key, T value);
        void deleteItem(std::string key);
};

// hashTable function(s) implementations
template<typename T> __attribute__((always_inline)) inline
int hashTable<T>::getHash(std::string key) {
    int h = 0;
    for(char c : key) {
        h += (int)c;
    }
    return h % hashTable<T>::tableSize;
}

// template<typename T>
// T hashTable<T>::getItem(std::string key) {
//     using ht = hashTable<T>;
//     int arrIndex = ht::getHash(key);
    
//     for(std::vector val : ht::myVectors[arrIndex]){
//         if (std::get<0>(val) == key) {
//             return std::get<1>(val);
//         }
//     }

//     return T{};
// }

template<typename T>
void hashTable<T>::setItem(std::string key, T value) {
    using ht = hashTable<T>;
    int h = ht::getHash(key);
    // bool isFound = false;

    // for (int idx = 1; idx <= ht::myVectors[h].size(); idx++) {
    //     if (((ht::myVectors[h][idx]).size() == 2) && (std::get<0>(ht::myVectors[h][idx]) == key)) {
    //         ht::myVectors[h][idx] = std::make_tuple(idx, value);
    //         isFound = true;
    //     }
    // }

    // if (!isFound) {
    //     (ht::myVectors[h]).push_back(std::make_tuple(ht::myVectors[h].size(), value));
    // }
}

// template<typename T>
// void hashTable<T>::deleteItem(std:: string key) {
//     using ht = hashTable<T>;
//     int h = ht::getHash(key);
//     for (int idx = 1; ht::myVectors[h].size(); idx++) {
//         if (std::get<0>(ht::myVectors[h][idx]) == key) {
//             std::cout << "Deleting index " << idx << std::endl; 
//             ht::myVectors[h][idx] = std::make_tuple(idx, T{});
//         }
//     }
// }

int main() {
    hashTable<int> myTab{};

    std::cout << "setting values to the table" << std::endl;
    myTab.setItem("march 6", 310);
    // myTab.setItem("march 7", 310);
    // myTab.setItem("march 8", 310);
    // myTab.setItem("march 11", 310);

    return 0;
}