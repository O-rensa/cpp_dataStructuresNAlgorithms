#include <iostream>
#include <vector>
#include <string>
#include "bits/stdc++.h"

// function(s) prototype
std::vector<int> mergeSort(std::vector<int> input);
std::vector<int> mergeTwoSortedList(std::vector<int>& left, std::vector<int>& right);
std::vector<int> slicing(std::vector<int>& vect, int x, int y);
void printVec(std::vector<int>& vect);
//
// main function
// 
int main() {
  std::vector<int> myVec{10,3,15,7,8,23,98,29};

  std::vector<int> sortedMyVec = mergeSort(myVec);

  std::cout << sortedMyVec.size() << std::endl;

  printVec(sortedMyVec);

  return 0;
}
// 
// main function
//

// function(s) definition
std::vector<int> mergeSort(std::vector<int> input){
  if (input.size() <= 1) {
    return input;
  };

  int mid = input.size() / 2;

  std::vector<int> left;
  std::vector<int> right;

  if (input.size() == 2) {
    left = std::vector<int>(input[0]);
    right = std::vector<int>(input[1]);
  } else {
    left = slicing(input, 0, mid);
    right = slicing(input, mid, input.size() - 1);
  }

  left = mergeSort(left);
  right = mergeSort(right);


  return mergeTwoSortedList(left, right);
  return input;
};

std::vector<int> mergeTwoSortedList(std::vector<int>& a, std::vector<int>& b){
  std::vector<int> sortedList{};

  int lenA = a.size();
  int lenB = b.size();

  int i = 0;
  int j = 0;

  while ((i < lenA) && (j < lenB)) {
    if (a[i] <= b[j]) {
      sortedList.push_back(a[i++]);
    } else {
      sortedList.push_back(b[j++]);
    }
  }

  while (i < lenA) {
    sortedList.push_back(a[i++]);
  }

  while (j < lenB) {
    sortedList.push_back(b[j++]);
  }

  return sortedList;
}

__attribute__((always_inline)) inline
std::vector<int> slicing(std::vector<int>& vect, int x, int y){
  auto start = vect.begin() + x;
  auto end = vect.begin() + y + 1;

  std::vector<int> result(y - x + 1);
  std::copy(start, end, result.begin());
  return result;
};

__attribute__((always_inline)) inline
void printVec(std::vector<int>& vect) {
  std::cout << "{ ";
  for (auto iter = vect.begin(); iter != vect.end(); iter++) {
    if (iter != vect.end() - 1) {
      std:: cout << *iter << ", ";
    } else {
      std::cout << *iter << " }" << std::endl;
    }
  }
};