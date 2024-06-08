#include <iostream>
#include <vector>
#include <string>

class stockPriceObj {
    private:
        std::string company;
        std::string timeStamp;
        float price;
        bool isBlank;
    public:
        // constructor(s)
        stockPriceObj():
            company{},
            timeStamp{},
            price{},
            isBlank{true}
        {}

        stockPriceObj(std::string name, std::string time, float _price):
            company{name},
            timeStamp{time},
            price{_price},
            isBlank{false}
        {}

        // method(s)
        void print();
};

template<typename T> 
class myQueue {
    private:
        std::vector<T> collection;
    public:
        // constructor(s)
        explicit myQueue<T>() = default;

        // method(s)
        void enqueue(T value);
        T dequeue();
        int size();
};

// class method(s) definition
// // myQueue
template<typename T>
void myQueue<T>::enqueue(T value) {
    using mq = myQueue<T>;

    mq::collection.push_back(value);
    std::cout << "successfully added to queue" << std::endl;
}

template<typename T>
T myQueue<T>::dequeue() {
    using mq = myQueue<T>;

    if (mq::collection.size() == 0) {
        std::cout << "the queue is empty" << std::endl;
        return T{};
    }

    T output = mq::collection.front();
    mq::collection.erase(mq::collection.begin());

    return output;
}

template<typename T>
int myQueue<T>::size() {
    int o =  myQueue<T>::collection.size();

    return o;
}

// // stockPriceObj
void stockPriceObj::print() {
    using s = stockPriceObj;

    if (s::isBlank){
        return;
    }

    std::cout << "{ company: " << s::company << ", timeStamp: "<< s::timeStamp << ", price " << s::price  << " }" << std::endl;
}

int main() {
    myQueue<stockPriceObj> myVar = myQueue<stockPriceObj>();

    std::cout << "inserting data into the queue" << std::endl;
    myVar.enqueue(stockPriceObj("Wall mart", "15 apr, 11.01 AM", 131.10));
    myVar.enqueue(stockPriceObj("Wall mart", "15 apr, 11.02 AM", 132.00));
    myVar.enqueue(stockPriceObj("Wall mart", "15 apr, 11.03 AM", 135.00));

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