#include <iostream>
#include <vector>
#include <string>

template<typename T>
void bubbleSort(std::vector<T>& elements);

template<typename T>
void printVectors(std::vector<T>& elements);

int main() {
    std::vector<int> v1 = { 5,9,2,1,67,34,88,34 };

    std::cout << "sorting array of numbers: ";
    printVectors(v1);

    bubbleSort(v1);

    std::cout << "sorted array of numbers: ";
    printVectors(v1);

    return 0;
}

template<typename T>
void bubbleSort(std::vector<T>& elements) {
    int size = elements.size();
    for (int i = 0; size > 0; i++) {
        bool isSorted = true;
        for (int j = 0; (size - i) > j; j++) {
            if (elements[j] > elements[j + 1]) {
                T temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
                isSorted = false;
            }
        }

        if (isSorted) {
            break;
        }
    }
}

template<typename T> inline
void printVectors(std::vector<T>& elements) {
    std::cout << "{ " ;
    for (T e : elements) {
        std::cout << e << ", ";
    }
    std::cout << " }" << std::endl;
}