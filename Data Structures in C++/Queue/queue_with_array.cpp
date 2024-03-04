#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow. Cannot enqueue element " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow. Cannot dequeue from an empty queue." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Dequeued " << arr[front] << " from the queue." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return some invalid value as queue is empty
        }
        return arr[front];
    }
};

int main() {
    Queue queue;

    char choice;
    int value;

    do {
        cout << "Choose operation:\n"
                "1. Enqueue\n"
                "2. Dequeue\n"
                "3. Peek\n"
                "4. Quit\n"
                "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case '2':
                queue.dequeue();
                break;
            case '3':
                cout << "Front element of the queue: " << queue.peek() << endl;
                break;
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != '4');

    return 0;
}
