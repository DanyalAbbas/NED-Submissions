#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
public:
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int size() const = 0;
    virtual T Front() const = 0;
    virtual T Rear() const = 0;
    virtual void enqueue(const T& item) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;
};
template<typename T>
class DynamicQueue : public DynamicArray<T> {
private:
    T* arr;
    int capacity;
    int front, rear, count;
public:
    DynamicQueue(int size = 5) {
        capacity = size;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~DynamicQueue() { 
        delete[] arr; 
    }

    bool isEmpty() const override {return count == 0;}
    bool isFull() const override {return count == capacity;}
    int size() const override {return count;}
    T Front() const override {return arr[front];}
    T Rear() const override {return arr[rear];}


    void enqueue(const T& item) override {
        if (isFull()) resize();
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
    void dequeue() override {
        if (isEmpty()) {
            throw "Queue is Empty";
        }
        front = (front + 1) % capacity;
        count--;
    }
    void resize() override {
        T* newArr = new T[2 * capacity];
        int index = 0;
        for (int i = front; i != rear; i = (i + 1) % capacity)
            newArr[index++] = arr[i];
        newArr[index] = arr[rear];
        delete[] arr;
        arr = newArr;
        front = 0;
        rear = capacity - 1;
        capacity *= 2;
    }
};
int main() {
    DynamicQueue<int> q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); 
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;
    q.dequeue();
    cout << "New Front: " << q.Front() << endl;
    return 0;
}