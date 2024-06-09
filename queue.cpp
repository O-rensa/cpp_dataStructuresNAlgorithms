#include <iostream>
#include <vector>
#include <string>

class StockPriceObj {
    private:
        std::string company;
        std::string timeStamp;
        float price;
        bool isBlank;
    public:
        // constructor(s)
        StockPriceObj():
            company{},
            timeStamp{},
            price{},
            isBlank{true}
        {}

        StockPriceObj(std::string name, std::string time, float _price):
            company{name},
            timeStamp{time},
            price{_price},
            isBlank{false}
        {}

        // method(s)
        void print();
};

template<typename T> 
class MyQueue {
    private:
        std::vector<T> collection;
    public:
        // constructor(s)
        explicit MyQueue<T>() = default;

        // method(s)
        void enqueue(T value);
        T dequeue();
        int size();
};

// class method(s) definition
// // myQueue
template<typename T>
void MyQueue<T>::enqueue(T value) {

    this->collection.push_back(value);
    std::cout << "successfully added to queue" << std::endl;
}

template<typename T>
T MyQueue<T>::dequeue() {

    if (this->collection.size() == 0) {
        std::cout << "the queue is empty" << std::endl;
        return T{};
    }

    T output = this->collection.front();
    this->collection.erase(this->collection.begin());

    return output;
}

template<typename T>
int MyQueue<T>::size() {
    int o =  this->collection.size();

    return o;
}

// // stockPriceObj
void StockPriceObj::print() {
    using s = StockPriceObj;

    if (s::isBlank){
        return;
    }

    std::cout << "{ company: " << s::company << ", timeStamp: "<< s::timeStamp << ", price " << s::price  << " }" << std::endl;
}

int main() {
    MyQueue<StockPriceObj> myVar = MyQueue<StockPriceObj>();

    std::cout << "inserting data into the queue" << std::endl;
    myVar.enqueue(StockPriceObj("Wall mart", "15 apr, 11.01 AM", 131.10));
    myVar.enqueue(StockPriceObj("Wall mart", "15 apr, 11.02 AM", 132.00));
    myVar.enqueue(StockPriceObj("Wall mart", "15 apr, 11.03 AM", 135.00));

    std::cout << std::endl << "popping out the data from queue" << std::endl;
    std::cout << std::endl << "popped out data: "; (myVar.dequeue()).print();
    std::cout << "the size of queue is " << myVar.size() << std::endl;
    std::cout << std::endl << "popped out data: "; (myVar.dequeue()).print();
    std::cout << "the size of queue is " << myVar.size() << std::endl;
    std::cout  << std::endl << "popped out data: "; (myVar.dequeue()).print();
    std::cout << "the size of queue is " << myVar.size() << std::endl;

    std::cout  << std::endl << "popped out data: "; (myVar.dequeue()).print();

    return 0;
}