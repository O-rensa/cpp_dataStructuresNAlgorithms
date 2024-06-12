#include <iostream>
#include <vector>
#include <string>

template<typename T>
class BinarySearchTree {
    private:
        T data;
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;
    public: 
        // constructor(s)
        explicit BinarySearchTree<T>(T _data):
            data{_data},
            left{nullptr},
            right{nullptr}
        {}

        // destructor
        ~BinarySearchTree<T>() {
            std::cout << std::endl << "initializing destructor for data: " << this->data << std::endl;

            delete this->left;
            this->left = nullptr;

            delete this->right;
            this->right = nullptr;

            std::cout << "destructor successful for data: " << this->data << std::endl;
        }

        // method(s)
        void addChild(T data);
        bool isExist(T data);
        std::vector<T> inOrderTraversal();
};

// class method(s) definition
// // BinarySearchTree

template<typename T> 
void BinarySearchTree<T>::addChild(T data) {
    if (this->data == data) {
        return;
    }

    if (data < this->data) {
        if (this->left != nullptr) {
            this->left->addChild(data);
        } else {
            this->left = new BinarySearchTree(data);
            std::cout << "successfully added " << data << std::endl;
        }
    } else {
        if (this->right != nullptr) {
            this->right->addChild(data);
        } else {
            this->right = new BinarySearchTree(data);
            std::cout << "successfully added " << data << std::endl;
        }
    }
}

template<typename T>
bool BinarySearchTree<T>::isExist(T data) {
    if (this->data == data) {
        return true;
    }

    if (data < this->data) {
        if (this->left != nullptr) {
            return this->left->isExist(data);
        } else {
            return false;
        }
    } else {
        if (this->right != nullptr) {
            return this->right->isExist(data);
        } else {
            return false;
        }
    }
}

template <typename T> 
std::vector<T> BinarySearchTree<T>::inOrderTraversal() {
    std::vector<T> elements = {};

    if (this->left != nullptr) {
        std::vector<T> temp = this->left->inOrderTraversal();
        elements.insert(elements.end(), temp.begin(), temp.end());
    }

    elements.push_back(this->data);

    if (this->right != nullptr) {
        std::vector<T> temp = this->right->inOrderTraversal();
        elements.insert(elements.end(), temp.begin(), temp.end());
    }

    return elements;
}

template<typename T>
BinarySearchTree<T>* buildTree(std::vector<T>& values);

int main() {
    std::cout << "Creating a tree of countries" << std::endl;
    std::vector<std::string> countries = { "India", "Pakistan", "Germany", "USA", "China", "India", "UK", "USA" };
    BinarySearchTree<std::string>* countryTree = buildTree(countries);

    std::cout << std::endl << "Is UK in the List? " << countryTree->isExist("UK") << std::endl; 
    std::cout << std::endl << "Is Sweden in the List? " << countryTree->isExist("Sweden") << std::endl;
    std::cout << std::endl << "Is China in the List? " << countryTree->isExist("China") << std::endl;
    std::cout << std::endl << "Is Japan in the List? " << countryTree->isExist("Japan") << std::endl;
    
    std::cout << std::endl << "Creating a tree of numbers" << std::endl;
    std::vector<int> numbers = { 17, 4, 1, 20, 9, 23, 18, 34 };
    BinarySearchTree<int>* numberTree = buildTree(numbers);
    std::cout << "In order traversal gives sorted list of the numbers" << std::endl;

    std::vector<int> sortedNumbers = numberTree->inOrderTraversal();

    for (int n : sortedNumbers) {
        std::cout << n << " ";
    }

    delete countryTree;
    countryTree = nullptr;
    delete numberTree;
    numberTree = nullptr;
    return 0;
}

template<typename T>
BinarySearchTree<T>* buildTree(std::vector<T>& values) {
    if (values.empty()) {
        return nullptr;
    }

    T rootData = *(values.begin());

    BinarySearchTree<T>* root = new BinarySearchTree<T>(rootData);

    for (T val : values) {
        root->addChild(val);
    }

    return root;
}