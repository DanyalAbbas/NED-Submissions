#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Queue {
private:
    T* arr;
    int capacity;
    int front;
    int rear;
    int count;
public:
    Queue(int size = 5) {
        capacity = size;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~Queue() { delete[] arr; }
    bool isEmpty() const { 
        return count == 0; 
    }
    bool isFull() const { 
        return count == capacity; 
    }
    int size() const { 
        return count; 
    }
    void enqueue(const T& item) {
        if (isFull()) {
            cout << "Resizing queue..." << endl;
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
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "No jobs in the queue." << endl;
            return;
        }
        cout << "Printing job: " << arr[front] << endl;
        front = (front + 1) % capacity;
        count--;
    }
    void processJobs() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "All print jobs completed." << endl;
    }
};
int main() {
    Queue<string> printerQueue;
    printerQueue.enqueue("Report.pdf");
    printerQueue.enqueue("Invoice.docx");
    printerQueue.enqueue("Image.jpg");
    cout << "Starting print jobs..." << endl;
    printerQueue.processJobs();
    return 0;
}