#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top of the stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot push element " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop from an empty stack." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Return some invalid value as stack is empty
        }
        return arr[top];
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
