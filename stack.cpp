#include <iostream>
#include <vector>
#include <string>

template <typename T>
class myStack {
    private:
        std::vector<T> stackObj; 
    public:
        // constructor(s)
        explicit myStack<T>() = default;

        // method(s)
        void push(T value);
        T pop();
        T peek();
        void isEmpty();
};

// class method(s) definitions
template<typename T>
void myStack<T>::push(T value) {
    using ms = myStack<T>;
    
    ms::stackObj.push_back(value);
    std::cout << "pushed " << value << " to the stack." << std::endl;
}

template<typename T>
T myStack<T>::pop() {
    using ms = myStack<T>;
    
    if (ms::stackObj.size() > 0) {
        T output = ms::stackObj.back();
        ms::stackObj.pop_back();

        return output;
    }

    std::cout << "the stack is empty" << std::endl;
    return T{};
}

template<typename T>
T myStack<T>::peek() {
    T output = myStack<T>::stackObj.back();

    return output;
}

template<typename T>
void myStack<T>::isEmpty() {
    if (myStack<T>::stackObj.size() == 0) {
        std::cout << "true"<< std::endl;
        return;
    } 

    std::cout << "false"<< std::endl;
}

int main() {

    myStack<int> myVar = myStack<int>();

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