#include <iostream>
#include <vector>
#include <string>

template <typename T>
class MyStack {
    private:
        std::vector<T> stackObj; 
    public:
        // constructor(s)
        explicit MyStack<T>() = default;

        // method(s)
        void push(T value);
        T pop();
        T peek();
        void isEmpty();
};

// class method(s) definitions
template<typename T>
void MyStack<T>::push(T value) {
    this->stackObj.push_back(value);
    std::cout << "pushed " << value << " to the stack." << std::endl;
}

template<typename T>
T MyStack<T>::pop() {
    if (this->stackObj.size() > 0) {
        T output = this->stackObj.back();
        this->stackObj.pop_back();

        return output;
    }

    std::cout << "the stack is empty" << std::endl;
    return T{};
}

template<typename T>
T MyStack<T>::peek() {
    T output = this->stackObj.back();

    return output;
}

template<typename T>
void MyStack<T>::isEmpty() {
    if (this->stackObj.size() == 0) {
        std::cout << "true"<< std::endl;
        return;
    } 

    std::cout << "false"<< std::endl;
}

int main() {

    MyStack<int> myVar = MyStack<int>();

    std::cout << "inserting values to stack." << std::endl;
    myVar.push(10);
    myVar.push(20);
    myVar.push(30);
    myVar.push(40);
    myVar.push(50);

    std::cout << std::endl << "checking what is on the top of the stack." << std::endl;
    std::cout << "the item on the top of the stack is " << myVar.peek() << std::endl;

    std::cout << std::endl << "removing all of the values on the stack" << std::endl;
    std::cout << "removing the value " << myVar.pop() << std::endl;
    std::cout << "removing the value " << myVar.pop() << std::endl;
    std::cout << "removing the value " << myVar.pop() << std::endl;
    std::cout << "removing the value " << myVar.pop() << std::endl;
    
    std::cout << std::endl << "is the stack empty? ";
    myVar.isEmpty();

    std::cout << std::endl << "seems like we failed to remove all so we call the pop function again" << std::endl;
    std::cout << "removing the value " << myVar.pop() << std::endl;
    std::cout << std::endl << "is the stack empty? ";
    myVar.isEmpty();

    return 0;
}