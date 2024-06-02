#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Node {

	public:
	// members
	T data;
	Node<T>* pNextNode;
	bool isNone;

	// constructor(s)
	Node<T>():
		data{},
		pNextNode{nullptr},
		isNone{true}
	{}; 

	Node<T>(T d, Node* n):
		data{d},
		pNextNode{n},
		isNone{false}	
	{}
};

template <typename T>
class LinkedList {

	public:
	// members
	Node<T>* pHead;
	
	// constructor
	LinkedList():
		pHead{ new Node<T>{} }
	{};

	// destructor
	~LinkedList() {
		std::cout << "Linked List Destructor Called" << std::endl;
		Node<T>* nextToDelete = this->pHead;
		while(true) {
			std::cout << "deleting pointer to: " << nextToDelete->data << std::endl;
			if (nextToDelete->pNextNode != nullptr) {
				Node<T>* temp = nextToDelete->pNextNode;
				delete nextToDelete;
				nextToDelete = temp;
			} else {
				delete nextToDelete;
				break;
			}
		}
		std::cout << "Linked List Destructor Ended" << std::endl;
	}

	// print linked list
	void print() {
		if ((this->pHead)->isNone) {
			std::cout << "Linked list is empty" << std::endl;
			return;
		}

		Node<T>* itrObj = this->pHead;

		while(true) {
			if (itrObj->pNextNode != nullptr) {
				std::cout << itrObj->data << " --> ";
				itrObj = itrObj->pNextNode;
			} else {
				std:: cout << itrObj->data << std::endl;
				break;
			}
		}
	}

	// getLength
	int getLength(){
		int count = 0;
		Node<T>* itrObj = this->pHead;

		while (itrObj->pNextNode != nullptr) {
			count++;
			itrObj = itrObj->pNextNode;
		}

		return count;
	}

	// insert at beginning
	void insertAtBeginning(T data){
		Node<T>* node = new Node<T>(data, this->pHead);
		this->pHead = node;
	}

	// void insert at end
	void insertAtEnd(T data) {
		if ((this->pHead)->isNone) {
			this->pHead = new Node<T>(data, nullptr);
			return;
		}

		// create a new node
		Node<T>* newNode  = new Node<T>(data, nullptr);
		
		// create an iterator
		Node<T>* itrObj = this->pHead;

		while (itrObj->pNextNode != nullptr) {
			itrObj = itrObj->pNextNode;
		}	

		// assign address of new node into the last head.nextNode pointer
		itrObj->pNextNode = newNode;
	}

	// insert at
	void insertAt(int index, T data) {
		if (index < 0 || index > this->getLength()) {
			std::cout << "error: invalid index" << std::endl;
			return;
		} 

		if (index == 0) {
			this->insertAtBeginning(data);
			return;
		}

		int count = 0;
		Node<T>* itrObj = this->pHead;
		while(true) {
			if (count == index - 1) {
				Node<T>* n = new Node<T>(data, itrObj->pNextNode);
				itrObj->pNextNode = n;
				break;
			}

			itrObj = itrObj->pNextNode;
			count++;
		}
	};

	// remove at
	void removeAt(int index) {
		if (index < 0 || index >= this->getLength()) {
			std::cout << "error invalid index" << std::endl;
			return;
		}

		if (index == 0) {
			delete this->pHead;
			this->pHead = (this->pHead)->pNextNode;
			return;
		}

		int count = 0;
		Node<T>* itrObj = this->pHead;
		while (true) {
			if (count == index - 1) {
				Node<T>* nodeToDelete = itrObj->pNextNode; 
				itrObj->pNextNode = (itrObj->pNextNode)->pNextNode;
				delete nodeToDelete;
				break;
			}

			itrObj = itrObj->pNextNode;
			count++;
		}
	}

	// insert values
	void insertValues(std::vector<T>dataList) {
		this->pHead = new Node<T>();
		for (T d : dataList) {
			this->insertAtEnd(d);
		}
	}
};

// main function
int main() {
	
	// adding vector to linked list
	std::cout << std::endl;
	std::cout << "Adding a vector of strings to linked list" << std::endl;

	LinkedList<std::string> ll = LinkedList<std::string>();
	std::vector<std::string> myValues{ "banana", "mango", "grapes", "orange" };
	ll.insertValues(myValues);
	ll.print();

	// insert apple at beginning
	std::cout << std::endl;
	std::cout << "Insert apple at the beginning of the linked list" << std::endl;
	ll.insertAtBeginning("apple");
	ll.print();

	// insert coconut at [2]
	std::cout << std::endl;
	std::cout << "Insert coconut at index 2" << std::endl;
	ll.insertAt(2, "coconut");
	ll.print();

	// insert peaches at end
	std::cout << std::endl;
	std::cout << "Insert peaches at the end of the linked list" << std::endl;
	ll.insertAtEnd("peaches");
	ll.print();

	// remove value at [3]
	std::cout << std::endl;
	std::cout << "Remove value at index 3" << std::endl;
	ll.removeAt(3);
	ll.print();

	return 0;
}
