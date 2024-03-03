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

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr; // Initialize top of the stack
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Return some invalid value as stack is empty
        }
        return top->data;
    }
};

int main() {
    Stack stack;

    char choice;
    int value;

    do {
        cout << "Choose operation:\n"
                "1. Push\n"
                "2. Pop\n"
                "3. Peek\n"
                "4. Quit\n"
                "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case '2':
                stack.pop();
                break;
            case '3':
                cout << "Top element of the stack: " << stack.peek() << endl;
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
