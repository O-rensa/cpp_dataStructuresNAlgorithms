#include <iostream>
#include <vector>
#include <string>

class TreeNode {
    private:
        std::string data;
        std::vector<TreeNode*> children;
        TreeNode*  parent;
    public:
        // constructor(s);
        explicit TreeNode():
            data{},
            children(),
            parent{nullptr}
        {}

        explicit TreeNode(std::string data):
            data{data},
            children{},
            parent{nullptr}
        {}

        // destructor
        ~TreeNode() {
            std::cout << std::endl << "initializing TreeNode destructor for " << this->data << std::endl;

            for (TreeNode* c : children) {
                if (c != nullptr) {
                    std::cout << "deleting child: " << c->data << std::endl;
                    delete c;
                    c = nullptr;
                }
            }

            std::cout << "TreeNode destructor for " << this->data << " initialized successfully" << std::endl;
        }

        // method(s)
        int getLevel();
        void printTree();
        void addChild(TreeNode* child);
};

// class method definitions
// // TreeNode
int TreeNode::getLevel() {
    int level = 0;
    TreeNode* p = this->parent;
    while (p != nullptr) {
        level++;
        TreeNode * temp = p->parent;
        p = temp;
    }

    return level;
}

void TreeNode::printTree() {
    std::string spaces;
    for (int i = 1; i <= this->getLevel(); i++) {
        spaces += "   ";
    }

    std::string prefix;
    if (this->parent != nullptr) {
        prefix = spaces + "|__";
    } else {
        prefix = "";
    }

    std::string temp_data = this->data;
    std::cout << prefix << temp_data << std::endl;

    if (this->children.size() > 0) {
        for (TreeNode* c : this->children) {
            if (c != nullptr) {
                c->printTree();
            }
        }
    }
}

void TreeNode::addChild(TreeNode* child){
    std::cout << "parent " << this->data << " is adding child: " << child->data << std::endl; 
    child->parent = this;
    this->children.push_back(child);
}

// main function
int main() {
    // root tree
    std::cout << "creating root tree" << std::endl;
    TreeNode root("Electronics");
    
    // laptop tree
    std::cout << std::endl << "creating laptop tree" << std::endl;
    TreeNode* laptop = new TreeNode("Laptop");
    laptop->addChild(new TreeNode("Mac"));
    laptop->addChild(new TreeNode("Surface"));
    laptop->addChild(new TreeNode("Thinkpad"));

    // cellphone tree
    std::cout << std::endl << "creating cellphone tree" << std::endl;
    TreeNode* cellphone = new TreeNode("Cellphone");
    cellphone->addChild(new TreeNode("Iphone"));
    cellphone->addChild(new TreeNode("Google Pixel"));
    cellphone->addChild(new TreeNode("Vivo"));

    // TV tree
    std::cout << std::endl << "creating television tree" << std::endl;
    TreeNode* Television = new TreeNode("Television");
    Television->addChild(new TreeNode("Samsung"));
    Television->addChild(new TreeNode("LG"));
    Television->addChild(new TreeNode("Sony"));
    
    std::cout << std::endl << "adding laptop, cellphone and television as child of root" << std::endl;
    root.addChild(laptop);
    root.addChild(cellphone);
    root.addChild(Television);

    std::cout << std::endl << "printing root tree" << std::endl;
    root.printTree();

    std::cout << std::endl << "end of main function" << std::endl;
    return 0;
}