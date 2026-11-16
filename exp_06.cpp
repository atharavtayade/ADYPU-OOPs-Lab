
#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Default Constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Function Overloading
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    void display(string message) {
        cout << message;
        display();
    }

    // Operator Overloading (+)
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Operator Overloading (-)
    Complex operator-(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
};

int main() {

    Complex c1(10, 5);
    Complex c2(4, 3);
    Complex result;

    cout << "===== COMPILE-TIME POLYMORPHISM =====" << endl;

    // Function Overloading
    cout << "\nFunction Overloading:" << endl;
    c1.display();
    c1.display("Complex Number: ");

    // Operator Overloading
    cout << "\nOperator Overloading:" << endl;

    result = c1 + c2;
    cout << "Addition: ";
    result.display();

    result = c1 - c2;
    cout << "Subtraction: ";
    result.display();

    return 0;
}
