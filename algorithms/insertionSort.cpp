#include <iostream>
#include <vector>
#include <string>

// function(s) prototypes
void insertionSort(std::vector<int>& elems);
void printVector(std::vector<int>& elems);


// 
// main function
//
int main() {
  std::vector<int> elems { 11, 9, 29, 7, 2, 15, 28 };
  insertionSort(elems);
  printVector(elems);

  std::vector<std::vector<int>> test {
    { 3, 7, 9, 11 },
    { 25, 22, 21, 10 },
    { 29, 15, 28 },
    {},
    { 6 }
  };

  for (std::vector<int> t : test) {
    insertionSort(t);
    printVector(t);
  }

  return 0;
}
//
// main function
//



// function(s) definition
void insertionSort(std::vector<int>& elems) {
  for (int i; i < elems.size(); i++) {
    int anchor = elems[i];
    int j = i - 1;
    while (j >= 0 && anchor < elems[j]){
      elems[j + 1] = elems[j];
      j = j - 1;
      elems[j + 1] = anchor;
    }
  }
}

void printVector(std::vector<int>& elems) {
  if (elems.size() <= 0) {
    std::cout << "{ }" << std::endl;
    return;
  }

  std::cout << "{ ";
  for (auto iter = elems.begin(); iter != elems.end(); iter++) {
    if (iter == elems.end() - 1) {
      std::cout << *iter << " }" << std::endl;
      return;
    }

    std::cout << *iter << ", ";
  }
}