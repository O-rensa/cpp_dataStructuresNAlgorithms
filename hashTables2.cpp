#include <iostream>
#include <vector>
#include <string>
#include <tuple>

template<typename T>
class hashTable{
    private: 
        // member(s)
        int tableSize;
        std::vector<std::vector<std::tuple<int, T>>> myVectors;
        // function(s)
        int getHash(std::string key);

    public: 
        // constructor(s)
        explicit hashTable<T>():
            tableSize{10},
            myVectors(10, std::vector(0, std::tuple<int, T>::make_tuple({}, {})))
        {}

        explicit hashTable<T>(int size):
            tableSize{size},
            myVectors(size, std::vector(0, std::tuple<int, T>::make_tuple({}, {})))
        {}

        // funcstion(s)
        // // get item
        T getItem(std::string key);
};

// hashTable function(s) implementations
template<typename T>
int hashTable<T>::getHash(std::string key) {
    int h = 0;
    for(char c : key) {
        h += (int)c;
    }
    return h % hashTable<T>::tableSize;
}

template<typename T>
T hashTable<T>::getItem(std::string key) {
    using hashTable<T> = ht;
    int arrIndex = ht::getHash(key);
    for(std::vector val : ht::myVectors[arrIndex]){

    }
}

int main() {

    return 0;
}