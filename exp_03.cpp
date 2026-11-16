
#include <iostream>
using namespace std;

class Student {
private:
    int* marks;
    int size;

public:

    // 1. Default Constructor
    Student() {
        marks = nullptr;
        size = 0;
        cout << "Default Constructor Called" << endl;
    }

    // 2. Parameterized Constructor
    Student(int n, int value) {
        size = n;
        marks = new int[size];

        for (int i = 0; i < size; i++) {
            marks[i] = value;
        }

        cout << "Parameterized Constructor Called" << endl;
    }

    // 3. Copy Constructor (Deep Copy)
    Student(const Student& other) {
        size = other.size;

        if (size > 0) {
            marks = new int[size];

            for (int i = 0; i < size; i++) {
                marks[i] = other.marks[i];
            }
        }
        else {
            marks = nullptr;
        }

        cout << "Copy Constructor Called" << endl;
    }

    // 4. Move Constructor
    Student(Student&& other) noexcept {
        marks = other.marks;
        size = other.size;

        other.marks = nullptr;
        other.size = 0;

        cout << "Move Constructor Called" << endl;
    }

    // 5. Copy Assignment Operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            int* temp = nullptr;

            if (other.size > 0) {
                temp = new int[other.size];

                for (int i = 0; i < other.size; i++) {
                    temp[i] = other.marks[i];
                }
            }

            delete[] marks;

            marks = temp;
            size = other.size;
        }

        cout << "Copy Assignment Called" << endl;
        return *this;
    }

    // 6. Move Assignment Operator
    Student& operator=(Student&& other) noexcept {
        if (this != &other) {
            delete[] marks;

            marks = other.marks;
            size = other.size;

            other.marks = nullptr;
            other.size = 0;
        }

        cout << "Move Assignment Called" << endl;
        return *this;
    }

    // Display marks
    void display() const {
        cout << "Marks: ";

        for (int i = 0; i < size; i++) {
            cout << marks[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Student() {
        delete[] marks;
        cout << "Destructor Called" << endl;
    }
};

int main() {

    cout << "\n--- Default Constructor ---" << endl;
    Student s1;

    cout << "\n--- Parameterized Constructor ---" << endl;
    Student s2(3, 85);
    s2.display();

    cout << "\n--- Copy Constructor ---" << endl;
    Student s3(s2);
    s3.display();

    cout << "\n--- Move Constructor ---" << endl;
    Student s4(static_cast<Student&&>(s2));
    s4.display();

    cout << "\n--- Copy Assignment ---" << endl;
    s1 = s3;
    s1.display();

    cout << "\n--- Move Assignment ---" << endl;
    Student s5;
    s5 = static_cast<Student&&>(s4);
    s5.display();

    cout << "\n--- End of Program ---" << endl;

    return 0;
}
