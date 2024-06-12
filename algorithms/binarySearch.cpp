#include <iostream>
#include <string>
#include <vector>

int binarySearch(std::vector<int>& list, int find);

int main() {

    std::vector<int> numList = { 12, 15, 17, 19, 21, 24, 45, 67 };
    int findNum = 21;

    int index = binarySearch(numList, findNum);

    std::cout << "The number " << findNum << " is on index " << index << "." << std::endl;

    return 0;
}

int binarySearch(std::vector<int>& list, int find){
    int left = 0;
    int right = list.size() - 1;
    int middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;
        int midNum = list[middle];

        if (midNum == find) {
            return middle;
        }

        if (midNum < find) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}