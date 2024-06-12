#include <iostream>
#include <vector>
#include <string>

class BinarySearchTreeNode {
    private:
        int data;
        BinarySearchTreeNode* left;
        BinarySearchTreeNode* right;
    public:
        // constructor(s)
        explicit BinarySearchTreeNode():
            data{},
            left{nullptr},
            right{nullptr}
            {}

        explicit BinarySearchTreeNode(int _data):
            data{_data},
            left{nullptr},
            right{nullptr}
            {}

        ~BinarySearchTreeNode(){
            delete this->left;
            this->left = nullptr;
            delete this->right;
            this->right = nullptr;
        }
        
        // method(s)
        void addChild(int value);
        bool isExist(int value);
        std::vector<int> inOrderTraversal();
        BinarySearchTreeNode* deleteValue(int value);
        int findMax();
        int findMin();
};

// class method(s) definition
void BinarySearchTreeNode::addChild(int value) {
    if (this->data == value) {
        return;
    }

    if (value < this->data) {
        if (this->left != nullptr) {
            this->left->addChild(value);
        } else {
            this->left = new BinarySearchTreeNode(value);
        }
    } else {
        if (this->right != nullptr) {
            this->right->addChild(value);
        } else {
            this->right = new BinarySearchTreeNode(value);
        }
    }
}

bool BinarySearchTreeNode::isExist(int value) {
    if (this->data == value) {
        return true;
    }

    if (value < this->data) {
        if (this->left != nullptr) {
            return this->left->isExist(value);
        } 

        return false;
    } else {
        if (this->right != nullptr) {
            return this->right->isExist(value);
        }

        return false;
    }
}

std::vector<int> BinarySearchTreeNode::inOrderTraversal() {
    std::vector<int> elements = {};

    if (this->left != nullptr) {
        std::vector<int> t = this->left->inOrderTraversal();
        elements.insert(elements.end(), t.begin(), t.end());
    }

    elements.push_back(this->data);

    if (this->right != nullptr) {
        std::vector<int> t = this->right->inOrderTraversal();
        elements.insert(elements.end(), t.begin(), t.end());
    }

    return elements;
}

BinarySearchTreeNode* BinarySearchTreeNode::deleteValue(int value){
    if (value < this->data) {
        if (this->left != nullptr) {
            this->left = this->left->deleteValue(value);
        }
    } else if (value > this->data) {
        if (this->right != nullptr) {
        this->right = this->right->deleteValue(value);
        }
    } else {
        if (this->right == nullptr && this->left == nullptr) {
            return nullptr;
        } else if (this->left == nullptr) {
            return this->right;
        } else if (this->right == nullptr) {
            return this->left;
        }

        int minValue = this->findMin();
        this->data = minValue;
        this->right = this->right->deleteValue(minValue);
    }

    return this;
}

int BinarySearchTreeNode::findMax() {
    if (this->right == nullptr) {
        return this->data;
    }

    return this->right->findMax();
}

int BinarySearchTreeNode::findMin() {
    if (this->left == nullptr) {
        return this->data;
    }

    return this->left->findMin();
}

// function(s) prototype
BinarySearchTreeNode* buildTree(std::vector<int>& values);

int main() {
    std::vector<int> values = { 17, 4, 1, 20, 9, 23, 18, 34 };
    BinarySearchTreeNode* numbersTree = buildTree(values);

    std::cout << std::endl << "The maximum value of the tree is " << numbersTree->findMax() << std::endl;
    std::cout << std::endl << "The minimum value of the tree is " << numbersTree->findMin() << std::endl;
    
    std::cout << std::endl << "Displaying tree in a sorted order" << std::endl;
    for (int n : numbersTree->inOrderTraversal()) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "Displaying tree in a sorted order after deleting 20" << std::endl;
    numbersTree->deleteValue(20);
    for (int n : numbersTree->inOrderTraversal()) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl << "Displaying tree in a sorted order after deleting 9" << std::endl;
    numbersTree->deleteValue(9);
    for (int n : numbersTree->inOrderTraversal()) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "Displaying tree in a sorted order after deleting 17" << std::endl;
    numbersTree->deleteValue(17);
    for (int n : numbersTree->inOrderTraversal()) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;

    // std::cout << std::endl << "The minimum value of the tree is " << numbersTree->findMax() << std::endl;

    delete numbersTree;
    return 0;
}

// function(s) definition
BinarySearchTreeNode* buildTree(std::vector<int>& values) {
    std::cout << "building tree" << std::endl;

    if (values.size() == 0) {
        return nullptr;
    }

    BinarySearchTreeNode* root = new BinarySearchTreeNode(values[0]);

    for (int i = 1; values.size() > i; i++) {
        root->addChild(values[i]);
    }

    std::cout << "finished building tree" << std::endl;
    return root;
}