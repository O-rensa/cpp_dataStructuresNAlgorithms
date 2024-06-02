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
				std::cout << itrObj->data << " --> " << std::endl;
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
			break;
		}

		return count;
	}

	// insert at beginning
	void insertAtBeginning(T data){
		Node<T> node = new Node<T>(data, this->pHead);
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
	void inserAt(int index, T data) {
		if (index < 0 || index > this->getLength()) {
			std::cout << "error: invalid index" << std::endl;
			return;
		} 

		if (index == 0) {
			this->insertAtBeginning();
			return;
		}

		int count = 0;
		Node<T>* itrObj = this->pHead;
		while(true) {
			if (count == index - 1) {
				Node<T>* n = new Node<T>(data, &itrObj->pNextNode);
				itrObj->pNextNode = n;
				break;
			}

			itrObj = itrObj->nextNode;
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
			delete this->head;
			this->head = (this->head)->nextNode;
			return;
		}

		int count = 0;
		Node<T>* itrObj = this->head;
		while (true) {
			if (count == index - 1) {
				itrObj = (itrObj->nextNode)->nextNode;
				break;
			}

			itrObj = itrObj->nextNode;
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
	
	std::cout << "Hello World" << std::endl;

	LinkedList<std::string> ll = LinkedList<std::string>();
	std::vector<std::string> myValues{ "banana", "mango", "grapes", "orange" };
	ll.insertValues(myValues);
	ll.print();

	return 0;
}
