
#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    // Pure virtual function
    virtual double area() = 0;

    virtual void display() {
        cout << "Calculating Shape Area" << endl;
    }

    // Virtual Destructor
    virtual ~Shape() {}
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14 * radius * radius;
    }

    void display() override {
        cout << "Circle Area: " << area() << endl;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() override {
        return length * breadth;
    }

    void display() override {
        cout << "Rectangle Area: " << area() << endl;
    }
};

// Derived Class: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() override {
        return 0.5 * base * height;
    }

    void display() override {
        cout << "Triangle Area: " << area() << endl;
    }
};

int main() {

    // Base class pointers
    Shape* s1;
    Shape* s2;
    Shape* s3;

    // Derived class objects
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(8, 5);

    cout << "===== RUNTIME POLYMORPHISM =====" << endl;

    s1 = &c;
    s1->display();

    s2 = &r;
    s2->display();

    s3 = &t;
    s3->display();

    return 0;
}
