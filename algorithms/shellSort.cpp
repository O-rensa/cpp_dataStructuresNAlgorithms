#include <iostream>
#include <vector>
#include <string>

// function(s) prototypes
void shellSort(std::vector<int>& input);
void printVector(std::vector<int>& input);

//
// MAIN FUNCTION
//
int main() {
  std::vector<std::vector<int>> tests{
    std::vector<int>{ 89, 78, 61,89, 78, 61, 53, 23, 21, 17, 12, 9, 7, 6, 2, 1 },
    std::vector<int>{ 9, 8, 5 , 1 },
    std::vector<int>{ 234, 3, 1, 56, 34, 12, 9 , 12, 1300 }
  };

  for (auto elem : tests) {
    shellSort(elem);
    printVector(elem);
  }

  return 0;
}
//
// MAIN FUNCTION
//

// function(s) definition
void shellSort(std::vector<int>& input){
  int gap = (input.size() / 2);

  while (gap > 0) {
    for (int i = gap; i < input.size(); i++) {
      auto anchor = input[i];
      int j = i;
      while ((j >= gap) && input[j - gap] > anchor) {
        input[j] = input[j - gap];
        j -= gap;
        input[j] = anchor;
      } 
    }
    gap = gap / 2;
  }
}

void printVector(std::vector<int>& input) {
  std::cout << "{ ";
  for (auto i = input.begin(); i != input.end(); i++) {
    if (i == input.end() - 1) {
      std::cout << *i << ", }" << std::endl;
    } else {
      std::cout << *i << ", ";
    }
  }
}