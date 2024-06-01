#include <iostream>
#include <string>
#include <bits/stdc++.h>

template <typename T>
class Node {

	public:
	// members
	T data;
	bool isNone;
	Node* nextNode;

	// constructor(s)
	Node(T d, Node* n = nullptr) 
	{
		this->data = d;
		this->nextNode = n;
		this->isNone = false;
	};

	Node(){
		this->isNone = true;
		this->nextNode = nullptr;
	};

	// destructor
	~Node(){};
};

template <typename T>
class linkedList {

	public:
	// members
	Node<T> head;
	
	// constructor
	linkedList() {
		this->head = Node<T>();
	};

	// print linked list
	void print() {
		if ((head.isNone)) {
			std::cout << "Linked list is empty" << std::endl;
			return;
		}

		Node<T> itr = head;

		while(itr.isNone) {
			if (itr.nextNode != nullptr) {
				std::cout << itr.data << " --> " << std::endl;
			} else {
				std:: cout << itr.data << std::endl;
			}

			itr = *(itr.nextNode);
		}
	}

	// int getLength
};

int main() {
	
	std::cout << "Hello World" << std::endl;

	linkedList<std::string> ll = linkedList<std::string>();
	ll.print();

	return 0;
}
