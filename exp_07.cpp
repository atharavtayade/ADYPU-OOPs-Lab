
#include <iostream>
#include <string>
using namespace std;

// Generic Stack Class
template <class T>
class Stack {
private:
    T arr[100];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push element into stack
    void push(T value) {
        if (top == 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value;
    }

    // Pop element from stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << "Popped Element: " << arr[top--] << endl;
    }

    // Display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << "Stack Elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    // Integer Stack
    cout << "===== INTEGER STACK =====" << endl;

    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    s1.pop();
    s1.display();

    // Float Stack
    cout << "\n===== FLOAT STACK =====" << endl;

    Stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);
    s2.push(30.5);
    s2.display();
    s2.pop();
    s2.display();

    // String Stack
    cout << "\n===== STRING STACK =====" << endl;

    Stack<string> s3;
    s3.push("Hello");
    s3.push("C++");
    s3.push("Programming");
    s3.display();
    s3.pop();
    s3.display();

    return 0;
}
