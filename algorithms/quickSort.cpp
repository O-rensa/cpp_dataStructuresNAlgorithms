#include <iostream>
#include <vector>
#include <string>

// function(s) prototypes
void swap(int a, int b, std::vector<int>& elems);
void quickSort(std::vector<int>& elems, int start, int end);
int partition(std::vector<int>&, int start, int end);
void printVector(std::vector<int>& elems);

// main function
int main() {
  std::vector<int> myElems{ 11, 2, 29, 7, 2, 15, 28 };

  quickSort(myElems, 0, myElems.size() - 1);

  printVector(myElems);

  std::vector<std::vector<int>> test{
    { 11, 9, 29, 7, 2, 15, 28 },
    { 3, 7, 9, 11 },
    { 25, 22, 21, 10 },
    { 29, 15, 28 },
    {},
    { 6 }
  };

  for (int i = 0; i < test.size(); i++) {
    quickSort(test[i], 0, test[i].size() - 1);
    printVector(test[i]);
  }

  return 0;
}

// function(s) definition
void swap(int a, int b, std::vector<int>& elems) {
  if (a != b) {
    int temp = elems[a];
    elems[a] = elems[b];
    elems[b] = temp;
  }
}

void quickSort(std::vector<int>& elems, int start, int end) {
  if (start < end) {
    int pi = partition(elems, start, end);
    quickSort(elems, start, pi - 1);
    quickSort(elems, pi + 1, end);
  }
}

int partition(std::vector<int>& elems, int start, int end) {
  int pivotIdx = start;
  int pivot = elems[pivotIdx];

  while(start < end) {
    while (start < elems.size() && elems[start] <= pivot) {
      start += 1;
    }

    while (elems[end] > pivot){
      end -= 1;
    }

    if (start < end) {
      swap(start, end, elems);
    }
    
  }
  
  swap(pivotIdx, end, elems);

  return end;
}

void printVector(std::vector<int>& elems) {
  std::cout << "{ ";
  for (auto iter = elems.begin(); iter != elems.end(); iter++) {
    if (iter == elems.end() - 1) {
      std::cout << *iter << " }" << std::endl;
      return;
    }

    std::cout << *iter << ", ";
  }
}





