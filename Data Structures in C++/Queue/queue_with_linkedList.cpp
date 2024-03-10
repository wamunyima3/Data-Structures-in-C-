#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow. Cannot dequeue from an empty queue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << "Dequeued " << temp->data << " from the queue." << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return some invalid value as queue is empty
        }
        return front->data;
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
