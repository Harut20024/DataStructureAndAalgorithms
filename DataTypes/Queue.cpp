#include <iostream>
using namespace std;


class Queue
{
private:
    int arr[30];
    int front;
    int rear;
    int size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(short value) {
        if (size >= 30) {
            cout << "Queue overflow" << endl;
        } else {
            rear = (rear + 1) % 30; 
            arr[rear] = value;
            size++;
        }
    }

    short dequeue() {
        if (size <= 0) {
            cout << "Queue underflow" << endl;
            return -1; 
        } else {
            short value = arr[front];
            front = (front + 1) % 30; 
            size--;
            return value;
        }
    }

    short peek() const {
        if (size <= 0) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == 30;
    }
};

int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element is: " << queue.peek() << endl;

    cout << "Elements: " << endl;

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
